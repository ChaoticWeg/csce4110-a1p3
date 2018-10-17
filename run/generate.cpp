#include <iostream>

#include "args.hpp"
#include "generator.hpp"

int main(int argc, char **argv)
{
    // parse command-line arguments
    Arguments args;
    args.Parse(argc, argv);

    // bail out if there are any errors
    if (args.HasErrors())
    {
        std::list<std::string> errors = args.GetErrors();
        for (auto e = errors.begin(); e != errors.end(); e++)
            std::cerr << *e << std::endl;
        
        return 1;
    }

    // retrieve int count and type from Arguments
    int count = args.GetValue(ArgumentKey::NUM_INTS);
    int gentype_i = args.GetValue(ArgumentKey::GENERATOR_TYPE);

    // lookup generator type by ID (stored in Arguments)
    GeneratorType gentype = GeneratorType::FromInt(gentype_i);

    // quick little heads-up to STDERR (QoL)
    std::cerr << count << " ints of type: " << gentype.AsFlag() << std::endl;

    // generate integer set
    Generator *gen = new Generator(count, gentype);
    int *ints = gen->Generate();

    // print to STDOUT (should be redirected to a file! or piped to something else.)
    for (int i = 0; i < gen->Count(); i++)
    {
        std::cout << ints[i] << ";";
    }

    // cleanup and exit
    delete gen;
    return 0;
}
