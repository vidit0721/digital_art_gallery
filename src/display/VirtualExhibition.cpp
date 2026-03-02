#include "VirtualExhibition.h"
#include <iostream>

void VirtualExhibition::start(const std::vector<Artwork>& artworks) {
    std::cout << "Starting virtual exhibition..." << std::endl;
    for (const auto& artwork : artworks) {
        artwork.display();
    }
}
