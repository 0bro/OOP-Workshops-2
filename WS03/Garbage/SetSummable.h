#ifndef SET_SUMMABLE_H_SDDS
#define SET_SUMMABLE_H_SDDS

#include <iostream>
#include "Set.h"

namespace sdds
{

    template <typename T, int N>
    class SetSummable : public Set<T, N>
    {

    public:
        T accumulate(const std::string &filter) const
        {
            T temp(filter);
            for (int i = 0; i < this->size(); i++)
            {
                // temp += this[i];
                if (filter == this[i].m_key())

            }
            return temp;
        }
    };

} // namespace sdds

#endif