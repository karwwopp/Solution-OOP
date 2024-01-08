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
            new_person = new Professor(name, age, post, salary);
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
            cout << left << setfill(' ') << setw(15)<< "Имя" << setw(20) << "Возраст" << setw(20) << "Номер студ. билета" << setw(10) << "16" << setw(10) <<"8" <<endl;
            cout << left << setfill('-') << setw(55) << " " << endl <<setfill(' ');
            for (int i = 0; i < students.size(); i++) {
                students[i].displayInfo();
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
            cout << left << setw(15) << "Имя" << setw(20) << "Возраст"<< endl;
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
                cout << "Нет групп в базе\n";
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
            cout << "Введите номер студ. билета который хотите удалить: ";
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
                cout << "Студент Успешно удален.";
            }
            catch (...) {
                cout << "Студент с таким студ. билетом не найден";
            }
            system("pause");
            break;
        case 7:
            system("cls");
            cout << "Введите номер студ. билета который хотите отредактировать: ";
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
                    cout << "Студент с таким студ. билетом найден.";
                    cout << "\n1)Изменить имя";
                    cout << "\n2)Изменит возраст";
                    cout << "\n3)Изменить номер студ. билета";
                    cout << "\n0)Выход";
                    cout << "\nВаш выбор: ";
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
                        cout << "Вы ввели неправильное число.";
                        system("pause");
                    }
                    catch (...) {
                        system("cls");
                        cout << "Что-то пошло не так. Попробуйте еще раз";
                        system("pause");
                    }
                } while (change_choice < 0 || change_choice > 4);
                switch (change_choice) {
                case 1:
                    cout << "Введите новое имя студента: ";
                    cin >> name;
                    students[save_found].setname(name);
                    break;
                case 2:
                    cout << "Введите новый возраст студента: ";
                    cin >> age;
                    students[save_found].setage(age);
                    break;
                case 3:
                    cout << "Введите новый номер студенческого билета: ";
                    cin >> studentID;
                    students[save_found].setID(studentID);
                    break;
                case 0:
                    break;
                }

            }
            catch (...) {
                cout << "Студент с таким студ. билетом не найден";
            }
        case 8:
            system("cls");
            do {
                system("cls");
                cout << "\n1)Отсортировать по имени";
                cout << "\n2)Отсортировать по возрасту";
                cout << "\n3)Отсортировать по номеру студ билета номер студ. билета";
                cout << "\n0)Выход";
                cout << "\nВаш выбор: ";
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
                    cout << "Вы ввели неправильное число.";
                    system("pause");
                }
                catch (...) {
                    system("cls");
                    cout << "Что-то пошло не так. Попробуйте еще раз";
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
                cout << "Нет студентов в базе\n";
                system("pause");
                break;
            }
            cout << left << setfill(' ') << setw(15) << "Имя" << setw(20) << "Возраст" << setw(20) << "Номер студ. билета" << setw(10) << "16" << setw(10) << "8" << endl;
            cout << left << setfill('-') << setw(55) << " " << endl << setfill(' ');
            for (int i = 0; i < students.size(); i++) {
                students[i].displayInfo();
            }
            system("pause");
            break;
        case 9:
            system("cls");
            do {
                    cout << "\n1)Найти студентов по имени";
                    cout << "\n2)Найти студентов по возрасту";
                    cout << "\n3)Найти студента по номеру студ. билета";
                    cout << "\n0)Выход";
                    cout << "\nВаш выбор: ";
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
                        cout << "Вы ввели неправильное число.";
                        system("pause");
                    }
                    catch (...) {
                        system("cls");
                        cout << "Что-то пошло не так. Попробуйте еще раз";
                        system("pause");
                    }
                } while (change_choice < 0 || change_choice > 4);
                switch (change_choice) {
                case 1:
                    system("cls");
                    cout << "Введите имя: ";
                    try {
                        getchar();
                        getline(cin, name);
                        if (cin.fail()) {
                            throw 1;
                        }
                    }
                    catch (int) {
                        cout << "Ошибка ввода.";
                    }
                    catch (...) {
                        cout << "Вызван исключительный обработчик";
                    }
                    cout << left << setfill(' ') << setw(15) << "Имя" << setw(20) << "Возраст" << setw(20) << "Номер студ. билета" << setw(10) << "16" << setw(10) << "8" << endl;
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
                    cout << "Введите возраст: ";
                    try {
                        cin >> age;
                        if (cin.fail()) {
                            throw 1;
                        }
                    }
                    catch (int) {
                        cout << "Ошибка ввода.";
                    }
                    catch (...) {
                        cout << "Вызван исключительный обработчик";
                    }
                    cout << left << setfill(' ') << setw(15) << "Имя" << setw(20) << "Возраст" << setw(20) << "Номер студ. билета" << setw(10) << "16" << setw(10) << "8" << endl;
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
                    cout << "Введите Номер студ билета: ";
                    try {
                        cin >> studentID;
                        if (cin.fail()) {
                            throw 1;
                        }
                    }
                    catch (int) {
                        cout << "Ошибка ввода.";
                    }
                    catch (...) {
                        cout << "Вызван исключительный обработчик";
                    }
                    cout << left << setfill(' ') << setw(15) << "Имя" << setw(20) << "Возраст" << setw(20) << "Номер студ. билета" << setw(10) << "16" << setw(10) << "8" << endl;
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