#include "transport/server.h"

#include "login/services/account.h"

#include "datasources/impl/pqxx/account.h"
#include "datasources/impl/pqxx/character.h"
#include "game/server.h"
#include "login/server.h"

#include "experimental/login/account/accountcontroller.h"
#include "experimental/transport/server.h"

using namespace openao::experimental;
using namespace openao::experimental::serialization;
using namespace openao::experimental::login::account;
using namespace openao::experimental::reactor;

int main(int argc, char *argv[]) {
  io_context context;

  DependencyInjector dependency_injector;
  dependency_injector.create<BranchesService>();
  dependency_injector.create<AccountService>();

  CustomReactor reactor(dependency_injector);
  reactor.insert(AccountController::authenticate);

  Serializer serializer;
  serializer.insert<CharacterListEvent>(0);

  Deserializer deserializer;
  deserializer.insert<AuthenticationCommand>(2);

  transport::Server server(context, 30000, reactor, serializer, deserializer);
  server.start();

  context.run();
}