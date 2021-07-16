#ifndef SET_H_SDDS
#define SET_H_SDDS

#include <iostream>

namespace sdds
{

    template <typename T, int N>
    class Set
    {
        T m_arr[N];
        const int m_size = N;
        unsigned int m_count = 0;
        T dummy;

    public:
        size_t size() const { return m_count; };
        const T &operator[](size_t idx) { return idx < m_size ? m_arr[idx]: dummy ;  };
        void operator+=(const T &item)
        {
            if (m_count < m_size)
            {
                m_arr[m_count] = item;
                m_count++;
            }
        };
    };

} // namespace sdds

#endif