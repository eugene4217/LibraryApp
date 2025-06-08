#include "Reader.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <windows.h> // Для настройки консоли в Windows

std::vector<Reader> readers;

void loadReaders() {
    SetConsoleOutputCP(1251); // Установить Windows-1251 для вывода
    SetConsoleCP(1251);       // Установить Windows-1251 для ввода
    setlocale(LC_ALL, "Russian"); // Установить локаль Russian (Windows-1251)
    readers.clear();

    std::ifstream fin("data/readers.txt");
    if (!fin.is_open()) {
        std::cerr << "Файл data/readers.txt не найден, он будет создан при сохранении.\n";
        return;
    }

    Reader r;
    while (fin >> r.id >> std::ws && std::getline(fin, r.name) &&
        std::getline(fin, r.address) &&
        fin >> r.phone >> r.email) {
        readers.push_back(r);
    }
    fin.close();
}

void saveReaders() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    std::ofstream fout("data/readers.txt");
    if (!fout.is_open()) {
        std::cerr << "Ошибка при создании/открытии файла data/readers.txt. Убедитесь, что папка data существует.\n";
        return;
    }

    for (auto& r : readers) {
        fout << r.id << "\n" << r.name << "\n" << r.address << "\n"
            << r.phone << " " << r.email << "\n";
    }
    fout.close();
}

void addReader() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    Reader r;
    std::cout << "Введите ID читателя: "; std::cin >> r.id; std::cin.ignore();
    std::cout << "ФИО: "; std::getline(std::cin, r.name);
    std::cout << "Адрес: "; std::getline(std::cin, r.address);
    std::cout << "Телефон: "; std::cin >> r.phone;
    std::cout << "Email: "; std::cin >> r.email;
    readers.push_back(r);
    saveReaders();
    std::cout << "Читатель успешно добавлен!\n";
}

void listReaders() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    std::cout << "\nСписок читателей:\n";
    std::cout << "------------------------------------------------------------\n";
    for (auto& r : readers) {
        std::cout << "ID: " << r.id << "\nФИО: " << r.name
            << "\nАдрес: " << r.address << "\nТелефон: " << r.phone
            << "\nEmail: " << r.email << "\n";
        std::cout << "------------------------------------------------------------\n";
    }
}

