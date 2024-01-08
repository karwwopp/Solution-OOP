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
        cout << "�������: \n1. �������� ������������; \n2. �������� ����; \n3. ������������� ���������� ����� \n4. �������������� ���� \n5. ������� �����; \n0. �����.\n";
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
            cout << "��������� ���������.";
            continueInput = false;
            break;
        default:
            cout << "�������� �����.\n";
            break;
        }
    }
    return 0;
}

