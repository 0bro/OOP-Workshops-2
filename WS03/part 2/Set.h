// Name: Muhammad Ibrahi Muhammad Yusoof
// Email: imuhammad-yusoof@myseneca.ca
// SEQ: 164366189
// Date: June 13 2021

#ifndef SET_H_SDDS
#define SET_H_SDDS

#include <iostream>

namespace sdds
{
    // Template requires a type name and a unsigned integer for size of array, since an array with a negative value wouldn't be necceary, we use an unsigned int
    template <unsigned int N, typename T>
    class Set
    {
        // an array of the type that is passed through the template with a size that's passed through the template
        T m_arr[N];
        // holds the total size as a variable
        unsigned int m_size = N;
        // counts ammount of index's filled
        unsigned int m_count = 0;
        // An empty version of the object for when asked for
        T dummy;

    public:
        // returns the amount of items are within the Array
        size_t size() const { return m_count; };
        // Returns data from a index
        const T &get(size_t idx) const { return idx < (size_t)m_size ? m_arr[idx] : dummy; };
        // Adds a object into the next index
        void operator+=(const T &item)
        {
            // Aslong as there is available space
            if (m_count < m_size)
            {
                // set the item under the next
                m_arr[m_count] = item;
                // Increment count
                m_count++;
            }
        };
    };

} // namespace sdds

#endif