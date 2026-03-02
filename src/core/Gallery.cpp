#include "Gallery.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm> // Required for case-insensitive comparison

// Helper function for case-insensitive string comparison
bool caseInsensitiveCompare(const std::string& str1, const std::string& str2) {
    return std::equal(str1.begin(), str1.end(),
                      str2.begin(), str2.end(),
                      [](char a, char b) {
                          return tolower(a) == tolower(b);
                      });
}


Gallery::Gallery(const std::string& name) : name(name) {}

// ... (keep the existing load and display functions as they are) ...
void Gallery::loadArtworks(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open artwork file: " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string title, artist, year_str;
        std::getline(ss, title, ',');
        std::getline(ss, artist, ',');
        std::getline(ss, year_str, ',');
        try {
            int year = std::stoi(year_str);
            artworks.emplace_back(title, artist, year);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid year format in artworks.txt: " << year_str << std::endl;
        }
    }
    file.close();
}

void Gallery::loadArtists(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open artist file: " << filename << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, biography;
        std::getline(ss, name, '|');
        std::getline(ss, biography, '|');
        artists.emplace_back(name, biography);
    }
    file.close();
}

void Gallery::loadExhibitions(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open exhibition file: " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, description;
        std::getline(ss, name, ',');
        std::getline(ss, description, ',');
        exhibitions.emplace_back(name, description);
    }
    file.close();
}

void Gallery::displayArtworks() const {
    for (const auto& artwork : artworks) {
        artwork.display();
    }
}

void Gallery::displayArtists() const {
    for (const auto& artist : artists) {
        artist.display();
        std::cout << std::endl;
    }
}

void Gallery::displayExhibitions() const {
    for (const auto& exhibition : exhibitions) {
        exhibition.display();
        std::cout << std::endl;
    }
}


// New function implementations
void Gallery::findArtworkByTitle(const std::string& title) const {
    bool found = false;
    for (const auto& artwork : artworks) {
        if (caseInsensitiveCompare(artwork.getTitle(), title)) {
            std::cout << "Found artwork:" << std::endl;
            artwork.display();
            found = true;
            break; 
        }
    }
    if (!found) {
        std::cout << "Artwork with title '" << title << "' not found." << std::endl;
    }
}

void Gallery::findArtistByName(const std::string& name) const {
    bool found = false;
    for (const auto& artist : artists) {
        if (caseInsensitiveCompare(artist.getName(), name)) {
            std::cout << "Found artist:" << std::endl;
            artist.display();
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Artist with name '" << name << "' not found." << std::endl;
    }
}


const std::string& Gallery::getName() const {
    return name;
}

const std::vector<Artwork>& Gallery::getArtworks() const {
    return artworks;
}
