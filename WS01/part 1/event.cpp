#include "event.h"

using namespace std;

unsigned int g_sysClock = 0;

namespace sdds
{

    Event::Event()
    {
        numOfSecs = 0;
    }
    const void Event::display()
    {
        static unsigned int counter = 0;
        cout << ++counter << ". ";
        if (desc[0] == '\0')
        {
            cout << "| No Event |" << endl;
        }
        else
        {
            int hrs, mins, secs, time = numOfSecs;
            hrs = time / 3600;
            time = time % 3600;
            mins = time / 60;
            time = time % 60;
            secs = time;
            cout << setfill('0') << setw(2) << hrs;
            cout << ":";
            cout << setfill('0') << setw(2) << mins;
            cout << ":";
            cout << setfill('0') << setw(2) << secs;
            cout << " => " << desc << endl;
        }
    }
    void Event::set(char *str)
    {
        if (str == nullptr)
            desc[0] = '\0';
        else
            strcpy(desc, str);
        numOfSecs = ::g_sysClock;
    }

} // namespace sdds