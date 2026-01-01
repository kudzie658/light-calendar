#include <iostream>
#include "Calendar.hpp"
#include "Displayable.hpp"
#include "DateTime.hpp"
#include <sstream>

int Calendar::events_count = 0;

void printCalendarGrid() const
{
    lognnl("1ˢᵗ    2ⁿᵈ   3ʳᵈ   4ᵗʰ   5ᵗʰ   6ᵗʰ   7ᵗʰ");
    log("(Day)");
}

void printWeeklyView() const
{
    lognnl("1ˢᵗ    2ⁿᵈ   3ʳᵈ   4ᵗʰ   5ᵗʰ   6ᵗʰ   7ᵗʰ");
    log("(Day)");    
}

Calendar::Calendar() {}

Calendar::Calendar(std::vector < Event > events) {
    for (auto& e: events) {
        this->events.emplace_back(std::make_unique < Event > (e));
        incrementEvents(1);
    }
}

void setDate(const DateTime& date) {
    m_current_date = date;
}

DateTime& getDate() const
{
    return m_current_date;
}

void Calendar::removeEvent(const std::string& title) {
    events.erase(
        std::remove_if(events.begin(), events.end(),
            [&](const std::unique_ptr < Event>& e) {
                return e->getTitle() == title;
            }),
        events.end()
    );
}

std::vector < Event > Calendar::getEventsOnDate(const Date& date) const
{
    std::vector < Event > result;
    for (const auto& e: events)
    if (e->occursOn(date))
    result.push_back(*e);
    return result;
}

std::string Calendar::getInfo() const
{
    std::ostringstream ss;
    ss << "Calendar with " << events.size() << " events"<<std::endl<<"Current date: "<<m_current_date.getInfo();
    return ss.str();
}

void Calendar::printDay(const Date& date) const
{
    auto dailyEvents = getEventsOnDate(date);
    std::cout << "Events on " << date.getInfo() << ":\n";
    for (const auto& e: dailyEvents)
    std::cout << e.getInfo() << std::endl;
}

void Calendar::display(std::string& mode)const
{
    if(mode == "yyy") {
        printCalendarGrid();
    }
    printWeeklyView();
}