#include <iostream>
#include <list>

#include "ints_in.hpp"
#include "ints_out.hpp"

void QuickSort(std::list<int> ints);      // quicksort
void InsertionSort(std::list<int> ints);  // insertion sort

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


    // sort

    std::cerr << "quicksorting " << ints.size() << " ints\n";
    QuickSort(ints);


    // print to STDOUT
    IntsOut::PrintList(ints);

    return 0;
}

void QuickSort(std::list<int> ints)
{
    // TODO QuickSort
}

void InsertionSort(std::list<int> ints)
{
    // TODO insertion sort
}