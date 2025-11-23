#ifndef TIME_HPP
#define TIME_HPP

#include <locale>
#include <string>
#include "Displayable.hpp"

class Time: public Displayable
{
   // Fields
   int m_hour;
   int m_minute;
   int m_second;
  
   // Constructors
public:
   Time();
   Time(int hour, int minute, int second);
   Time(const Time &);
   Time(const Time &&);
   std::string getInfo() const override;
  
   // Methods
public:
   inline void setHour(int hr){m_hour=hr;}
   inline void setMinute(int min){m_minute=min;}
   inline void setSecond(int sec){m_second=sec;}
   bool setTime(int hour, int minute, int second);
  
   inline int getHour() const{return m_hour;}
   inline int getMinute() const{return m_minute;}
   inline int getSecond() const{return m_second;}
  
   Time& operator=(const Time& );
   Time& operator=(const Time&& );
   bool operator==(const Time & ) const;
   bool operator>(const Time& ) const;
   bool operator<(const Time& ) const;
   bool operator>=(const Time& ) const;
   bool operator<=(const Time& ) const;
  
   inline void addSeconds(const int s){m_second+=s; normalize();}
   inline void addMinutes(const int m){m_minute+=m; normalize();}
   inline void addHours(const int h){m_hour+=h; normalize();}
  
private:
   void normalize();
   int validate() const;
};

#endif // TIME_HPP
