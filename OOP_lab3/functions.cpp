#pragma once
#include "Classes.h"

void TermFunc() {
    system("cls");
    cout << "Похоже, что вы ввели некорректное значение." << endl;
    cout << "Функция TermFunc() вызвана функцией terminate().\nРабта программы завершена\n";
    exit(-1);
}

int Menu() {
    int choice = 0;
    do {
        system("cls");
        cout << "1)Добавить студента\n";
        cout << "2)Добавить профессора\n";
        cout << "3)Просмотреть студентов\n";
        cout << "4)Просмотреть преподователей\n";
        cout << "5)Просмотреть группы\n";
        cout << "0)Выход\n";
        cout << "Введите ваш выбор: ";
        try {
            cin >> choice;
            if (choice < 0 || choice > 5) {
                throw 1;
            }
        }
        catch (exception& ex) {
            cout << ex.what() << endl;
            system("pause");
        }
        catch (int) {
            cout << "Вы ввели неправильное число.";
            system("pause");
        }
        catch (...) {
            system("cls");
            cout << "Что-то пошло не так. Попробуйте еще раз";
            system("pause");
        }
    } while (choice < 0 || choice > 5);
    return choice;
}