// Name: Muhammad Ibrahi Muhammad Yusoof
// Email: imuhammad-yusoof@myseneca.ca
// SEQ: 164366189
// Date: June 03 2021

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <chrono>

const unsigned int MAX_EVENTS = 10;
namespace sdds
{

    class TimedEvents
    {
        int numOfEvents;
        std::chrono::time_point<std::chrono::system_clock> beginTime;
        std::chrono::time_point<std::chrono::system_clock> endTime;
        struct
        {
            std::string eventName;
            std::string unitsOfTime;
            std::chrono::duration<int, std::nano> duration;

        } Events[MAX_EVENTS];

    public:
        TimedEvents();
        void startClock();
        void stopClock();
        void addEvent(const std::string &str);
        friend std::ostream &operator<<(std::ostream &os, const TimedEvents &Event);
    };

} // namespace sdds

#endif