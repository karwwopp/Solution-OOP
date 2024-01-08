#pragma once
#include "Classes.h"

void TermFunc() {
    system("cls");
    cout << "������, ��� �� ����� ������������ ��������." << endl;
    cout << "������� TermFunc() ������� �������� terminate().\n����� ��������� ���������\n";
    exit(-1);
}

int Menu() {
    int choice = 0;
    do {
        system("cls");
        cout << "1)�������� ��������\n";
        cout << "2)�������� ����������\n";
        cout << "3)����������� ���������\n";
        cout << "4)����������� ��������������\n";
        cout << "5)����������� ������\n";
        cout << "6)������� ��������\n";
        cout << "7)��������������� ��������\n";
        cout << "8)������������� ���������\n";
        cout << "9)����� ��������� �� ��������� ������\n";
        cout << "10)������� ������ �� �����\n";
        cout << "11)������ ������ � ����\n";
        cout << "12)����� �������� �� ����� � �����\n";
        cout << "0)�����\n";
        cout << "������� ��� �����: ";
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
            cout << "������ �����.";
            cin.ignore(1024, '\n');
            system("pause");
        }
        catch (int) {
            cout << "�� ����� ������������ �����.";
            system("pause");
        }
        catch (...) {
            system("cls");
            cout << "���-�� ����� �� ���. ���������� ��� ���";
            system("pause");
        }
    } while (choice < 0 || choice > 12);
    return choice;
}
