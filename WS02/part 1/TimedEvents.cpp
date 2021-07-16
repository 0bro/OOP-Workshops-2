#include "TimedEvents.h"

using namespace std;
namespace sdds
{

    TimedEvents::TimedEvents()
    {
        numOfEvents = 0;
    }
    void TimedEvents::startClock()
    {
        beginTime = std::chrono::system_clock::now();
    }
    void TimedEvents::stopClock()
    {
        endTime = std::chrono::system_clock::now();
    }
    void TimedEvents::addEvent(const string &str)
    {
        if (numOfEvents != MAX_EVENTS)
        {
            Events[numOfEvents].eventName.assign(str);

            Events[numOfEvents].unitsOfTime.assign("nanoseconds");

            Events[numOfEvents].duration = endTime - beginTime;
            numOfEvents++;
        }
    }
    std::ostream &operator<<(std::ostream &os, const TimedEvents &event)
    {
        os << "Execution Times:" << endl
           << "--------------------------" << endl;

        for (int i = 0; i < event.numOfEvents; i++)
        {
            os.width(20);
            os.fill(' ');
            os << left << event.Events[i].eventName << "     ";
            os.width(20);
            os.fill(' ');
            os << right << event.Events[i].duration.count() << "     ";

            os << event.Events[i].unitsOfTime << "     " << endl;
        };
        os << "--------------------------" << endl;
        return os;
    }

} // namespace sdds
