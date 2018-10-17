#pragma once

#include <iostream>
#include <list>
#include <map>

namespace IntsOut
{

    /* Print an occurrence map to STDOUT */
    void PrintMap(const std::map<int, int> &ints)
    {
        for (auto it = ints.begin(); it != ints.end(); it++)
        {
            int count = it->second;
            for (int i = 0; i < count; i++)
                std::cout << it->first << ";";
        }
    }

    /* Print a list to STDOUT */
    void PrintList(const std::list<int> &ints)
    {
        for (auto it = ints.begin(); it != ints.end(); it++)
        {
            std::cout << *it << ";";
        }
    }
}