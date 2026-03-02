#ifndef GALLERY_H
#define GALLERY_H

#include <string>
#include <vector>
#include "Artwork.h"
#include "Artist.h"
#include "Exhibition.h"

class Gallery {
public:
    Gallery(const std::string& name);

    void loadArtworks(const std::string& filename);
    void loadArtists(const std::string& filename);
    void loadExhibitions(const std::string& filename);

    void displayArtworks() const;
    void displayArtists() const;
    void displayExhibitions() const;

    // New search functions
    void findArtworkByTitle(const std::string& title) const;
    void findArtistByName(const std::string& name) const;

    const std::string& getName() const;
    const std::vector<Artwork>& getArtworks() const;

private:
    std::string name;
    std::vector<Artwork> artworks;
    std::vector<Artist> artists;
    std::vector<Exhibition> exhibitions;
};

#endif // GALLERY_H
