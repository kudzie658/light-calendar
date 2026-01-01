#include <iostream>
#include <iomanip>
#include <memory>
#include<string>
#include<sstream>
#include "Date.hpp"
#include <stdio.h>
#include"Displayable.hpp"

const std::map<int, std::string> Date::s_days = 
{
    {1,"first_day" },
    {2,"second_day"},
    {3,"third_day"},
    {4,"fourth_day"},
    {5,"fifth_day"},
    {6,"sixth_day"},
    {7,"sabbath_day"}
  };
  
const std::map<int, std::string> Date::s_months = 
{
    {1,"January" },
    {2,"February"},
    {3,"March"},
    {4,"April"},
    {5,"May"},
    {6,"June"},
    {7,"July"},
    {8,"August"},
    {9,"September"},
    {10,"October"},
     {11,"November"},
     {12,"December"}
  };

Date::Date()
{
  m_year=m_month=m_day=0;
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
  
std::string Date::getInfo() 
   {
     std::ostringstream ss;
     ss<<m_year<<"/"<<m_month<<"/"<<m_day;
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
bool Date::operator>(const Date& other) const
  {
    if(m_year != other.getYear())
        return m_year > other.getYear();
    if(m_month != other.getMonth())    
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
		if(validate())
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
		if(m_year>0)
		{
			return 1;
		}
		return -1;
	}

int Date::dayCountInWeek() const
{
    return Date::s_days.find(m_day)->first;
}

int Date::monthCountInYear() const
{
    return Date::s_months.find(m_month)->first;
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
		return m_year%4 == 0;
	}

int Date::daysInMonth(int month, int year) const
	{
		int days_of_months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
		if(isLeapYear(year) && m_month == 2)
		{
			return 29;
		}
		
		return days_of_months[month];
	}
  
   std::string Date::getDayName() const
   {
     return Date::daysDayName(dayCountInWeek());
   }
   
     std::string Date::getMonthName() const
  {
    return Date::monthsMonthName(monthCountInYear());
  }

std::string Date::toShortDateString() const
{
  std::ostringstream ss;
  ss << m_year << "/" << std::setfill('0') << std::setw(2) << m_month << "/" << std::setfill('0') << std::setw(2) << m_day;
  return ss.str();
}
							
