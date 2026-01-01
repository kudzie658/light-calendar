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
    std::vector < std::unique_ptr < Event>> events;
    static int events_count;
    DateTime m_current_date;

    private: void printCalendarGrid() const;
    private: void printWeeklyView() const;

    public:
    Calendar();
    Calendar(std::vector < Event >, DateTime& current_date);

    std::string getInfo() const override;
    static void incrementEvents(int n) {
        events_count += n;
    }
    void addEvent(Event& e) {
        events.emplace_back(std::make_unique < Event > (e));
    }

    void setDate(const DateTime& date);
    DateTime& getDate() const;

    void removeEvent(const std::string& title);
    std::vector < Event>& getEventsOnDate(const Date& date) const;
    void printDay(const Date& date) const;
    void display(std::string mode = "yyy")const;
};

#endif // CALENDAR_HPP