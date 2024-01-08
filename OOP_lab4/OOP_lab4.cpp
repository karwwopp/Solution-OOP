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
    int change_choice;
    int save_found;
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
            new_person = new Professor(name, age, post, salary);
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
            cout << left << setfill(' ') << setw(15)<< "���" << setw(20) << "�������" << setw(20) << "����� ����. ������" << setw(10) << "16" << setw(10) <<"8" <<endl;
            cout << left << setfill('-') << setw(55) << " " << endl <<setfill(' ');
            for (int i = 0; i < students.size(); i++) {
                students[i].displayInfo();
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
            cout << left << setw(15) << "���" << setw(20) << "�������"<< endl;
            cout << left << setfill('-') << setw(35) << " " << endl << setfill(' ');
            for (int i = 0; i < professors.size(); i++) {
                professors[i].displayInfo();
                cout << endl;
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
        case 6:
            system("cls");
            cout << "������� ����� ����. ������ ������� ������ �������: ";
            cin >> studentID;
            try {
                for (int i = 0; i < students.size(); i++) {
                    if (students[i].getID() == studentID) {
                        students.erase(students.begin() + i);
                        throw 1;
                    }
                }
            }
            catch (int) {
                cout << "������� ������� ������.";
            }
            catch (...) {
                cout << "������� � ����� ����. ������� �� ������";
            }
            system("pause");
            break;
        case 7:
            system("cls");
            cout << "������� ����� ����. ������ ������� ������ ���������������: ";
            cin >> studentID;
            try {
                for (int i = 0; i < students.size(); i++) {
                    if (students[i].getID() == studentID) {
                        save_found = i;
                        throw 1;
                    }
                }
            }
            catch (int) {
                do {
                    system("cls");
                    cout << "������� � ����� ����. ������� ������.";
                    cout << "\n1)�������� ���";
                    cout << "\n2)������� �������";
                    cout << "\n3)�������� ����� ����. ������";
                    cout << "\n0)�����";
                    cout << "\n��� �����: ";
                    try {
                        cin >> change_choice;
                        if (change_choice < 0 || change_choice > 3 || cin.fail()) {
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
                } while (change_choice < 0 || change_choice > 4);
                switch (change_choice) {
                case 1:
                    cout << "������� ����� ��� ��������: ";
                    cin >> name;
                    students[save_found].setname(name);
                    break;
                case 2:
                    cout << "������� ����� ������� ��������: ";
                    cin >> age;
                    students[save_found].setage(age);
                    break;
                case 3:
                    cout << "������� ����� ����� ������������� ������: ";
                    cin >> studentID;
                    students[save_found].setID(studentID);
                    break;
                case 0:
                    break;
                }

            }
            catch (...) {
                cout << "������� � ����� ����. ������� �� ������";
            }
        case 8:
            system("cls");
            do {
                system("cls");
                cout << "\n1)������������� �� �����";
                cout << "\n2)������������� �� ��������";
                cout << "\n3)������������� �� ������ ���� ������ ����� ����. ������";
                cout << "\n0)�����";
                cout << "\n��� �����: ";
                try {
                    cin >> change_choice;
                    if (change_choice < 0 || change_choice > 3 || cin.fail()) {
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
            } while (change_choice < 0 || change_choice > 4);
            switch (change_choice) {
            case 1:
                for (int j = 0; j < students.size(); j++) {
                    for (int i = 0; i < students.size() - 1; i++) {
                        if (students[i].getname() > students[i + 1].getname()) {
                            swap(students[i], students[i + 1]);
                        }
                    }
                }
                break;
            case 2:
                for (int j = 0; j < students.size(); j++) {
                    for (int i = 0; i < students.size() - 1; i++) {
                        if (students[i].getage() > students[i + 1].getage()) {
                            swap(students[i], students[i + 1]);
                        }
                    }
                }
                break;
            case 3:
                for (int j = 0; j < students.size(); j++) {
                    for (int i = 0; i < students.size() - 1; i++) {
                        if (students[i].getID() > students[i + 1].getID()) {
                            swap(students[i], students[i + 1]);
                        }
                    }
                }
                break;
            case 0:
                break;
            }
            system("cls");
            if (students.size() == 0) {
                cout << "��� ��������� � ����\n";
                system("pause");
                break;
            }
            cout << left << setfill(' ') << setw(15) << "���" << setw(20) << "�������" << setw(20) << "����� ����. ������" << setw(10) << "16" << setw(10) << "8" << endl;
            cout << left << setfill('-') << setw(55) << " " << endl << setfill(' ');
            for (int i = 0; i < students.size(); i++) {
                students[i].displayInfo();
            }
            system("pause");
            break;
        case 9:
            system("cls");
            do {
                    cout << "\n1)����� ��������� �� �����";
                    cout << "\n2)����� ��������� �� ��������";
                    cout << "\n3)����� �������� �� ������ ����. ������";
                    cout << "\n0)�����";
                    cout << "\n��� �����: ";
                    try {
                        cin >> change_choice;
                        if (change_choice < 0 || change_choice > 3 || cin.fail()) {
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
                } while (change_choice < 0 || change_choice > 4);
                switch (change_choice) {
                case 1:
                    system("cls");
                    cout << "������� ���: ";
                    try {
                        getchar();
                        getline(cin, name);
                        if (cin.fail()) {
                            throw 1;
                        }
                    }
                    catch (int) {
                        cout << "������ �����.";
                    }
                    catch (...) {
                        cout << "������ �������������� ����������";
                    }
                    cout << left << setfill(' ') << setw(15) << "���" << setw(20) << "�������" << setw(20) << "����� ����. ������" << setw(10) << "16" << setw(10) << "8" << endl;
                    cout << left << setfill('-') << setw(55) << " " << endl << setfill(' ');
                    for (int i = 0; i < students.size(); i++) {
                        if (students[i].getname() == name) {
                            students[i].displayInfo();
                        }
                    }
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    cout << "������� �������: ";
                    try {
                        cin >> age;
                        if (cin.fail()) {
                            throw 1;
                        }
                    }
                    catch (int) {
                        cout << "������ �����.";
                    }
                    catch (...) {
                        cout << "������ �������������� ����������";
                    }
                    cout << left << setfill(' ') << setw(15) << "���" << setw(20) << "�������" << setw(20) << "����� ����. ������" << setw(10) << "16" << setw(10) << "8" << endl;
                    cout << left << setfill('-') << setw(55) << " " << endl << setfill(' ');
                    for (int i = 0; i < students.size(); i++) {
                        if (students[i].getage() == age) {
                            students[i].displayInfo();
                        }
                    }
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    cout << "������� ����� ���� ������: ";
                    try {
                        cin >> studentID;
                        if (cin.fail()) {
                            throw 1;
                        }
                    }
                    catch (int) {
                        cout << "������ �����.";
                    }
                    catch (...) {
                        cout << "������ �������������� ����������";
                    }
                    cout << left << setfill(' ') << setw(15) << "���" << setw(20) << "�������" << setw(20) << "����� ����. ������" << setw(10) << "16" << setw(10) << "8" << endl;
                    cout << left << setfill('-') << setw(55) << " " << endl << setfill(' ');
                    for (int i = 0; i < students.size(); i++) {
                        if (students[i].getID() == studentID) {
                            students[i].displayInfo();
                        }
                    }
                    system("pause");
                    break;
                case 0:
                    break;
                }
            break;
        case 0: return 0;
        }
    }
    return 0;
}