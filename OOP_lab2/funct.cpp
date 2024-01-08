#include "Header.h"

vector<shared_ptr<File>> allFiles;
vector<shared_ptr<User>> allUsers;

void CreateUserPrompt() {
    cout << "Введите имя пользователя: \n";
    string name;
    getline(cin, name);
    allUsers.push_back(make_shared<User>(name));
}

void CreateFilePrompt() {
    cout << "Введите имя файла:\n";
    string name;
    getline(cin, name);
    cout << "Введите формат файла:\n";
    string format;
    getline(cin, format);

    auto file = make_shared<File>(name, format);
    file->askForContent();
    allFiles.push_back(file);
}

void printFiles() {
    cout << left << setw(15) << "Имя файла"
        << left << setw(15) << "Формат файла"
        << left << setw(30) << "Содержание файла" << endl;

    for (const auto& file : allFiles) {
        cout << left << setw(15) << file->getName()
            << left << setw(15) << file->getFormat()
            << left << setw(30) << file->getContent() << endl;
    }
}

void ConvertFilePrompt() {
    cout << "Введите имя файла для конвертации:\n";
    string name;
    getline(cin, name);

    auto it = find_if(allFiles.begin(), allFiles.end(), [&](const shared_ptr<File>& file) { return file->getName() == name; });
    if (it == allFiles.end()) {
        cout << "Файл с именем " << name << " не найден.\n";
        return;
    }
    cout << "Введите исходный формат:\n";
    string sourceFormat;
    getline(cin, sourceFormat);

    cout << "Введите формат, в который хотите конвертировать:\n";
    string destinationFormat;
    getline(cin, destinationFormat);

    FormatConverter converter(sourceFormat, destinationFormat);
    converter.convert(*it);

    cout << "Конвертация завершена.\n";
}

void EditFilePrompt() {
    cout << "Введите имя файла для редактирования:\n";
    string name;
    getline(cin, name);

    auto it = find_if(allFiles.begin(), allFiles.end(), [&](const shared_ptr<File>& file) { return file->getName() == name; });
    if (it == allFiles.end()) {
        cout << "Файл с именем " << name << " не найден.\n";
        return;
    }

    cout << "Введите новое содержимое файла:\n";
    string newContent;
    getline(cin, newContent);

    (*it)->editContent(newContent);

    cout << "Содержимое файла обновлено.\n";
}

int isnumber() {
    int n;
    while (1) {
        while (!(cin >> n)) {
            cin.clear();
            cin.ignore(1024, '\n');   cout << "Неверный ввод. Попробуйте снова! " << endl;
        }  if (cin.get() != '\n') {
            cout << "Неверный ввод. Попробуйте снова! " << endl;   cin.clear();
            cin.ignore(1025, '\n');   continue;
        }
        if (n < 0 || n > 5) {
            cout << "Неверный ввод. Попробуйте снова! " << endl;
            continue;
        }
        else break;
    }
    return n;
}
