// Name: Muhammad Ibrahi Muhammad Yusoof
// Email: imuhammad-yusoof@myseneca.ca
// SEQ: 164366189
// Date: June 03 2021

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
        int numOfwords;

    public:
        StringSet();
        StringSet(const char *nameOfFile);
        StringSet(const StringSet &cpy);
        StringSet &operator=(const StringSet &);
        StringSet(StringSet &&movd);
        StringSet &operator=(StringSet &&movd);
        ~StringSet();
        size_t size() const;
        std::string operator[](size_t) const;
    };

} //namespace sdds
#endif