#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H

#include <iostream>
#include <fstream>

namespace sdds
{
    class StringSet
    {
    private:
        std::string *words;
        unsigned int numOfwords;

    public:
        StringSet();
        StringSet(char *nameOfFile);
        StringSet(StringSet &cpy);
        StringSet &operator=(StringSet &);
        ~StringSet();
        size_t size();
        std::string operator[](size_t) const;
    };

} //namespace sdds
#endif