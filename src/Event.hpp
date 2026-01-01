#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>
#include <string>
#include <memory>
#include "Displayable.hpp"
#include "DateTime.hpp"

class Event: public Displayable
{
    private:
    std::string m_title;
    std::string m_description;
    std::unique_ptr < DateTime > m_start_ptr;
    std::unique_ptr < DateTime > m_end_ptr;

    public:
    Event(): m_title("No event"),
    m_description("No description"),
    m_start_ptr(std::make_unique < DateTime > ()),
    m_end_ptr(std::make_unique < DateTime > ()) {}

    Event(const Event& other): m_title(other.m_title),
    m_description(other.m_description),
    m_start_ptr(std::make_unique < DateTime > (other.m_start_ptr->getDate(), other.m_start_ptr->getTime())),
    m_end_ptr(std::make_unique < DateTime > (other.m_end_ptr->getDate(), other.m_end_ptr->getTime())) {}

    Event(std::string ttl, std::string dsp, std::unique_ptr < DateTime > strt, std::unique_ptr < DateTime > stp): m_title(ttl),
    m_description(dsp),
    m_start_ptr(std::move(strt)),
    m_end_ptr(std::move(stp)) {}

    std::string getInfo() const override;
    inline std::string getTitle() {
        return m_title;
    }
    inline std::string getDescription() {
        return m_description;
    }
    inline DateTime& getStart() {
        return *m_start_ptr;
    }
    inline DateTime& getEnd() {
        return *m_end_ptr;
    }
    bool conflictsWith(Event&);
    bool occursOn(const Date&);
};

#endif // EVENT_HPP