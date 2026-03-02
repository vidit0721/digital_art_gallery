#include "Artist.h"
#include <iostream>

Artist::Artist(const std::string& name, const std::string& biography)
    : name(name), biography(biography) {}

void Artist::display() const {
    std::cout << "Name: " << name << "\nBiography: " << biography << std::endl;
}

std::string Artist::getName() const {
    return name;
}
