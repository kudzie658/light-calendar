#include <iostream>
#include "Calendar.hpp"
#include"Displayable.hpp"
#include"DateTime.hpp"
#include<sstream>

static int Calendar::events_count = 0;

Calendar::Calendar(std::vector<Event> events)
{
  for(auto e : events)
  {
    this->events.emplace_back(make_unique<Event>(e));
    incrementEvents(1);
  }
}

void Calendar::removeEvent(const std::string& title)
{
  events.erase(
            std::remove_if(events.begin(), events.end(),
                [&](const Event& e) { return *e.getTitle() == title; }),
            events.end()
        );
}

std::vector<Events> Calendar::getEventsOnDate(Date&)
{
  std::vector<Event> result;
        for (const auto e : events)
            if (*e.occursOn(date))
                result.push_back(*e);
        return result;
}

std:: string Calendar::getInfo()
{
  ostringstream ss;
  ss<<"";
  return ss.str();
}

void Calendar::printDay(const Date& date) const {
        auto dailyEvents = getEventsOnDate(date);
        std::cout << "Events on " << date << ":\n";
        for (const auto& e : dailyEvents)
  												std::cout<<e.getInfo()<<std::endl;
    }