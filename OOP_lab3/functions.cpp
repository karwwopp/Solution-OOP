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
        cout << "0)�����\n";
        cout << "������� ��� �����: ";
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
            cout << "�� ����� ������������ �����.";
            system("pause");
        }
        catch (...) {
            system("cls");
            cout << "���-�� ����� �� ���. ���������� ��� ���";
            system("pause");
        }
    } while (choice < 0 || choice > 5);
    return choice;
}