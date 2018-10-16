/*
    File:   inc/args.hpp
    Author: Shawn Lutch - sml0262

    About:  Defines the enum-like ArgumentKey class and the command-line arg-parsing Arguments class
*/

#pragma once

#include <map>
#include <list>
#include <string>


/*  Defines an enum class to be used as the key that each ArgumentKey is given */
enum class InternalArgumentKey : unsigned
{
    NUM_INTS, GENERATOR_TYPE, UNKNOWN = 99
};


/* Defines an argument key, which has its own identifier string */
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


/*  Defines a set of ArgumentKeys and their respective values.
 *  ArgumentKeys are passed on the command line by their identifying strings, e.g.
 *
 *  ./generate.out --type unique --count 100000
 *
 *  wherein "--type" and "--count" are ArgumentKeys and "unique" and "100000" are their
 *  respective values.
 */
class Arguments
{

private:
    std::map<ArgumentKey, int> m_mValues; // key/value map (or dict, for you Python lovers)
    std::list<std::string> m_lErrors;     // list of errors, to be populated while parsing

public:
    void Parse(int argc, char **argv);    // parse the given set of command-line arguments
    int GetValue(ArgumentKey);            // get the value passed for the given ArgumentKey

    inline bool HasErrors() { return m_lErrors.size() > 0; }        // any errors?
    inline std::list<std::string> GetErrors() { return m_lErrors; } // what errors?
    
};
