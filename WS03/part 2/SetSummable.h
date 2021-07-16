// Name: Muhammad Ibrahi Muhammad Yusoof
// Email: imuhammad-yusoof@myseneca.ca
// SEQ: 164366189
// Date: June 13 2021

#ifndef SETSUMMABLE_H_SDDS
#define SETSUMMABLE_H_SDDS

#include <iostream>
#include "Set.h"
#include <typeinfo>

namespace sdds
{
    // Template requires a type name and a unsigned integer for size of array, since an array with a negative value wouldn't be necceary, we use an unsigned int
    template <unsigned int N, typename T>
    class SetSummable : public Set<N, T>
    {
    public:
        // Adds the values together from the array
        T accumulate(const std::string &filter) const
        {
            // Uses a filter as a key to pass through the compatability when adding values
            T temp(filter);
            temp.reset();
            // Itterate through the array in set
            for (size_t i = 0; i < this->size(); i++)
            {
                // add values of index into current item value
                temp += this->get(i);
            }
            // After having changed the static items, reset the values.
            temp.reset();
            // Return temp item
            return temp;
        }
    };

} // namespace sdds

#endif
