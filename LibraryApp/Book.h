#pragma once
#pragma once
#include <string>
#include <locale>

struct Book {
   
    int id;
    std::string title;
    std::string author;
    int year;
    std::string isbn;
    std::string publisher;
    std::string genre;
    int totalCopies;
    int availableCopies;
};

void addBook();
void listBooks();
void saveBooks();
void loadBooks();
