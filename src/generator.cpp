#include <cstdlib> // rand
#include <ctime>   // seed with ctime

#include "generator.hpp"

/* generator type */

GeneratorType GeneratorType::UNIQUE = GeneratorType(InternalGeneratorType::UNIQUE, "unique");
GeneratorType GeneratorType::LIMITED_RANGE = GeneratorType(InternalGeneratorType::LIMITED_RANGE, "limited");
GeneratorType GeneratorType::UNKNOWN = GeneratorType(InternalGeneratorType::UNKNOWN, "");

std::map<std::string, GeneratorType> GeneratorType::by_name = {
    { GeneratorType::UNIQUE._name, GeneratorType::UNIQUE },
    { GeneratorType::LIMITED_RANGE._name, GeneratorType::LIMITED_RANGE }
};

std::map<int, GeneratorType> GeneratorType::by_int = {
    { (int) InternalGeneratorType::UNIQUE, GeneratorType::UNIQUE },
    { (int) InternalGeneratorType::LIMITED_RANGE, GeneratorType::LIMITED_RANGE }
};

GeneratorType::GeneratorType(InternalGeneratorType type, const char *name)
{
    _type = type;
    _name = std::string(name);
}

GeneratorType GeneratorType::ByName(char *name)
{
    auto found = by_name.find(std::string(name));
    return found == by_name.end() ? GeneratorType::UNKNOWN : found->second;
}

GeneratorType GeneratorType::FromInt(int raw)
{
    auto found = by_int.find(raw);
    return found == by_int.end() ? GeneratorType::UNKNOWN : found->second;
}

/* generator */

Generator::Generator(int count, GeneratorType type)
{
    _count = count;
    _type = type;
}

Generator::~Generator()
{
    DeleteArr();
}

void Generator::DeleteArr()
{
    // delete and set _arr to nullptr if it exists
    if (_arr != nullptr)
    {
        delete [] _arr;
        _arr = nullptr;
    }
    
}

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

void Generator::GenerateLimited(int *&arr, int count)
{
    arr = new int[count];
}

bool Generator::ArrayContains(int *arr, int count, int target)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == target)
            return true;
    }

    return false;
}
