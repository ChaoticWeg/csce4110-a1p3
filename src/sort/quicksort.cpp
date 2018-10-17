#include <iostream>
#include <list>

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

    std::cerr << "quicksorting " << ints.size() << " ints\n";

    return 0;
}
