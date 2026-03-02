#ifndef VIRTUALEXHIBITION_H
#define VIRTUALEXHIBITION_H

#include "../core/Artwork.h"
#include <vector>

class VirtualExhibition {
public:
    void start(const std::vector<Artwork>& artworks);
};

#endif // VIRTUALEXHIBITION_H
