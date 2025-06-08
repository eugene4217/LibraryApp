#include "Book.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <windows.h> // ��� ��������� ������� � Windows

std::vector<Book> books;

void loadBooks() {
    SetConsoleOutputCP(1251); // ���������� Windows-1251 ��� ������
    SetConsoleCP(1251);       // ���������� Windows-1251 ��� �����
    setlocale(LC_ALL, "Russian"); // ���������� ������ Russian (Windows-1251)
    books.clear();

    std::ifstream fin("data/books.txt");
    if (!fin.is_open()) {
        std::cerr << "���� data/books.txt �� ������, �� ����� ������ ��� ����������.\n";
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
        std::cerr << "������ ��� ��������/�������� ����� data/books.txt. ���������, ��� ����� data ����������.\n";
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
    std::cout << "������� ID �����: "; std::cin >> b.id; std::cin.ignore();
    std::cout << "��������: "; std::getline(std::cin, b.title);
    std::cout << "�����: "; std::getline(std::cin, b.author);
    std::cout << "��� �������: "; std::cin >> b.year; std::cin.ignore();
    std::cout << "ISBN: "; std::cin >> b.isbn; std::cin.ignore();
    std::cout << "������������: "; std::getline(std::cin, b.publisher);
    std::cout << "����: "; std::getline(std::cin, b.genre);
    std::cout << "���������� �����������: "; std::cin >> b.totalCopies;
    b.availableCopies = b.totalCopies;
    books.push_back(b);
    saveBooks();
    std::cout << "����� ������� ���������!\n";
}

void listBooks() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    std::cout << "\n������ ����:\n";
    std::cout << "------------------------------------------------------------\n";
    for (auto& b : books) {
        std::cout << "ID: " << b.id << "\n��������: " << b.title
            << "\n�����: " << b.author << "\n���: " << b.year
            << "\nISBN: " << b.isbn << "\n������������: " << b.publisher
            << "\n����: " << b.genre
            << "\n��������: " << b.availableCopies << " �� " << b.totalCopies << "\n";
        std::cout << "------------------------------------------------------------\n";
    }
}