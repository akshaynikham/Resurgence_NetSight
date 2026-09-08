#pragma once
#include <cstdint>
#include "ether_type.hpp"
#include "parse_status.hpp"

struct EthernetInfo
{
    std::uint16_t rawEtherType;
    EtherType ethertype;
    ParseStatus parsestatus;
};

EthernetInfo parseEthernet(unsigned char* packet_start, unsigned char* packet_end );