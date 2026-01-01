#include <iostream>
#include "DateTime.hpp" 

void display(Displayable* displayable_obj)
{
    std::cout << displayable_obj->getInfo() << "\n";
}

int main() 
{
    Date d(2007, 8, 15);
    Time t(12, 0, 0);
  
    std::cout << "Date: ";
    display(&d);
    std::cout << "Time: ";
    display(&t);
  
    DateTime dt(d, t);
  
    std::cout << "Date time: ";
    display(&dt);
  
    return 0;
}
