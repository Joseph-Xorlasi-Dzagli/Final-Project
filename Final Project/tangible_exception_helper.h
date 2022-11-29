#pragma once

#include <string>
#include <exception>

class NumberFormatException : public std::exception
{
private:
    std::string msg;

public:
    NumberFormatException(const std::string &message = "") : msg(message)
    {
    }

    const char * what() const noexcept
    {
        return msg.c_str();
    }
};
