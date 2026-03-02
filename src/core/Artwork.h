#ifndef ARTWORK_H
#define ARTWORK_H

#include <string>

class Artwork {
public:
    Artwork(const std::string& title, const std::string& artist, int year);

    void display() const;
    std::string getTitle() const;
    std::string getArtist() const;
    int getYear() const;


private:
    std::string title;
    std::string artist;
    int year;
};

#endif // ARTWORK_H
