// Muhammad Ibrahi Muhammad Yusoof
// 164366189
// imuhammad-yusoof@myseneca.ca
// May 29 2021


#include "event.h"

using namespace std;

unsigned int g_sysClock = 0;

namespace sdds
{
    // Constructor
    Event::Event()
    {
        desc = nullptr;
        numOfSecs = 0;
    }
    // Assignment operator
    Event &Event::operator=(const Event &cpy)
    {

        // If source is valid
        if (cpy.desc != nullptr && this != &cpy)
        {
            // Set data
            desc = new char[strlen(cpy.desc) + 1];
            strcpy(desc, cpy.desc);
            numOfSecs = cpy.numOfSecs;
        }
        // Return this
        return *this;
    }
    // Copy constructor
    Event::Event(const Event &cpy)
    {
        desc = nullptr;
        numOfSecs = 0;
        *this = cpy;
    }
    // Destructor
    Event::~Event()
    {
        delete[] desc;
        desc = nullptr;
    }
    // Display Function
    const void Event::display()
    {
        // Static to maintain count
        static unsigned int counter = 0;
        // Formating
        cout << setw(2)
             << setfill(' ')
             << ++counter << ". ";
        // If pointer is valid(not null)
        if (desc)
        {
            // Display using formating
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
        // If pointer is invalid (Nullptr)
        else
        {
            cout << "| No Event |" << endl;
        }
    }
    // Set Function
    void Event::set(char *str)
    {

        delete[] desc;
        desc = nullptr;
        // If parameter is valid (valid) then Allocate space in desc
        if (str != nullptr && str[0] != '\0')
        {
            desc = new char[strlen(str) + 1];
            strcpy(desc, str);
        }
        numOfSecs = ::g_sysClock;
    }

} // namespace sdds
