#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <sstream>
#include "Date.hpp"
#include <stdio.h>
#include "Displayable.hpp"

const std::map<int, std::string> Date::s_days = 
{
    {1, "first_day"},
    {2, "second_day"},
    {3, "third_day"},
    {4, "fourth_day"},
    {5, "fifth_day"},
    {6, "sixth_day"},
    {7, "sabbath_day"}
};
  
const std::map<int, std::string> Date::s_months = 
{
    {1, "January"},
    {2, "February"},
    {3, "March"},
    {4, "April"},
    {5, "May"},
    {6, "June"},
    {7, "July"},
    {8, "August"},
    {9, "September"},
    {10, "October"},
    {11, "November"},
    {12, "December"}
};

Date::Date()
{
    m_year = 1970;
    m_month = 1;
    m_day = 1;
}

Date::Date(int year, int month, int day)
{
    m_year = year;
    m_month = month;
    m_day = day;
}

Date::Date(const Date& d)
{
    m_year = d.getYear();
    m_month = d.getMonth();
    m_day = d.getDay();
}
  
std::string Date::getInfo() const
{
    std::ostringstream ss;
    ss << m_year << "/" << m_month << "/" << m_day;
    return ss.str();
}

Date& Date::operator=(const Date &other)
{
    m_year = other.getYear();
    m_month = other.getMonth();
    m_day = other.getDay();
    return *this;
}

Date& Date::operator=(const Date &&other)
{
    m_year = other.getYear();
    m_month = other.getMonth();
    m_day = other.getDay();
    return *this;
}

bool Date::operator==(const Date& d) const
{
    return (m_year == d.getYear() && m_month == d.getMonth() && m_day == d.getDay());
}

bool Date::operator!=(const Date& d) const
{
    return !(*this == d);
}

bool Date::operator>(const Date& other) const
{
    if (m_year != other.getYear())
        return m_year > other.getYear();
    if (m_month != other.getMonth())    
        return m_month > other.getMonth();
    return m_day > other.getDay();    
}
    
bool Date::operator<(const Date& other) const
{
    return other > *this;
}

bool Date::operator>=(const Date& other) const
{
    return (*this > other || *this == other);
}
  
bool Date::operator<=(const Date& other) const
{
    return (*this < other || *this == other);
}
  
bool Date::setDate(int year, int month, int day)
{
    if (year > 0 && month >= 1 && month <= 12 && day >= 1 && day <= daysInMonth(month, year))
    {
        m_year = year;
        m_month = month;
        m_day = day;
        return true;
    }
    return false;
}
        
int Date::validate() const
{
    if (m_year > 0)
    {
        return 1;
    }
    return -1;
}

int Date::dayCountInWeek() const
{
    int y = m_year;
    int m = m_month;
    int d = m_day;
    
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    
    int q = d;
    int m_adj = m;
    int k = y % 100;
    int j = y / 100;
    
    int h = (q + ((13 * (m_adj + 1)) / 5) + k + (k / 4) + (j / 4) - (2 * j)) % 7;
    
    int dayOfWeek = ((h + 6) % 7) + 1;
    
    return dayOfWeek;
}

int Date::monthCountInYear() const
{
    auto itr = Date::s_months.find(m_month);
    if (itr != s_months.end())
        return itr->first;
    return 0;
}

std::string Date::daysDayName(int countInWeek)
{
    auto itr = Date::s_days.find(countInWeek);
    if (itr != s_days.end())
    {
        return itr->second;
    }
    return "";
}

std::string Date::monthsMonthName(int countInYear) 
{
    auto itr = Date::s_months.find(countInYear);
    if (itr != s_months.end())
    {
        return itr->second;
    }
    return "";
}

bool Date::isLeapYear(int year) const
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

int Date::daysInMonth(int month, int year) const
{
    if (month < 1 || month > 12)
        return 0;
    
    int days_of_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (month == 2 && isLeapYear(year))
    {
        return 29;
    }
    
    return days_of_months[month - 1];
}
  
std::string Date::getDayName() const
{
    int dayOfWeek = dayCountInWeek();
    if (dayOfWeek == 0)
        return "Unknown";
    return Date::daysDayName(dayOfWeek);
}
   
std::string Date::getMonthName() const
{
    if (m_month < 1 || m_month > 12)
        return "Unknown";
    return Date::monthsMonthName(m_month);
}

std::string Date::toShortDateString() const
{
    std::ostringstream ss;
    ss << m_year << "/" << std::setfill('0') << std::setw(2) << m_month << "/" << std::setfill('0') << std::setw(2) << m_day;
    return ss.str();
}
