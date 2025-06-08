#include "Book.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <windows.h> // Для настройки консоли в Windows

std::vector<Book> books;

void loadBooks() {
    SetConsoleOutputCP(1251); // Установить Windows-1251 для вывода
    SetConsoleCP(1251);       // Установить Windows-1251 для ввода
    setlocale(LC_ALL, "Russian"); // Установить локаль Russian (Windows-1251)
    books.clear();

    std::ifstream fin("data/books.txt");
    if (!fin.is_open()) {
        std::cerr << "Файл data/books.txt не найден, он будет создан при сохранении.\n";
        return;
    }

    Book b;
    while (fin >> b.id >> std::ws && std::getline(fin, b.title) &&
        std::getline(fin, b.author) && fin >> b.year >> b.isbn >> b.publisher >>
        b.genre >> b.totalCopies >> b.availableCopies) {
        books.push_back(b);
    }
    fin.close();
}

void saveBooks() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    std::ofstream fout("data/books.txt");
    if (!fout.is_open()) {
        std::cerr << "Ошибка при создании/открытии файла data/books.txt. Убедитесь, что папка data существует.\n";
        return;
    }

    for (auto& b : books) {
        fout << b.id << "\n" << b.title << "\n" << b.author << "\n"
            << b.year << "\n" << b.isbn << "\n" << b.publisher << "\n"
            << b.genre << "\n" << b.totalCopies << " " << b.availableCopies << "\n";
    }
    fout.close();
}

void addBook() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    Book b;
    std::cout << "Введите ID книги: "; std::cin >> b.id; std::cin.ignore();
    std::cout << "Название: "; std::getline(std::cin, b.title);
    std::cout << "Автор: "; std::getline(std::cin, b.author);
    std::cout << "Год издания: "; std::cin >> b.year; std::cin.ignore();
    std::cout << "ISBN: "; std::cin >> b.isbn; std::cin.ignore();
    std::cout << "Издательство: "; std::getline(std::cin, b.publisher);
    std::cout << "Жанр: "; std::getline(std::cin, b.genre);
    std::cout << "Количество экземпляров: "; std::cin >> b.totalCopies;
    b.availableCopies = b.totalCopies;
    books.push_back(b);
    saveBooks();
    std::cout << "Книга успешно добавлена!\n";
}

void listBooks() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    std::cout << "\nСписок книг:\n";
    std::cout << "------------------------------------------------------------\n";
    for (auto& b : books) {
        std::cout << "ID: " << b.id << "\nНазвание: " << b.title
            << "\nАвтор: " << b.author << "\nГод: " << b.year
            << "\nISBN: " << b.isbn << "\nИздательство: " << b.publisher
            << "\nЖанр: " << b.genre
            << "\nДоступно: " << b.availableCopies << " из " << b.totalCopies << "\n";
        std::cout << "------------------------------------------------------------\n";
    }
}