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
        cout << "6)Удалить студента\n";
        cout << "7)Отредактировать студента\n";
        cout << "8)Отсортировать студентов\n";
        cout << "9)Поиск студентов по различным данным\n";
        cout << "10)Считать данные из файла\n";
        cout << "11)Внести данные в файл\n";
        cout << "12)Поиск студента по имени в файле\n";
        cout << "0)Выход\n";
        cout << "Введите ваш выбор: ";
        try {
            cin >> choice;
            if (cin.fail()) {
                throw true;
            }
            if (choice < 0 || choice > 12) {
                throw 12;
            }
        }
        catch (exception& ex) {
            cout << ex.what() << endl;
            system("pause");
        }
        catch (bool) {
            cin.clear();
            cout << "Ошибка ввода.";
            cin.ignore(1024, '\n');
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
    } while (choice < 0 || choice > 12);
    return choice;
}
