#ifndef EMAIL_HPP
#define EMAIL_HPP
#include "Displayable.hpp"
#include <string>
#include<tuple>

class Email
{
    private:
    std::string m_username;
    std::string m_password;
    std::string m_domain;

    public:
    Email(std::string username = "username", std::string password = "Passw@123", std::string domain = "example.com"): m_username(username),
    m_password(password), m_domain(domain) {}
    Email(Email& other)
    {
        set(other.getUsername(),other.getPassword(), other.getDomain());
    }
    
    Email(Email&& other)
    {
        set(other.getUsername(),other.getPassword(),other.getDomain());
    }

    Email& operator = (Email& other) {
        set(other.getUsername(), other.getPassword(),other.getDomain());
        return *this;
    }

    void set(std::string username, std::string password, str::string domain) {
        m_username = username
        m_password = password;
        m_domain = domain;
    }

    std::tuple < std::string,
    std::string, std::string>& get()const
    {
        return {
            m_username,
            m_password,
            m_domain
        };
    }
    
    std::string& getEmail()
    {
        return m_username + "@" + m_domain;
    }
    
    void setUsername(std::string username)
    {
        m_username = username;
    }
    
    void setPassword(std::string password)
    {
        m_password = password;
    }
    
    void setDomain(std::string domain)
    {
        m_domain = domain;
    }

    std::string& getUsername() {
        return m_username;
    }

    std::string getPassword() {
        return m_password;
    }
    
    std::string getDomain()
    {
        return m_domain;
    }
    
    bool validate(std::string username, std:string password)
    {
        return m_username == username && m_password == password;
    }

    void print() const
    {
        std::cout<<getEmail()<<std::endl;
    }
    
    std::string getInfo() const
    {
        return getEmail();
    }
};