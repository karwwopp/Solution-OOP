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
            cout << "Введите имя студента: ";
            getchar();
            getline(cin, name);
            cout << "Введите возраст студента: ";
            cin >> age;
            cout << "Введите номер студенческого билета: ";
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
                cout << "\nВведите номер студенческого билета: ";
            }
            cout << "Введите номер группы: ";
            cin >> group;
            try {
                while (true) {
                    cout << "Работает ли студент(да/нет): ";
                    cin >> choice;
                    if (choice == "нет" || choice == "да") {
                        break;
                    }
                    else if (choice != "да") {
                        throw 1;
                    }
                }
            }
            catch (exception& ex) {
                cout << "Исключение: " << ex.what() << endl;
            }
            catch (...) {
                cout << "Ошибка направлена в исключительный обработчик." << endl;
            }
            if (choice == "да") {
                cout << "Введите должность студента: ";
                getchar();
                getline(cin, post);
                cout << "Введите зарплату студента: ";
                try {
                    cin >> salary;
                }
                catch (exception& ex) {
                    cout << "Исключение" << ex.what() << endl;
                }
                new_student.set_studentworker(name, age, studentID, post, salary);
            }
            else
                new_student.set_student(name, age, studentID);
            try {
                new_person = new Student(name, age, studentID);
            }
            catch (bad_alloc& ex) {
                cout << "Ошибка выделения памяти\n";
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
            cout << "Введите имя преподавателя: ";
            getchar();
            getline(cin, name);
            cout << "Введите возраст преподавателя: ";
            try {
                cin >> age;
            }
            catch (exception& ex) {
                cout << "Исключение: " << ex.what() << endl;
            }
            cout << "Введите Должность преподователя: ";
            getchar();
            getline(cin, post);
            cout << "Введите зарплату преподователя: ";
            try {
                cin >> salary;
            }
            catch (exception& ex) {
                cout << "Исключение" << ex.what() << endl;
            }
            new_person = new Professor(name,age,post,salary);
            new_professor.setProfessor(name, age, post, salary);
            while (true) {
                is_found = 0;
                cout << "Введите группу в которой работает преподаватель: ";
                try {
                    cin >> group;
                }
                catch (exception& ex) {
                    cout << "Исключение: " << ex.what() << endl;
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
                cout << "Желаете продолжить(да/нет): ";
                try {
                    cin >> choice;
                    if (choice == "нет") {
                        break;
                    }
                    else if (choice != "Да") {
                        throw 1;
                    }
                }
                catch (exception& ex) {
                    cout << "Исключение: " << ex.what() << endl;
                }
                catch (...) {
                    cout << "Вызван исключительный обработчик";
                }
            }
            professors.push_back(new_professor);
            break;
        case 3:
            system("cls");
            if (students.size() == 0) {
                cout << "Нет студентов в базе\n";
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
                cout << "Нет преподователей в базе\n";
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
                cout << "Нет групп в базе\n";
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