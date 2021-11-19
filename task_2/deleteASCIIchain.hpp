#pragma once

#include <string>


void deleteChain(char* str) = delete;

void deleteChain(std::string& str)
{
    if(str.length() <= 1)
    {
        return;
    }

    size_t index1 = 0;      // chain start index
    size_t index2 = 1;      // chain end index
    bool isChain = false;   // if we have ASCIIchain

    auto deleteSubString = [&str, &isChain](size_t& index1, size_t& index2)
    { 
        isChain = false;
        str.erase(index1, index2 - index1);
        if(index1)
        {
            index1 = index1 - 1;
        }
        index2 = index1 + 1;
    };

    while(index2 < str.length())
    {
        if(isChain && (int)str[index2] - 1 != (int)str[index2 - 1])
        {
            deleteSubString(index1, index2);
            continue;
        }
        if((int)str[index2] - 1 == (int)str[index2 - 1])
        {
            isChain = true;
            ++index2;
            continue;
        }
        ++index2;
        ++index1;
    }

    if(isChain)
    {
        deleteSubString(index1, index2);
    }
}