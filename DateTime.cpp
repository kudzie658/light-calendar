#include <iostream>
#include <iomanip>
#include "DateTime.hpp"
#include "Displayable.hpp"
#include <chrono>
#include <sstream>

DateTime::DateTime(const DateTime& other)
{
    m_date_ptr = std::make_unique<Date>(other.getDate());
    m_time_ptr = std::make_unique<Time>(other.getTime());
}

std::string DateTime::getInfo() const
{
    std::ostringstream ss;
    ss << m_date_ptr->getInfo() << " " << m_time_ptr->getInfo();
    return ss.str();
} 

std::string DateTime::format(std::string fmt) const
{
    std::ostringstream ss;
    ss << m_date_ptr->toShortDateString() << " " << m_time_ptr->getInfo();
    return ss.str();
}

DateTime DateTime::now()
{
    auto now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&current_time);
    
    return DateTime(
        local_time->tm_year + 1900,
        local_time->tm_mon + 1,
        local_time->tm_mday,
        local_time->tm_hour,
        local_time->tm_min,
        local_time->tm_sec
    );
}
