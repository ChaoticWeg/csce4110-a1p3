#include <cstdlib> // rand
#include <ctime>   // seed with ctime

#include "generator.hpp"


// define static generator types

GeneratorType GeneratorType::UNIQUE = GeneratorType(InternalGeneratorType::UNIQUE, "unique");
GeneratorType GeneratorType::LIMITED_RANGE = GeneratorType(InternalGeneratorType::LIMITED_RANGE, "limited");
GeneratorType GeneratorType::UNKNOWN = GeneratorType(InternalGeneratorType::UNKNOWN, "");


// define GeneratorType lookup table by name

std::map<std::string, GeneratorType> GeneratorType::by_name = {
    { GeneratorType::UNIQUE._name, GeneratorType::UNIQUE },
    { GeneratorType::LIMITED_RANGE._name, GeneratorType::LIMITED_RANGE }
};


// define GeneratorType lookup table by ID

std::map<int, GeneratorType> GeneratorType::by_int = {
    { (int) InternalGeneratorType::UNIQUE, GeneratorType::UNIQUE },
    { (int) InternalGeneratorType::LIMITED_RANGE, GeneratorType::LIMITED_RANGE }
};


/*  GeneratorType constructor */
GeneratorType::GeneratorType(InternalGeneratorType type, const char *name)
{
    _type = type;
    _name = std::string(name);
}


/*  Look up a GeneratorType by name.
 *  
 *  Params:
 *  - char *name - The name of the GeneratorType (as would be passed on command-line)
 *
 *  Returns the desired GeneratorType if exists; else returns GeneratorType::UNKNOWN.
 */
GeneratorType GeneratorType::ByName(char *name)
{
    auto found = by_name.find(std::string(name));
    return found == by_name.end() ? GeneratorType::UNKNOWN : found->second;
}


/*  Look up a GeneratorType by internal ID.
 *
 *  Params:
 *  - int raw - The internal ID of the GeneratorType (as would be stored in Arguments)
 *
 *  Returns the desired GeneratorType if exists; else returns GeneratorType::UNKNOWN.
 */
GeneratorType GeneratorType::FromInt(int raw)
{
    auto found = by_int.find(raw);
    return found == by_int.end() ? GeneratorType::UNKNOWN : found->second;
}


/*  Generator constructor */
Generator::Generator(int count, GeneratorType type)
{
    _count = count;
    _type = type;
}


/*  Generator destructor */
Generator::~Generator()
{
    DeleteArr();
}


/*  Delete the internal array and set it to nullptr. */
void Generator::DeleteArr()
{
    // delete and set _arr to nullptr if it exists
    if (_arr != nullptr)
    {
        delete [] _arr;
        _arr = nullptr;
    }
    
}


/*  Generate the desired set of integers based on the type and count given
 *  to the constructor. Note: directly modifies the internal array, to save
 *  memory.
 *
 *  Returns a pointer to the internal array.
 */
int * Generator::Generate()
{
    // cleanup first
    DeleteArr();

    switch (_type)
    {
        case 0:
            GenerateUnique(_arr, _count);
            break;
        case 1:
            GenerateLimited(_arr, _count);
            break;
        default:
            break;
    }

    return _arr;
}


/*  Generate a set of unique integers. Integers may not repeat.
 *
 *  Params:
 *  - int *&arr - Pointer to resultant array (out)
 *  - int count - Array size
 */
void Generator::GenerateUnique(int *&arr, int count)
{
    srand(time(NULL)); // seed RNG
    arr = new int[count];

    for (int i = 0; i < count; i++)
    {
        int random = rand();

        while (ArrayContains(arr, count, random))
        {
            random++;
        }

        arr[i] = random;
    }
}


/*  Generate a set of integers with a limited range (1% of array size).
 *  Integers may repeat.
 *  
 *  Params:
 *  - int *&arr - Pointer to resultant array (out)
 *  - int count - Array size
 */
void Generator::GenerateLimited(int *&arr, int count)
{
    srand(time(NULL)); // seed RNG
    arr = new int[count];

    int range = count / 100;
    for (int i = 0; i < count; i++)
    {
        arr[i] = rand() % range;
    }
}


/*  Checks to see whether the array already contains the given integer.
 *  Only useful when generating a set of unique integers.
 *
 *  Params:
 *  - int *arr   - Array to search through
 *  - int count  - Array size
 *  - int target - Integer to search the array for
 *
 *  Returns true if the array contains the integer; else returns false.
 */
bool Generator::ArrayContains(int *arr, int count, int target)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == target)
            return true;
    }

    return false;
}
