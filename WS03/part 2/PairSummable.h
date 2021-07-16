// Name: Muhammad Ibrahi Muhammad Yusoof
// Email: imuhammad-yusoof@myseneca.ca
// SEQ: 164366189
// Date: June 13 2021

#ifndef PAIRSUMMABLE_H_SDDS
#define PAIRSUMMABLE_H_SDDS

#include <iostream>
#include <iomanip>
#include "Pair.h"

namespace sdds
{
    // Template requires typenames for Key and Value
    template <typename V, typename K>
    class PairSummable : public Pair<K, V>
    {
        // A value that holds the intitial value throughout multiple objects
        static V m_initial;
        // A value that holds the width of the largest width through out objects for the display function
        static size_t m_minWidth;

    public:
        // Default constructor
        PairSummable() : Pair<K, V>(){};
        // Custom Constructor that sets the min Width
        PairSummable(const K &key, const V &value = m_initial) : Pair<K, V>(key, value)
        {
            if (m_minWidth < size(key))
                m_minWidth = size(key);
        }
        // Resets the static variables when neccesary
        void reset()
        {
            m_initial = 0;
        };
        // Returns true if current key and next key are the same
        bool isCompatibleWith(const PairSummable<V, K> &b) const
        {
            return (this->key() == b.key());
        }
        // adds value data with initial data aslogn as data is valid.
        PairSummable &operator+=(const PairSummable<V, K> &src)
        {
            // aslong as the incoming object isn't the current object
            if (this != &src)
            {
                // aslong as they're compatible
                if (this->isCompatibleWith(src))
                {
                    // Add other value to the initial of current object
                    m_initial += src.value();
                    // Create a new object that has the new initial data
                    *this = PairSummable(this->key(), m_initial);
                }
            }
            // Return current data
            return *this;
        }
        // Overide Display to add function the call base function
        void display(std::ostream &os) const
        {
            // Formatting
            os << std::fixed << std::left << std::setw(m_minWidth);
            // Call base Display
            Pair<K, V>::display(os);
        }
    };

    // Set static variables
    template <typename V, typename K>
    V PairSummable<V, K>::m_initial = 0;
    template <typename V, typename K>
    size_t PairSummable<V, K>::m_minWidth = 0;

    // Denotes Specialization
    template <>
    // Does all the same, but has special actions for String Pairs
    class PairSummable<std::string, std::string> : public Pair<std::string, std::string>
    {
        // A value that holds the intitial value throughout multiple objects
        static std::string m_initial;
        // A value that holds the minWidth throughout multiple objects
        static size_t m_minWidth;

    public:
        // Default constructor
        PairSummable() : Pair<std::string, std::string>(){};
        // Custom Constructor that sets the min Width
        PairSummable(const std::string &key, const std::string &value = m_initial) : Pair<std::string, std::string>(key, value)
        {
            m_initial = value;
            if (m_minWidth < key.size())
                m_minWidth = key.size();
        }
        // Resets the static variables when neccesary
        void reset()
        {
            m_initial = "";
        };
        // Returns true if current key and next key are the same
        bool isCompatibleWith(const PairSummable<std::string, std::string> &b) const
        {

            return (this->key() == b.key());
        }
        // adds value data with initial data aslogn as data is valid.
        PairSummable &operator+=(const PairSummable<std::string, std::string> &src)
        {
            // aslong as the incoming object isn't the current object
            if (this != &src)
            {
                // aslong as they're compatible
                if (this->isCompatibleWith(src))
                {

                    std::string newVal;
                    // If the intitial value is blank then set the new Value as just the other value
                    if (m_initial == "")
                        newVal = src.value();
                    // If the intitial value isn't blank then add a comma between value and initial
                    else
                        newVal = m_initial + ", " + src.value();
                    // create a new Object with the new value
                    *this = PairSummable(this->key(), newVal);
                }
            }
            // return this item
            return *this;
        }
        // Overide Display to add function the call base function
        void display(std::ostream &os) const
        {
            // Formatting
            os << std::fixed << std::left << std::setw(m_minWidth);
            // Call base Display
            Pair<std::string, std::string>::display(os);
        }
    };
    // Set static variables
    std::string PairSummable<std::string, std::string>::m_initial = "";

    size_t PairSummable<std::string, std::string>::m_minWidth = 0;

} // namespace sdds

#endif