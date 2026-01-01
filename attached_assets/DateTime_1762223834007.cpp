#include <iostream>
#include <iomanip>
#include "DateTime.hpp"
#include"Displayable.hpp"
#include<chrono>
#include<sstream>

DateTime::DateTime(DateTime& other)
{
  *m_date_ptr = other.getDate();
  *m_time_ptr = other.getTime();
}

std::string DateTime::getInfo()
{
  std::ostringstream ss;
  ss<<m_date_ptr->getInfo()<<" "<<m_time_ptr->getInfo();
  return ss.str();
} 

std::string DateTime::format(std::string fmt) const
{
  
}

DateTime& DateTime::now()
{
  auto now = std::chrono::system_clock::now();
  std::time_t  current_time = std::chrono::system_clock::to_time_t(now);
  std::tm* local_time = std::localtime(&current_time);
  
}
