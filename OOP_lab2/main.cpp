#include "Header.h"

int isnumber();
void CreateUserPrompt();
void CreateFilePrompt();
void EditFilePrompt();
void ConvertFilePrompt();
void printFiles();
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool continueInput = true;
    while (continueInput) {
        cout << "Введите: \n1. добавить пользователя; \n2. добавить файл; \n3. редактировать содержимое файла \n4. конвертировать файл \n5. вывести файлы; \n0. выйти.\n";
        int choice;
        choice = isnumber();
        switch (choice) {
        case 1:
            CreateUserPrompt();
            break;
        case 2:
            CreateFilePrompt();
            break;
        case 3:
            EditFilePrompt();
            break;
        case 4:
            ConvertFilePrompt();
            break;
        case 5:
            printFiles();
            break;
        case 0:
            cout << "Программа завершена.";
            continueInput = false;
            break;
        default:
            cout << "Неверный выбор.\n";
            break;
        }
    }
    return 0;
}

