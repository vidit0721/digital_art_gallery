#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

class CustomException : public std::exception {
public:
    CustomException(const std::string& message);
    virtual const char* what() const throw();

private:
    std::string message;
};

#endif // EXCEPTION_H
