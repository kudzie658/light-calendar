#include <initializer_list>
#include <type_traits>
#include <string>
#include <map>
#include"Displayable.hpp"
#include<iostream>

class Date: public Displayable
{
  
   //Static members
  private:

   static const std::map<int, std::string> s_days;
   static const std::map<int, std::string> s_months;
   
   public:
   
   static std::string daysDayName(int);
   static std::string monthsMonthName(int);

  // Fields
  private:
  
   int m_year;
   int m_month;
   int m_day;

  // Constructors
  public:
  
   Date(int year, int month, int day);
   Date();
   Date(const Date &d);
   std::string getInfo() override;
   
  public:

   inline void setYear(int y){m_year = y;}
   inline void setMonth(int m){m_month = m;}
   inline void setDay(int d){m_day = d;}
   bool setDate(int year, int month, int day);

   inline int getYear() const{return m_year;}
   inline int getMonth() const{return m_month;}
   inline int getDay() const{return m_day;}
   inline Date getDate() const{return *this;}

   inline void addDays(int d){m_day+=d;}
   inline void addMonths(int m){m_month+=m;}
   inline void addYears(int y){m_year+=y;};

   bool isLeapYear(int year) const;
   int daysInMonth(int month, int year) const;
   std::string getDayName() const;
   std::string getMonthName() const;
   std::string toShortDateString() const;
  
   bool operator==(const Date& ) const;
   bool operator>(const Date& ) const;
   bool operator<(const Date& ) const;
   bool operator>=(const Date& ) const;
   bool operator<=(const Date& ) const ;
   Date& operator= (const Date &);
   Date& operator= (const Date &&);
   
  private:
  
   int validate() const;
   int dayCountInWeek() const;
   int monthCountInYear() const;
};
