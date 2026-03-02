#ifndef EXHIBITION_H
#define EXHIBITION_H

#include <string>
#include <vector>
#include "Artwork.h"

class Exhibition {
public:
    Exhibition(const std::string& name, const std::string& description);

    void addArtwork(const Artwork& artwork);
    void display() const;

private:
    std::string name;
    std::string description;
    std::vector<Artwork> artworks;
};

#endif // EXHIBITION_H
