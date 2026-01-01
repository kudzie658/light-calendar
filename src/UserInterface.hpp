#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP
#include"Displayable.hpp"
#include<string>
#include"Email.hpp"
#include"Calendar.hpp"

class UserInterface
{
    private:
    Email m_user;
    Calendar m_calendar;

    public:
    UserInterface(Email& user): m_user(user) {}
    UserInterface(UserInterface& u_interface) {
        user = u_interface.getUser();
    }

    Email& getUser() {
        return m_user;
    }
    
    void display()
    {
        log("======================");
        log("\tCurrent user");
        log(m_user.getUsername());
        log("======================");
        log("\tCalendar info");
        m_calendar.display();
    }
    
    std::string getInfo() const
    {
        return "User:\n" + user.getInfo();
    }

}
#endif //USERINTERFACE_HPP