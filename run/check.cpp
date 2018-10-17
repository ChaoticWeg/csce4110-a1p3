#include <iostream>
#include <fstream>
#include <list>

#include "ints_in.hpp"
#include "bst.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "usage: " << argv[0] << " <file>\n";
        return 1;
    }
    
    BinaryTree tree;
    std::list<int> duplicates;

    std::list<int> ints;
    IntsIn::ReadFile(argv[1], ints);

    for (auto it = ints.begin(); it != ints.end(); it++)
    {
        int thisInt = *it;

        if (!tree.Insert(thisInt))
            duplicates.push_back(thisInt);
    }

    std::cerr << argv[1] << ": " << tree.GetSize() << " known ints; " << duplicates.size() << " duplicates\n";

    return duplicates.size();
}
