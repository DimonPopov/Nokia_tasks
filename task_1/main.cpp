// author: Popov Dmitry
// date: 19.11.2021
// task 1: Даны N отсортированных списков. Написать функцию, которая объединяет списки в один отсортированный список уникальных значений.

#include <iostream>
#include "mergeList.hpp"



int main()
{
    std::list<int> l3 = {1, 2, 3, 4, 5};
    std::list<int> l2 = {3, 4, 5, 6, 7};
    std::list<int> l1 = {6, 7, 8, 9, 10};

    std::list<std::list<int>> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    std::list<int> result = mergeLists(lists);

    for(const auto& i : result)
    {
        std::cout << i << '\n';
    }

    return 0;
}