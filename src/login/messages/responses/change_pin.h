
#ifndef OPENAO_LOGIN_MESSAGES_RESPONSES_CHANGE_PIN_H
#define OPENAO_LOGIN_MESSAGES_RESPONSES_CHANGE_PIN_H

#include "utils/string.h"

namespace Login::Messages::Responses {

struct ChangePin {
  static const uint16_t type = 7;

  bool status;

  void serialize(BinaryBuffer& archive) {
    archive.write(status);
  }
};

}

#endif// OPENAO_LOGIN_MESSAGES_RESPONSES_CHANGE_PIN_H
