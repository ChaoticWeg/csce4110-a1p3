#include <iostream>

#include "args.hpp"
#include "generator.hpp"

/* ArgumentKey */

ArgumentKey ArgumentKey::NUM_INTS = ArgumentKey(InternalArgumentKey::NUM_INTS, "--count");
ArgumentKey ArgumentKey::GENERATOR_TYPE = ArgumentKey(InternalArgumentKey::GENERATOR_TYPE, "--type");
ArgumentKey ArgumentKey::UNKNOWN = ArgumentKey(InternalArgumentKey::UNKNOWN, "");

std::map<std::string, ArgumentKey> ArgumentKey::by_key = {
    { NUM_INTS._flag, NUM_INTS },
    { GENERATOR_TYPE._flag, GENERATOR_TYPE }
};

ArgumentKey::ArgumentKey(InternalArgumentKey key, const char *flag)
{
    _internal = key;
    _flag = std::string(flag);
}

ArgumentKey ArgumentKey::FromFlag(char *flag)
{
    std::string tmp(flag);

    auto found = by_key.find(tmp);
    return found == by_key.end() ? ArgumentKey::UNKNOWN : (*found).second;
}

bool operator <  (const ArgumentKey &lhs, const ArgumentKey &rhs) { return lhs._internal < rhs._internal; }
bool operator >  (const ArgumentKey &lhs, const ArgumentKey &rhs) { return lhs._internal > rhs._internal; }
bool operator == (const ArgumentKey &lhs, const ArgumentKey &rhs) { return lhs._internal == rhs._internal; }

/* Arguments */

void Arguments::Parse(int argc, char **argv)
{
    if (argc % 2 == 0)
    {
        m_lErrors.push_back(std::string("invalid number of arguments: ") + std::to_string(argc));
        return;
    }

    for (int i = 1; i < argc; i++)
    {
        ArgumentKey key = ArgumentKey::FromFlag(argv[i]);
        switch (key.Internal())
        {
            case InternalArgumentKey::NUM_INTS:
                i++;
                m_mValues.insert(std::pair<ArgumentKey, int>(key, atoi(argv[i])));
                continue;
            
            case InternalArgumentKey::GENERATOR_TYPE:
                i++;
                m_mValues.insert(std::pair<ArgumentKey, int>(key, GeneratorType::ByName(argv[i])));
                continue;
                
            default:
                m_lErrors.push_back(std::string("invalid argument: ") + std::string(argv[i]));
                continue;
        }
    }
}

int Arguments::GetValue(ArgumentKey key)
{
    auto found = m_mValues.find(key);
    return found == m_mValues.end() ? -1 : (*found).second;
}

std::list<std::string> Arguments::GetErrors()
{
    return m_lErrors;
}

bool Arguments::HasErrors()
{
    return m_lErrors.size() > 0;
}
