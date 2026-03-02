#include <iostream>
#include <limits>
#include "core/Gallery.h"

void displayMenu() {
    std::cout << "\n--- Digital Art Gallery Menu ---\n";
    std::cout << "1. Display all artworks\n";
    std::cout << "2. Display all artists\n";
    std::cout << "3. Display all exhibitions\n";
    std::cout << "4. Search for an artwork by title\n";
    std::cout << "5. Search for an artist by name\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Gallery gallery("My Digital Art Gallery");
    gallery.loadArtworks("data/artworks.txt");
    gallery.loadArtists("data/artists.dat");
    gallery.loadExhibitions("data/exhibitions.txt");

    std::cout << "Welcome to " << gallery.getName() << "!" << std::endl;

    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Clear the rest of the line after reading the number
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        
        switch (choice) {
            case 1:
                std::cout << "\n--- All Artworks ---\n";
                gallery.displayArtworks();
                break;
            case 2:
                std::cout << "\n--- All Artists ---\n";
                gallery.displayArtists();
                break;
            case 3:
                std::cout << "\n--- All Exhibitions ---\n";
                gallery.displayExhibitions();
                break;
            case 4: {
                std::string title;
                std::cout << "Enter artwork title to search for: ";
                std::getline(std::cin, title);
                gallery.findArtworkByTitle(title);
                break;
            }
            case 5: {
                std::string name;
                std::cout << "Enter artist name to search for: ";
                std::getline(std::cin, name);
                gallery.findArtistByName(name);
                break;
            }
            case 6:
                std::cout << "Exiting the gallery. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}

