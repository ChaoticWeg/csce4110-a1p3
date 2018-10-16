#pragma once

#include <map>
#include <list>
#include <string>

/* argument detection */

enum class InternalArgumentKey : unsigned
{
    NUM_INTS, GENERATOR_TYPE, UNKNOWN = 99
};

class ArgumentKey
{
    private:
        InternalArgumentKey _internal;
        std::string _flag;
        ArgumentKey(InternalArgumentKey, const char *);

        static std::map<std::string, ArgumentKey> by_key;
        
    public:
        static ArgumentKey NUM_INTS;
        static ArgumentKey GENERATOR_TYPE;
        static ArgumentKey UNKNOWN;

        inline std::string AsFlag() { return _flag; }
        inline InternalArgumentKey Internal() { return _internal; }

        static ArgumentKey FromFlag(char *);

        friend bool operator<(const ArgumentKey &, const ArgumentKey &);
        friend bool operator>(const ArgumentKey &, const ArgumentKey &);
        friend bool operator==(const ArgumentKey &, const ArgumentKey &);
        
        inline operator int() { return (int) _internal; }
};

/* argument list */

class Arguments
{

private:
    std::map<ArgumentKey, int> m_mValues;
    std::list<std::string> m_lErrors;

public:
    void Parse(int argc, char **argv);
    int GetValue(ArgumentKey);

    std::list<std::string> GetErrors();
    bool HasErrors();
};
