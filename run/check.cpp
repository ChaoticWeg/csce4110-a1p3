#include <iostream>
#include <cctype>
#include <string>
#include <list>

#include "ints_in.hpp"
#include "bst.hpp"

bool CheckUnique(const std::list<int> &ints);
bool CheckSorted(const std::list<int> &ints);

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "usage: " << argv[0] << " <unique|sorted> <file>\n";
        return 1;
    }

    std::cerr << argv[2] << ": " << argv[1] << "?  ";

    std::list<int> ints;
    IntsIn::ReadFile(argv[2], ints);

    bool ok = false;

    std::string arg(argv[1]);

    if (arg.compare("unique") == 0)
    {
        ok = CheckUnique(ints);
    }

    else if (arg.compare("sorted") == 0)
    {
        ok = CheckSorted(ints);
    }

    else
    {
        std::cerr << "unknown check type '" << argv[1] << "'\n";
        return 99;
    }

    std::cerr << (ok ? "YES" : "NO") << "\n";
    return ok ? 0 : 2;
}


bool CheckUnique(const std::list<int> &ints)
{
    BinaryTree tree;
    std::list<int> duplicates;

    for (auto it = ints.begin(); it != ints.end(); it++)
    {
        int thisInt = *it;

        if (!tree.Insert(thisInt))
            duplicates.push_back(thisInt);
    }

    return duplicates.size() == 0;
}

bool CheckSorted(const std::list<int> &ints)
{
    int lastInt = -1,
        thisInt;
    
    for (auto it = ints.begin(); it != ints.end(); it++)
    {
        thisInt = *it;

        if (thisInt < lastInt)
            return false;
        
        lastInt = thisInt;
    }

    return true;
}
