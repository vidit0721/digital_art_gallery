#ifndef ARTIST_H
#define ARTIST_H

#include <string>

class Artist {
public:
    Artist(const std::string& name, const std::string& biography);

    void display() const;
    std::string getName() const;

private:
    std::string name;
    std::string biography;
};

#endif // ARTIST_H
