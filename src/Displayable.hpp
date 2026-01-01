#ifndef DISPLAYABLE_HPP
#define DISPLAYABLE_HPP

#include <iostream>
#include <string>

#define log(value) std::cout<<value<<std::endl; //Log with new line
#define lognnl() std::cout<<value; //Log no new line

class Displayable
{
public:
    virtual std::string getInfo() const = 0;
    virtual ~Displayable() = default;
};

#endif // DISPLAYABLE_HPP
