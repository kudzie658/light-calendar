#include <iostream>
#include "Time.hpp" 
#include "Displayable.hpp"
#include <sstream>

Time::Time()
{
    m_hour = 0;
    m_minute = 0;
    m_second = 0;
}

Time::Time(int hour, int minute, int second)
{
    m_hour = hour;
    m_minute = minute;
    m_second = second;
    normalize();
}
  
Time::Time(const Time &other)
{
    m_hour = other.getHour();
    m_minute = other.getMinute();
    m_second = other.getSecond();
    normalize();
}
  
Time::Time(const Time &&other)
{
    m_hour = other.getHour();
    m_minute = other.getMinute();
    m_second = other.getSecond();
    normalize();
}

std::string Time::getInfo() const
{
    std::ostringstream ss;
    ss << m_hour << ":" << m_minute << ":" << m_second;
    return ss.str();
}

bool Time::setTime(int hour, int minute, int second)
{
    if (validate())
    {
        m_hour = hour;
        m_minute = minute;
        m_second = second;
        normalize();
        return true;
    }
    return false;
}

Time& Time::operator=(const Time&& other)
{
    m_hour = other.getHour();
    m_minute = other.getMinute();
    m_second = other.getSecond();
    return *this;
}

bool Time::operator==(const Time& other) const
{
    return m_hour == other.getHour() && m_minute == other.getMinute() && m_second == other.getSecond();
}
  
bool Time::operator<(const Time& other) const
{
    if (m_hour != other.getHour())
        return m_hour < other.getHour();
    if (m_minute != other.getMinute())    
        return m_minute < other.getMinute();
    return m_second < other.getSecond();
}
  
bool Time::operator>(const Time& other) const
{
    return other < *this;
}
  
bool Time::operator>=(const Time& other) const
{
    return !(*this < other);
}
  
bool Time::operator<=(const Time& other) const
{
    return !(*this > other);
}
  
int Time::validate() const
{
    return (m_hour > -1 && m_minute > -1 && m_second > -1) ? 1 : -1;
}
  
void Time::normalize()
{
    if (m_second >= 60)
    {
        m_minute += m_second / 60;
        m_second %= 60;
    }
    if (m_minute >= 60)
    {
        m_hour += m_minute / 60;
        m_minute %= 60;
    }
    if (m_second < 0)
    {
        int borrowed = abs(m_second);
        m_minute += borrowed;
        m_second = borrowed;
    }
    if (m_minute < 0)
    {
        int borrowed = abs(m_minute);
        m_hour += borrowed;
        m_minute = borrowed;
    }
}
