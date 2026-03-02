#include "Artwork.h"
#include <iostream>

Artwork::Artwork(const std::string& title, const std::string& artist, int year)
    : title(title), artist(artist), year(year) {}

void Artwork::display() const {
    std::cout << "Title: " << title << ", Artist: " << artist << ", Year: " << year << std::endl;
}

std::string Artwork::getTitle() const {
    return title;
}

std::string Artwork::getArtist() const {
    return artist;
}

int Artwork::getYear() const {
    return year;
}
