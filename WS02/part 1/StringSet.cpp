#include "StringSet.h"

using namespace std;

namespace sdds
{
    StringSet::StringSet()
    {
        words = nullptr;
        numOfwords = 0;
    }
    StringSet::StringSet(char *nameOfFile)
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

    StringSet::StringSet(StringSet &cpy)
    {
        words = nullptr;
        numOfwords = 0;
        *this = cpy;
    }
    StringSet &StringSet::operator=(StringSet &cpy)
    {
        delete[] words;
        numOfwords = 0;
        if (this != &cpy)
        {

            words = new string[cpy.size()];
            numOfwords = cpy.numOfwords;
            for (int i = 0; i < numOfwords; i++)
            {
                words[i] = cpy.words[i];
            }
        }
        return *this;
    }

    StringSet::~StringSet()
    {
        delete[] words;
    }
    size_t StringSet::size()
    {
        return numOfwords;
    }
    std::string StringSet::operator[](size_t index) const
    {
        if (index > numOfwords || !words)
            return "";
        else
            return words[index];
    }
} // namespace SDDS
