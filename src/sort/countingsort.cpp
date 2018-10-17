#include <iostream>
#include <list>
#include <map>

#include "ints_in.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "usage: " << argv[0] << " <datafile>\n";
        return 1;
    }

    std::list<int> ints;
    IntsIn::ReadFile(argv[1], ints);

    std::cerr << "count-sorting " << ints.size() << " ints\n";

    std::map<int, int> buckets;
    for (auto it = ints.begin(); it != ints.end(); it++)
    {
        int thisInt = *it;
        auto found = buckets.find(thisInt);

        if (found == buckets.end())
        {
            // not previously stored, so store count as 1
            buckets[thisInt] = 1;
            continue;
        }

        // previously stored, so increment count
        int existingCount = found->second;
        buckets[thisInt] = existingCount + 1;
    }

    return 0;
}
