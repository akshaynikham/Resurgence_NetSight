#include "packet.h"
#include <utility>




Packet::Packet(std::vector<unsigned char>&& rawBytes)
:rawBytes(std::move(rawBytes)){};


