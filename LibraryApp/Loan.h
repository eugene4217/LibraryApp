#pragma once
#include <string>

struct Loan {
    int bookId;
    int readerId;
    std::string dateIssued;
    std::string dateDue;
    std::string dateReturned;
};

void issueBook();
void returnBook();
void listLoans();
void loadLoans();
void saveLoans();
