#ifndef DATETIME_HPP
#define DATETIME_HPP

#include <iostream>
#include <memory>
#include <string>
#include "Displayable.hpp"
#include "Date.hpp"
#include "Time.hpp"

class DateTime: public Displayable
{
    // Fields
    private:
    std::unique_ptr < Date > m_date_ptr;
    std::unique_ptr < Time > m_time_ptr;

    // Constructors
    public:
    DateTime(): m_date_ptr(std::make_unique < Date > ()), m_time_ptr(std::make_unique < Time > ()) {}
    DateTime(const DateTime& other);
    DateTime(Date& d, Time& t): m_date_ptr(std::make_unique < Date > (d)),m_time_ptr(std::make_unique < Time > (t)) {}
    DateTime(int y, int m, int d, int h, int min, int s): m_date_ptr(std::make_unique < Date > (y, m, d)),m_time_ptr(std::make_unique < Time > (h, min, s)) {}

    //Member methods
    public
    std::string getInfo() const override;
    void setDate(int y, int m, int d) {
        m_date_ptr->setDate(y, m, d);
    }
    void setTime(int h, int mi, int s) {
        m_time_ptr->setTime(h, mi, s);
    }

    inline int getYear() const {
        return m_date_ptr->getYear();
    }
    inline int getMonth() const {
        return m_date_ptr->getMonth();
    }
    inline int getDay() const {
        return m_date_ptr->getDay();
    }
    inline Date& getDate() const {
        return *m_date_ptr;
    }

    inline int getHour() const {
        return m_time_ptr->getHour();
    }
    inline int getMinute() const {
        return m_time_ptr->getMinute();
    }
    inline int getSecond() const {
        return m_time_ptr->getSecond();
    }
    inline Time& getTime() const {
        return *m_time_ptr;
    }

    bool operator == (const DateTime& other) const {
        return *m_date_ptr == other.getDate() && *m_time_ptr == other.getTime();
    }
    bool operator < (const DateTime& other) const {
        if (*m_date_ptr != other.getDate())
        return *m_date_ptr < other.getDate();
        return *m_time_ptr < other.getTime();
    }
    bool operator > (const DateTime& other) const {
        if (*m_date_ptr != other.getDate())
        return *m_date_ptr > other.getDate();
        return *m_time_ptr > other.getTime();
    }
    bool operator <= (const DateTime& other) const {
        return *this < other || *this == other;
    }
    bool operator >= (const DateTime& other) const {
        return *this > other || *this == other;
    }

    std::string format(std::string fmt = "YYYY-MM-DD HH:MM:SS") const;
    std::string dayOfWeek() const {
        return m_date_ptr->getDayName();
    }
    static DateTime now();
};

#endif // DATETIME_HPP