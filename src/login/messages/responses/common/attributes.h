
#ifndef OPENAO_MESSAGES_RESPONSES_COMMON_ATTRIBUTES_H
#define OPENAO_MESSAGES_RESPONSES_COMMON_ATTRIBUTES_H

#include "model/character.h"
#include "utils/binarybuffer.h"

namespace Login::Messages::Responses {
void serialize(BinaryBuffer &buffer, Model::Attributes &a) {
  buffer.write(a.gender);
  buffer.write(a.hair_style);
  buffer.write(a.height);
  buffer.write(a.hair_color);
  buffer.write(a.skin_color);
}
}// namespace Login::Messages::Responses

#endif// OPENAO_MESSAGES_RESPONSES_COMMON_ATTRIBUTES_H
