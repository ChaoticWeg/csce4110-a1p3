#include <iostream>
#include <list>
#include <map>

#include "ints_in.hpp"
#include "ints_out.hpp"

void CountingSort(const std::list<int> &ints, std::map<int, int> &buckets);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "usage: " << argv[0] << " <datafile>\n";
        return 1;
    }


    // read ints from file
    std::list<int> ints;
    IntsIn::ReadFile(argv[1], ints);

    std::cerr << "count-sorting " << ints.size() << " ints\n";


    // sort
    std::map<int, int> buckets;
    CountingSort(ints, buckets);
    

    // print to STDOUT
    IntsOut::PrintMap(buckets);

    return 0;
}

void CountingSort(const std::list<int> &ints, std::map<int, int> &buckets)
{
    buckets.clear();

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
}