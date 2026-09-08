#pragma once
#include "parse_status.hpp"
#include <iostream>


struct parseStatus
{
    ParseStatus status;
    const char* name;    
};

std::string parseEnumStatusToString(ParseStatus text);