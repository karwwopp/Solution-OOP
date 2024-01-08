#pragma once
#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include<Windows.h>
using namespace std;

class File {
private:
    string name;
    string format;
    string directory = "/path/to/directory";
    string content;

public:
    File(const string& name, const string& format)
        : name(name), format(format), directory(directory), content("") {}

    string getName() const { return name; }
    string getFormat() const { return format; }
    string getDirectory() const { return directory; }
    string getContent() const { return content; }
    void setContent(const string& newContent) { content = newContent; }

    void askForContent() {
        cout << "Введите содержание файла " << name << ":\n";
        getline(cin, content);
    }

    void save() {
        cout << "Сохранение файла " << name << " в формате " << format << " в директорий " << directory << endl;
    }

    void editContent(const string& newContent) {
        content = newContent;
        cout << "Содержимое файла " << name << " отредактировано." << endl;
    }

    void rollback() {
        cout << "Откат изменений для файла " << name << endl;
    }

};

class User {
private:
    string name;

public:
    User(const string& name) : name(name) {}

    string getName() const { return name; }
    void setName(const string& newName) { name = newName; }
};

class FormatConverter {
private:
    string sourceFormat;
    string destinationFormat;

public:
    FormatConverter(const string& sourceFormat, const string& destinationFormat)
        : sourceFormat(sourceFormat), destinationFormat(destinationFormat) {}

    string getSourceFormat() const { return sourceFormat; }
    string getDestinationFormat() const { return destinationFormat; }
    void setSourceFormat(const string& newSourceFormat) { sourceFormat = newSourceFormat; }
    void setDestinationFormat(const string& newDestinationFormat) { destinationFormat = newDestinationFormat; }

    template<typename T>
    void convert(const shared_ptr<T>& file) {
        cout << "Преобразование файла " << file->getName() << " из формата " << sourceFormat
            << " в формат " << destinationFormat << endl;
    }
};

class Transaction {
private:
    int fileId;
    int userId;
    bool success;

public:
    Transaction(int fileId, int userId, bool success)
        : fileId(fileId), userId(userId), success(success) {}

    int getFileId() const { return fileId; }
    int getUserId() const { return userId; }
    bool isSuccess() const { return success; }
};

class TransactionManager {
private:
    vector<shared_ptr<Transaction>> transactions;

public:
    void addTransaction(const shared_ptr<Transaction>& transaction) {
        transactions.push_back(transaction);
    }

    void rollbackLastTransaction() {
        if (!transactions.empty()) {
            shared_ptr<Transaction> lastTransaction = transactions.back();
            transactions.pop_back();

            if (lastTransaction->isSuccess()) {
                cout << "Откат изменений для файла с ID " << lastTransaction->getFileId() << endl;
            }
        }
    }
};

