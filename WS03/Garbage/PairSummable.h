#ifndef PAIR_SUMMABLE_H_SDDS
#define PAIR_SUMMABLE_H_SDDS

#include <iostream>
#include "Pair.h"
namespace sdds
{

    template <typename K, typename V>
    class PairSummable : public Pair<K, V>
    {
        static V m_initial;
        static size_t minWidth;

    public:
        PairSummable<K, V>() : Pair<K, V>() {}
        PairSummable(const K &key, const V &value = m_initial) : Pair<K, V>(key, value)
        {
            (size(key) > minWidth) ? minWidth(size(key)) : minWidth=0;
        }
        PairSummable &operator+=(const PairSummable &src)
        {
            if (this != src)
            {
                if (this->key() == src.key())
                {
                    m_initial += src.m_initial;
                }
            }
            return *this;
        }
        void display(std::ostream &os) const
        {
            os << "display";
        }
    };

    template <>
    class PairSummable<std::string, std::string> : public Pair<std::string, std::string>
    {
        static std::string m_initial;
        static size_t minWidth;

    public:
        PairSummable() : Pair<std::string, std::string>() {}
        PairSummable(const std::string &key, const std::string &value = "") : Pair<std::string, std::string>(key, value)
        {
            (key.size() > minWidth) ? minWidth = key.size() : minWidth=0;
        }

        PairSummable &operator+=(PairSummable &src)
        {
            if (this != &src)
            {
                if (this->key() == src.key())
                {
                    m_initial = m_initial + ", " + src.m_initial;
                }
            }
            return *this;
        }
    };

    template <>
    class PairSummable<std::string, int> : public Pair<std::string, int>
    {
        static int m_initial;
        static size_t minWidth;

    public:
        PairSummable() : Pair<std::string, int>() {}
        PairSummable(const std::string &key, const int &value = 0) : Pair<std::string, int>(key, value)
        {
            (key.size() > minWidth) ? minWidth = key.size() : minWidth = 0;
        }

        PairSummable &operator+=(const PairSummable &src)
        {
            if (this != &src)
            {
                if (this->key() == src.key())
                {
                    m_initial += src.m_initial;
                }
            }
            return *this;
        }
    };
} // namespace sdds

#endif