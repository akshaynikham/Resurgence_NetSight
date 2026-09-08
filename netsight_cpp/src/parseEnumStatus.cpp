#include "parseEnumStatus.hpp"
#include<iostream>

parseStatus ParseStatusStruct[]
{
    {ParseStatus::Parsed, "Parsed"},
    {ParseStatus::Truncated, "Truncated"},
    {ParseStatus::Unknown, "Unknown"}
};

std::string parseEnumStatusToString(ParseStatus text){
    size_t size = sizeof(ParseStatusStruct)/sizeof(ParseStatusStruct[0]);
    for(int i=0; i<size;i++){
        if(ParseStatusStruct->status == text){
            return ParseStatusStruct->name;
        }
    }
    return "Unknown";
}