#include "Loan.h"
#include "Book.h"
#include "Reader.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <windows.h> // Для настройки консоли в Windows

std::vector<Loan> loans;

void loadLoans() {
    SetConsoleOutputCP(1251); // Установить Windows-1251 для вывода
    SetConsoleCP(1251);       // Установить Windows-1251 для ввода
    setlocale(LC_ALL, "Russian"); // Установить локаль Russian (Windows-1251)
    loans.clear();

    std::ifstream fin("loans.txt");
    if (!fin.is_open()) {
        std::cerr << "Файл loans.txt не найден, он будет создан при сохранении.\n";
        return;
    }

    Loan l;
    while (fin >> l.bookId >> l.readerId >> l.dateIssued >> l.dateDue >> l.dateReturned) {
        loans.push_back(l);
    }
    fin.close();
}

void saveLoans() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    std::ofstream fout("loans.txt");
    if (!fout.is_open()) {
        std::cerr << "Ошибка при создании/открытии файла loans.txt. Убедитесь, что папка data существует.\n";
        return;
    }

    for (auto& l : loans) {
        fout << l.bookId << " " << l.readerId << " "
            << l.dateIssued << " " << l.dateDue << " " << l.dateReturned << "\n";
    }
    fout.close();
}

void issueBook() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    Loan l;
    std::cout << "Введите ID книги: "; std::cin >> l.bookId;
    std::cout << "Введите ID читателя: "; std::cin >> l.readerId;
    std::cout << "Дата выдачи (ДД-ММ-ГГГГ): "; std::cin >> l.dateIssued;
    std::cout << "Дата возврата: "; std::cin >> l.dateDue;
    l.dateReturned = "нет";
    loans.push_back(l);
    saveLoans();
    std::cout << "Книга выдана.\n";
}

void returnBook() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    int bookId, readerId;
    std::cout << "Введите ID книги: "; std::cin >> bookId;
    std::cout << "Введите ID читателя: "; std::cin >> readerId;
    bool found = false;
    for (auto& l : loans) {
        if (l.bookId == bookId && l.readerId == readerId && l.dateReturned == "нет") {
            std::cout << "Введите дату возврата (ДД-ММ-ГГГГ): ";
            std::cin >> l.dateReturned;
            std::cout << "Возврат успешно зарегистрирован.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Запись о выдаче книги не найдена или книга уже возвращена.\n";
    }
    saveLoans();
}

void listLoans() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    std::cout << "\nСписок выданных книг:\n";
    std::cout << "------------------------------------------------------------\n";
    for (auto& l : loans) {
        std::cout << "ID книги: " << l.bookId << "\nID читателя: " << l.readerId
            << "\nДата выдачи: " << l.dateIssued
            << "\nСрок до: " << l.dateDue
            << "\nДата возврата: " << l.dateReturned << "\n";
        std::cout << "------------------------------------------------------------\n";
    }
}