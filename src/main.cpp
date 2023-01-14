#include "transport/server.h"

#include "login/services/account.h"

#include "datasources/impl/pqxx/account.h"
#include "datasources/impl/pqxx/character.h"
#include "datasources/impl/pqxx/inventory.h"
#include "login/server.h"

int main(int argc, char *argv[]) {
  pqxx::connection conn("dbname=openao user=admin password=admin "
                        "hostaddr=127.0.0.1 port=5432");
  Datasources::PQXX::Account account(conn);
  Datasources::PQXX::Character character(conn);

  Login::Services::Account account_service(account, character);

  Login::Handlers handlers;
  handlers.add<Login::Messages::Requests::Auth>(
          [&account_service](auto &&c, auto &&m) {
            account_service.authenticate(c, m);
          });
  handlers.add<Login::Messages::Requests::SetPin>(
          [&account_service](auto &&c, auto &&m) {
            account_service.set_pin(c, m);
          });
  handlers.add<Login::Messages::Requests::Disconnect>(
          [&account_service](auto &&c, auto &&m) {
            account_service.disconnect(c, m);
          });

  Login::Server server{30000, handlers};
  std::thread t1([&server]() { server.start(); });

  t1.join();
}