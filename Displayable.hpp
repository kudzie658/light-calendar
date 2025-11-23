#ifndef DISPLAYABLE_HPP
#define DISPLAYABLE_HPP

#include <iostream>
#include <string>

class Displayable
{
public:
    virtual std::string getInfo() const = 0;
    virtual ~Displayable() = default;
};

#endif // DISPLAYABLE_HPP
