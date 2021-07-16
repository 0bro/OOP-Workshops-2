// Name: Muhammad Ibrahi Muhammad Yusoof
// Email: imuhammad-yusoof@myseneca.ca
// SEQ: 164366189
// Date: June 03 2021

#include "StringSet.h"

using namespace std;

namespace sdds
{
    StringSet::StringSet()
    {
        words = nullptr;
        numOfwords = 0;
    }
    StringSet::StringSet(const char *nameOfFile)
    {
        ifstream file(nameOfFile);
        words = nullptr;
        numOfwords = 0;

        if (file.is_open())
        {

            while (file)
            {
                string temp;
                getline(file, temp, ' ');
                if (file)
                    numOfwords++;
            };
            if (numOfwords > 0)
            {
                words = new string[numOfwords];
            }
            file.clear();
            file.seekg(0);

            for (int i = 0; i < numOfwords; i++)
            {
                getline(file, words[i], ' ');
            }
        };
    }

    StringSet::StringSet(const StringSet &cpy)
    {
        words = nullptr;
        numOfwords = 0;
        *this = cpy;
    }
    StringSet &StringSet::operator=(const StringSet &cpy)
    {
        if (this != &cpy)
        {

            delete[] words;
            words = new string[cpy.size()];
            numOfwords = cpy.numOfwords;
            for (int i = 0; i < numOfwords; i++)
            {
                words[i] = cpy.words[i];
            }
        }
        return *this;
    }

    StringSet::StringSet(StringSet &&movd)
    {
        words = nullptr;
        numOfwords = 0;
        *this = std::move(movd);
    }
    StringSet &StringSet::operator=(StringSet &&movd)
    {
        if (this != &movd)
        {
            delete[] words;
            numOfwords = movd.numOfwords;
            words = movd.words;
            movd.words = nullptr;
            movd.numOfwords = 0;
        }
        return *this;
    }

    StringSet::~StringSet()
    {
        delete[] words;
    }
    size_t StringSet::size() const
    {
        return numOfwords;
    }
    std::string StringSet::operator[](size_t index) const
    {
        if (index > (size_t)numOfwords || !words)
            return "";
        else
            return words[index];
    }
} // namespace SDDS
