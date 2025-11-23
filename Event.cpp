#include <iostream>
#include "Event.hpp"
#include "Displayable.hpp"
#include "DateTime.hpp"
#include <sstream>

std::string Event::getInfo() const
{
    std::ostringstream ss;
    ss << m_title << " (" << m_start_ptr->getInfo() << " - " << m_end_ptr->getInfo() << ")\n";
    if (m_description != "")
        ss << "  " << m_description << "\n";
    return ss.str();
}

bool Event::conflictsWith(Event& other)
{
    return !(*(m_end_ptr) <= other.getStart() || *(m_start_ptr) >= other.getEnd());
}

bool Event::occursOn(const Date& d)
{
    Date& startDate = m_start_ptr->getDate();
    Date& endDate = m_end_ptr->getDate();
    return d >= startDate && d <= endDate;
}
