#include <iostream>
#include "DateTime.hpp" 

void display(Displayable* displayable_obj)
{
    std::cout << displayable_obj->getInfo() << "\n";
}

std::ostream& operator<<(std::ostream& COUT, DateTime& dt)
{
    COUT <<dt.getInfo()<<std::endl;
    return COUT;
}

int main() 
{
    Date d(2007, 8, 15);
    Time t(12, 0, 0);
    DateTime dt(d,t);
    
    DateTime currDate(dt.now());
    std::cout<<currDate;
    display(&currDate);
  
    return 0;
}
