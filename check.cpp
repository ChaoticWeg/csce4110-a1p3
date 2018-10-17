#include <iostream>
#include <fstream>
#include <list>

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

    std::fstream file(argv[1], std::ios::in);

    std::string line;
    while (std::getline(file, line, ';'))
    {
        int thisInt = std::stoi(line);

        if (!tree.Insert(thisInt))
            duplicates.push_back(thisInt);
    }

    std::cerr << argv[1] << ": " << tree.GetSize() << " known ints; " << duplicates.size() << " duplicates\n";

    return duplicates.size();
}
