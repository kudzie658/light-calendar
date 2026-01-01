#include <locale>
#include"Displayable.hpp"

class Time: public Displayable
{
  //Fields
  int m_hour;
  int m_minute;
  int m_second;
  
  //Constructors
  public:
  
  Time();
  Time(int hour, int minute, int second);
  Time(const Time &);
  Time(const Time &&);
  std::string getInfo() override;
  
  //Methods
  public:
  
  inline void setHour(int hr){m_hour=hr;}
  inline void setMinute(int min){m_minute=min;}
  inline void setSecond(int sec){m_second=sec;}
  bool setTime(int hour, int month, int second);
  
  inline int getHour() const{return m_hour;}
  inline int getMinute() const{return m_minute;}
  inline int getSecond() const{return m_second;}
  
  Time& operator=(const Time& ); //Overloading assignment operator
  Time& operator=(const Time&& ); //Overloading assignment operator with rvalue
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
