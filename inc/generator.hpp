#pragma once

#include <map>

/* generator type */

enum class InternalGeneratorType : unsigned
{
    UNIQUE, LIMITED_RANGE, UNKNOWN = 99
};

class GeneratorType
{
    private:
        InternalGeneratorType _type;
        std::string _name;

        GeneratorType(InternalGeneratorType, const char *);
        static std::map<std::string, GeneratorType> by_name;
        static std::map<int, GeneratorType> by_int;

    public:
        static GeneratorType UNIQUE;
        static GeneratorType LIMITED_RANGE;
        static GeneratorType UNKNOWN;

        inline InternalGeneratorType Internal() { return _type; }
        inline std::string AsFlag() { return _name; }

        inline operator int() { return (int) _type; }

        static GeneratorType ByName(char *);
        static GeneratorType FromInt(int);
};

/* generator */

class Generator
{

    private:
        int *_arr  = nullptr;

        int _count;
        GeneratorType _type = GeneratorType::UNKNOWN;

        void DeleteArr();

        static void GenerateUnique(int *&, int);
        static void GenerateLimited(int *&, int);
        static bool ArrayContains(int *, int, int);
    
    public:
        Generator(int, GeneratorType);
        ~Generator();

        int * Generate();

        inline int Count() { return _count; }

};
