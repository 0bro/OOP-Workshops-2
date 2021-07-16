// Name: Muhammad Ibrahi Muhammad Yusoof
// Email: imuhammad-yusoof@myseneca.ca
// SEQ: 164366189
// Date: June 13 2021
#ifndef PAIR_H_SDDS
#define PAIR_H_SDDS

#include <iostream>

namespace sdds
{
    // Template requires typenames for Key and Value
    template <typename K, typename V>
    class Pair
    {
        // Key is the catogeory of a pair, and value is the item from the category
        K m_key;
        V m_value;

    public:
        // Default Constructor
        Pair<K, V>() : m_key(K()), m_value(V()) {}
        // Customer constructor 
        Pair(const K &key, const V &value) : m_key(key), m_value(value) {}
        // Returns the Key Value
        const K &key() const { return m_key; };
        // Returns the Value
        const V &value() const { return m_value; };
        // Display's teh base data
        virtual void display(std::ostream &os) const
        {
            os << m_key << " : " << m_value << std::endl;
        };
    };

    template <typename K, typename V>
    // Operator to display correct data and easier
    std::ostream &operator<<(std::ostream &os, const Pair<K, V> &pair)
    {
        // Calls display
        pair.display(os);
        return os;
    }
} // namespace sdds

#endif