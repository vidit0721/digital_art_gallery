#include "Exhibition.h"
#include <iostream>

Exhibition::Exhibition(const std::string& name, const std::string& description)
    : name(name), description(description) {}

void Exhibition::addArtwork(const Artwork& artwork) {
    artworks.push_back(artwork);
}

void Exhibition::display() const {
    std::cout << "Exhibition: " << name << "\nDescription: " << description << std::endl;
    std::cout << "Artworks in this exhibition:" << std::endl;
    for (const auto& artwork : artworks) {
        std::cout << "- ";
        artwork.display();
    }
}
