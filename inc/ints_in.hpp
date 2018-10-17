#include <fstream>
#include <list>

namespace IntsIn
{
    void ReadFile(char *filename, std::list<int> &ints)
    {
        ints.clear();

        std::fstream infile(filename, std::ios::in);

        std::string line;
        while (std::getline(infile, line, ';'))
        {
            ints.push_back(std::stoi(line));
        }
    }
}
