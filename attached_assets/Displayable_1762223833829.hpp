#include<iostream>
#include<string>
#ifndef CANDISPLAY_HPP
#define CANDISPLAY_HPP
class Displayable
{
	public:
    virtual std::string getInfo() = 0;
};
#endif //CANDISPLAY_HPP
