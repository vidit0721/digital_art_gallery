#include "Exception.h"

CustomException::CustomException(const std::string& message) : message(message) {}

const char* CustomException::what() const throw() {
    return message.c_str();
}
