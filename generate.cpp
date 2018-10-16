#include <iostream>

#include "args.hpp"
#include "generator.hpp"

int main(int argc, char **argv)
{
    Arguments args;
    args.Parse(argc, argv);

    if (args.HasErrors())
    {
        std::list<std::string> errors = args.GetErrors();
        for (auto e = errors.begin(); e != errors.end(); e++)
            std::cerr << *e << std::endl;
        
        return 1;
    }

    int count = args.GetValue(ArgumentKey::NUM_INTS);
    int gentype_i = args.GetValue(ArgumentKey::GENERATOR_TYPE);

    GeneratorType gentype = GeneratorType::FromInt(gentype_i);

    std::cerr << count << " ints of type: " << gentype.AsFlag() << std::endl;

    Generator *gen = new Generator(count, gentype);

    int *ints = gen->Generate();
    for (int i = 0; i < gen->Count(); i++)
    {
        std::cout << ints[i] << ";";
    }

    delete gen;

    return 0;
}
