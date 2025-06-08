#pragma once
#pragma once
#include <string>

struct Reader {
    int id;
    std::string name;
    std::string address;
    std::string phone;
    std::string email;
};

void addReader();
void listReaders();
void saveReaders();
void loadReaders();
