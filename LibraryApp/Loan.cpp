#include "Loan.h"
#include "Book.h"
#include "Reader.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <windows.h> // ��� ��������� ������� � Windows

std::vector<Loan> loans;

void loadLoans() {
    SetConsoleOutputCP(1251); // ���������� Windows-1251 ��� ������
    SetConsoleCP(1251);       // ���������� Windows-1251 ��� �����
    setlocale(LC_ALL, "Russian"); // ���������� ������ Russian (Windows-1251)
    loans.clear();

    std::ifstream fin("loans.txt");
    if (!fin.is_open()) {
        std::cerr << "���� loans.txt �� ������, �� ����� ������ ��� ����������.\n";
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
        std::cerr << "������ ��� ��������/�������� ����� loans.txt. ���������, ��� ����� data ����������.\n";
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
    std::cout << "������� ID �����: "; std::cin >> l.bookId;
    std::cout << "������� ID ��������: "; std::cin >> l.readerId;
    std::cout << "���� ������ (��-��-����): "; std::cin >> l.dateIssued;
    std::cout << "���� ��������: "; std::cin >> l.dateDue;
    l.dateReturned = "���";
    loans.push_back(l);
    saveLoans();
    std::cout << "����� ������.\n";
}

void returnBook() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    int bookId, readerId;
    std::cout << "������� ID �����: "; std::cin >> bookId;
    std::cout << "������� ID ��������: "; std::cin >> readerId;
    bool found = false;
    for (auto& l : loans) {
        if (l.bookId == bookId && l.readerId == readerId && l.dateReturned == "���") {
            std::cout << "������� ���� �������� (��-��-����): ";
            std::cin >> l.dateReturned;
            std::cout << "������� ������� ���������������.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "������ � ������ ����� �� ������� ��� ����� ��� ����������.\n";
    }
    saveLoans();
}

void listLoans() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    std::cout << "\n������ �������� ����:\n";
    std::cout << "------------------------------------------------------------\n";
    for (auto& l : loans) {
        std::cout << "ID �����: " << l.bookId << "\nID ��������: " << l.readerId
            << "\n���� ������: " << l.dateIssued
            << "\n���� ��: " << l.dateDue
            << "\n���� ��������: " << l.dateReturned << "\n";
        std::cout << "------------------------------------------------------------\n";
    }
}