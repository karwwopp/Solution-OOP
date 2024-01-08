#include "Classes.h"

int main() {
    set_terminate(TermFunc);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector <Person*> all_persons;
    vector <Student> students;
    vector <Professor> professors;
    vector <Group> groups;
    string name;
    int age;
    int studentID;
    int group;
    string choice;
    string post;
    float salary;
    Person* new_person;
    Student new_student;
    Professor new_professor;
    Group new_group;
    bool is_found = 0;
    while (1) {
        switch (Menu()) {
        case 1:
            system("cls");
            is_found = 0;
            cout << "������� ��� ��������: ";
            getchar();
            getline(cin, name);
            cout << "������� ������� ��������: ";
            cin >> age;
            cout << "������� ����� ������������� ������: ";
            while (1) {
                try {
                    cin >> studentID;
                    if (studentID < 10000000 || studentID > 99999999) {
                        throw UniversityException();
                    }
                    else {
                        break;
                    }
                }
                catch (UniversityException& ex) {
                    cout << ex.what();
                }
                catch (exception& ex) {
                    cout << ex.what() << endl;
                }
                cout << "\n������� ����� ������������� ������: ";
            }
            cout << "������� ����� ������: ";
            cin >> group;
            try {
                while (true) {
                    cout << "�������� �� �������(��/���): ";
                    cin >> choice;
                    if (choice == "���" || choice == "��") {
                        break;
                    }
                    else if (choice != "��") {
                        throw 1;
                    }
                }
            }
            catch (exception& ex) {
                cout << "����������: " << ex.what() << endl;
            }
            catch (...) {
                cout << "������ ���������� � �������������� ����������." << endl;
            }
            if (choice == "��") {
                cout << "������� ��������� ��������: ";
                getchar();
                getline(cin, post);
                cout << "������� �������� ��������: ";
                try {
                    cin >> salary;
                }
                catch (exception& ex) {
                    cout << "����������" << ex.what() << endl;
                }
                new_student.set_studentworker(name, age, studentID, post, salary);
            }
            else
                new_student.set_student(name, age, studentID);
            try {
                new_person = new Student(name, age, studentID);
            }
            catch (bad_alloc& ex) {
                cout << "������ ��������� ������\n";
            }
            all_persons.push_back(new_person);
            for (int i = 0; i < groups.size(); i++) {
                if (groups[i].get_code() == group) {
                    groups[i].addStudent(new_student);
                    is_found = 1;
                    break;
                }
            }
            if (!is_found) {
                new_group.addCode(group);
                groups.push_back(new_group);
                groups[groups.size() - 1].addStudent(new_student);
            }
            students.push_back(new_student);
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "������� ��� �������������: ";
            getchar();
            getline(cin, name);
            cout << "������� ������� �������������: ";
            try {
                cin >> age;
            }
            catch (exception& ex) {
                cout << "����������: " << ex.what() << endl;
            }
            cout << "������� ��������� �������������: ";
            getchar();
            getline(cin, post);
            cout << "������� �������� �������������: ";
            try {
                cin >> salary;
            }
            catch (exception& ex) {
                cout << "����������" << ex.what() << endl;
            }
            new_person = new Professor(name,age,post,salary);
            new_professor.setProfessor(name, age, post, salary);
            while (true) {
                is_found = 0;
                cout << "������� ������ � ������� �������� �������������: ";
                try {
                    cin >> group;
                }
                catch (exception& ex) {
                    cout << "����������: " << ex.what() << endl;
                }
                for (int i = 0; i < groups.size(); i++) {
                    if (groups[i].get_code() == group) {
                        groups[i].addProfessor(new_professor);
                        is_found = 1;
                        break;
                    }
                }
                if (!is_found) {
                    new_group.addCode(group);
                    groups.push_back(new_group);
                    groups[groups.size() - 1].addProfessor(new_professor);
                }
                cout << "������� ����������(��/���): ";
                try {
                    cin >> choice;
                    if (choice == "���") {
                        break;
                    }
                    else if (choice != "��") {
                        throw 1;
                    }
                }
                catch (exception& ex) {
                    cout << "����������: " << ex.what() << endl;
                }
                catch (...) {
                    cout << "������ �������������� ����������";
                }
            }
            professors.push_back(new_professor);
            break;
        case 3:
            system("cls");
            if (students.size() == 0) {
                cout << "��� ��������� � ����\n";
                system("pause");
                break;
            }
            for (int i = 0; i < students.size(); i++) {
                students[i].displayInfo();
                cout << "\n";
            }
            system("pause");
            break;
        case 4:
            system("cls");
            if (professors.size() == 0) {
                cout << "��� �������������� � ����\n";
                system("pause");
                break;
            }
            for (int i = 0; i < professors.size(); i++) {
                professors[i].displayInfo();
            }
            system("pause");
            break;
        case 5:
            system("cls");
            if (groups.size() == 0) {
                cout << "��� ����� � ����\n";
                system("pause");
                break;
            }
            for (int i = 0; i < groups.size(); i++) {
                groups[i].displayInfo();
                system("pause");
            }
            break;
        case 0: return 0;
        }
    }
    return 0;
}