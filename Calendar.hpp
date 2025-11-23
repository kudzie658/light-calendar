#ifndef CALENDAR_HPP
#define CALENDAR_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "Displayable.hpp"
#include "DateTime.hpp"
#include "Event.hpp"

class Calendar: public Displayable
{
private:
    std::vector<std::unique_ptr<Event>> events;
    static int events_count;
    
public:
    Calendar();
    Calendar(std::vector<Event>);
    
    std::string getInfo() const override;
    static void incrementEvents(int n) { events_count += n; }
    void addEvent(Event& e) { events.emplace_back(std::make_unique<Event>(e)); }
    void removeEvent(const std::string& title);
    std::vector<Event> getEventsOnDate(const Date& date) const;
    void printDay(const Date& date) const;
};

#endif // CALENDAR_HPP
