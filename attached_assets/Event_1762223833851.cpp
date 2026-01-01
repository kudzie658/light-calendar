#include <iostream>
#include "Event.hpp"
#include"Displayable.hpp"
#include"DateTime.hpp"
#include<sstream>

std::string Event::getInfo() 
{
  std::ostringstream ss;
  ss << m_title << " (" << m_start_ptr << " - " << m_end_ptr << ")\n";
        if (m_description != "")
            ss << m_title << " (" << m_start_ptr << " - " << m_end_ptr << ")\n"<< "  " << m_description << "\n";
  return ss.str();
}

bool Event::conflictsWith(Event& other)
{
  // Two events conflict if their time intervals overlap
        return !(*(m_end_ptr) <= other.getStart || *(m_start_ptr) >= other.getEnd);
}

bool Event::occursOn(Date& d)
{
  return d >= *(m_start_ptr) && d <= *(m_end_ptr);
}
