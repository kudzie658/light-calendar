#include<iostream>
#include<string>
#include"Displayable.hpp"
#include"DateTime.hpp"

#ifndef EVENT_HPP
#define EVENT_HPP
class Event: public Displayable
{
							private:
							std::string m_title;
							std::string m_description;
							std::unique_ptr<DateTime> m_start_ptr;
							std::unique_ptr<DateTime> m_end_ptr;
							
							public:
							
							Event(): m_title("No event"), m_description("No description"), m_start_ptr(std::make_unique<DateTime>()), m_end_ptr(std::make_unique<DateTime>()){}
							
							Event(std::string ttl, std::string dsp, std::unique_ptr<DateTime>strt, std::unique_ptr<DateTime>stp): m_title(ttl), m_description(dsp), m_start_ptr(std::make_unique<DateTime>(strt)), m_end_ptr(std::make_unique<DateTime>(stp)){}
							
							std::string  getInfo() override;
							inline std::string getTitle(){return m_title;}
							inline std::string getDescription(){return m_description;}
							inline DateTime& getStart(){return *m_start_ptr;}
							inline DateTime& getEnd(){return *m_start_ptr;}
							bool conflictsWith(Event&);
							bool occursOn(Date&);
};
#endif //EVENT_HPP
