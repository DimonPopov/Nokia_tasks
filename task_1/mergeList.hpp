#pragma once

#include <list>



template <typename T>
struct mCmp{
    bool operator()(const T& arg1, const T& arg2)
    {
        return arg1 < arg2;
    }
};

template <typename T>
struct uCmp{
    bool operator()(const T& arg1, const T& arg2)
    {
        return arg1 == arg2;
    }
};



template <typename T, typename mergComparator = mCmp<T>, typename uniqComparator = uCmp<T>>
std::list<T> mergeLists(std::list<std::list<T>>& lists, mergComparator mC = mCmp<T>(), uniqComparator uC = uCmp<T>())
{
    std::list<T> dst;
    for(auto& list : lists)
    {
        dst.merge(list, mC);
    }
    dst.unique(uC);

    return dst;
}