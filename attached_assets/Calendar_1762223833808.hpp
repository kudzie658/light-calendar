#include<iostream>
#include"Displayable.hpp"
#include"DateTime.hpp"
#include"Event.hpp"

#ifndef CALENDAR_HPP
#define CALENDAR_HPP
class Calendar: public Displayable
{
							private:
							
							std::vector<unique_ptr<Event>> events;
							static int events_count;
							
							public:
							
							Calendar();
							Calendar(std::vector<Event>);
							
							std:: string  getInfo() override;
							static void incrementEvents(int n){events_count += n;}
							void addEvent(Event& e){events.emplace_back(make_unique<Event>(e));}
							void removeEvent(const std::string& title);
							std::vector<Events> getEventsOnDate(Date&);
							void printDay(const Date& date) const;
							
};
#endif //CALENDAR_HPP
