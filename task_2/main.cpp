// author: Popov Dmitry
// date: 19.11.2021
// task 2: Дана конечная последовательность ascii-символов. Требуется удалить из неё цепочки символов
//         такие, что коды символов в них идут по возрастанию строго с шагом 1. В результате должна
//         получится последовательность символов, в которой вообще нет таких цепочек (даже после
//         удаления уже найденных).

#include <iostream>
#include "deleteASCIIchain.hpp"


int main()
{
    std::string mainStr = {"ABC"};

    deleteChain(mainStr);

    std::cout << mainStr << std::endl;

    return 0;
}