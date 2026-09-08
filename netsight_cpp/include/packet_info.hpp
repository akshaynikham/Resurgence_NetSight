#pragma once
#include "protocol.hpp"

struct PacketInfo
    {
        std::uint16_t packetLength;
        std::uint16_t EtherType;
        std::uint8_t ip_version;
        Protocol protocol;
    };

