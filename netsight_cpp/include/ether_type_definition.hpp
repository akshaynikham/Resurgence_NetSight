#pragma once
#include <cstdint>
#include <iostream>
#include <ether_type.hpp>

struct EtherTypeDefinition{
    std::uint16_t rawvalue;
    EtherType type;
    const char* name;
};

EtherType rawBytesToEtherType(std::uint16_t rawEtherType);
std::string etherTypeToDisplay(EtherType ethertype);