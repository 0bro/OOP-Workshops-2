#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <iomanip>
#include <string>

extern unsigned int g_sysClock;
const int MAX = 128;
namespace sdds
{
    class Event
    {
    private:
        char desc[MAX];
        int numOfSecs;
        static unsigned int counter;

    public:
        Event();
        const void display();
        void set(char *str = nullptr);
    };

} // namespace sdds

#endif