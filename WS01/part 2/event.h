// Muhammad Ibrahi Muhammad Yusoof
// 164366189
// imuhammad-yusoof@myseneca.ca
// May 29 2021

#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <iomanip>
#include <cstring>

extern unsigned int g_sysClock;
const int MAX = 128;
namespace sdds
{
    class Event
    {
    private:
        char *desc;
        int numOfSecs;
        static unsigned int counter;
    public:
        Event();
        Event(const Event &cpy);
        Event &operator=(const Event &cpy);
        ~Event();
        // 
        const void display();
        // Default parameter
        void set(char *str = nullptr);
    };

} // namespace sdds

#endif