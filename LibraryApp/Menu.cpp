#include "Book.h"
#include "Reader.h"
#include "Loan.h"
#include <iostream>
#include <locale>
#include <windows.h>

void showMainMenu() {

    setlocale(LC_ALL, "Russian");
    loadBooks();
    loadReaders();
    loadLoans();

    int choice;
    do {
        std::cout << "\n=== БИБЛИОТЕЧНАЯ СИСТЕМА ===\n";
        std::cout << "1. Добавить книгу\n";
        std::cout << "2. Список книг\n";
        std::cout << "3. Добавить читателя\n";
        std::cout << "4. Список читателей\n";
        std::cout << "5. Выдать книгу\n";
        std::cout << "6. Вернуть книгу\n";
        std::cout << "7. Список выдач\n";
        std::cout << "0. Выход\n> ";
        std::cin >> choice;

        switch (choice) {
        case 1: addBook(); break;
        case 2: listBooks(); break;
        case 3: addReader(); break;
        case 4: listReaders(); break;
        case 5: issueBook(); break;
        case 6: returnBook(); break;
        case 7: listLoans(); break;
        case 0: std::cout << "Выход...\n"; break;
        default: std::cout << "Неверный пункт меню.\n";
        }
    } while (choice != 0);
}
