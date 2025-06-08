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
        std::cout << "\n=== ������������ ������� ===\n";
        std::cout << "1. �������� �����\n";
        std::cout << "2. ������ ����\n";
        std::cout << "3. �������� ��������\n";
        std::cout << "4. ������ ���������\n";
        std::cout << "5. ������ �����\n";
        std::cout << "6. ������� �����\n";
        std::cout << "7. ������ �����\n";
        std::cout << "0. �����\n> ";
        std::cin >> choice;

        switch (choice) {
        case 1: addBook(); break;
        case 2: listBooks(); break;
        case 3: addReader(); break;
        case 4: listReaders(); break;
        case 5: issueBook(); break;
        case 6: returnBook(); break;
        case 7: listLoans(); break;
        case 0: std::cout << "�����...\n"; break;
        default: std::cout << "�������� ����� ����.\n";
        }
    } while (choice != 0);
}
