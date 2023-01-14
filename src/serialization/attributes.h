
#ifndef OPENAO_SERIALIZATION_ATTRIBUTES_H
#define OPENAO_SERIALIZATION_ATTRIBUTES_H

#include "model/character.h"
#include "utils/binarybuffer.h"

namespace Serialization {
template <typename Archive>
void serialize(Archive &archive, Model::Attributes &a) {
  archive.write(a.gender);
  archive.write(a.hair_style);
  archive.write(a.height);
  archive.write(a.hair_color);
  archive.write(a.skin_color);
}

template <typename Archive>
void deserialize(Archive &archive, Model::Attributes &a) {
  archive.read(a.gender);
  archive.read(a.hair_style);
  archive.read(a.height);
  archive.read(a.hair_color);
  archive.read(a.skin_color);
}
}// namespace Serialization

#endif// OPENAO_SERIALIZATION_ATTRIBUTES_H
