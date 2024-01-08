#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class UniversityException : public exception {
private:
public:
    const char* what() const override {
        return "Некорректный номер студенческого билета";
    }
};

class Person {
protected:
    string name;
    int age;
public:
    Person() : name(""), age(0) {}
    Person(string n, int a) : name(n), age(a) {
        cout << "Конструктор сработал для человека: " << name << endl;
    }
    Person(const Person &other) : name(other.name), age(other.age) {}
    void displayInfo() const {
        cout << "Имя: " << name << ", Возраст: " << age;
    }
    ~Person() {
        cout << "Деструктор сработал для человека: " << name << endl;
    }
};

class Work {
private:
    float salary;
    string post;
public:
    Work() : post(""), salary(0) {}
    Work(string p, float s) : post(p), salary(s) {
        cout << "Конструктор сработал для Должности: " << post << endl;
    }
    Work(const Work& other) {
        salary = other.salary;
        post = other.post;
    }
    void displayInfo() {
        cout << "Должность: " << post;
        cout << "Зарплата: " << salary;
    }
    void setWork(string post, float salary) {
        this->post = post;
        this->salary = salary;
    }
    ~Work() {
        cout << "Деструктор сработал для должности: " << post << endl;
    }
};

class Student : public Person {
private:
     int studentID;
     Work work;
public:
    Student() : Person(), studentID(0), work() {}
    Student(string n, int a, int id) : Person(n, a), studentID(id), work() {
        cout << "Конструктор сработал для студента: " << name << endl;
    }
    Student(string n, int a, int id,string post,float salary) : Person(n, a), studentID(id), work(post,salary) {
        cout << "Конструктор сработал для студента: " << name << endl;
    }
    Student(const Student &other) : Person(other.name,other.age) , studentID(other.studentID) ,work(other.work){}
    void set_studentworker(string n, int a, int id, string post, float salary) {
        name = n;
        age = a;
        studentID = id;
        work.setWork(post, salary);
    }
    void set_student(string n, int a, int id) {
        name = n;
        age = a;
        studentID = id;
    }
    void displayInfo() const {
        Person::displayInfo();
        cout << "Номер студенческого билета: " << studentID <<  endl;
    }
    ~Student() {
        cout << "Деструктор сработал для студента: " << name << endl;
    }
};

class Professor : public Person {
private:
    Work work;
public:
    Professor() : Person(), work() {}
    Professor(string n, int a, string post, float salary) : Person(n, a), work(post, salary) {
        cout << "Конструктор сработал для профессора: " << name << endl;
    }
    Professor(const Professor& other) : Person(other.name, other.age), work(other.work) {}
    void displayInfo() const {
        Person::displayInfo();
    }
    void setProfessor(string n,int a,string p,float s) {
        name = n;
        age = a;
        work.setWork(p, s);
    }
    ~Professor() {
        cout << "Деструктор сработал для профессора: " << name << endl;
    }
};

class Group {
private:
    int groupCode;
    vector <Professor> instructor;
    vector <Student> students;
public:
    Group () : groupCode(0){}
    Group(int code, Professor prof) {
        groupCode = code;
        try{
            instructor.push_back(prof);
        }
        catch (bad_alloc ex) {
            cout << "Ошибка выделения памяти.\n";
        }
        cout << "Конструктор сработал для группы№" << groupCode << endl;
    }
    void addCode(int group) {
        groupCode = group;
    }
    void addProfessor(Professor prof) {
        try {
            instructor.push_back(prof);
        }
        catch (bad_alloc ex) {
            cout << "Ошибка выделения памяти.\n";
        }
    }
    void addStudent(Student stud) {
        try {
            students.push_back(stud);
        }
        catch (bad_alloc ex) {
            cout << "Ошибка выделения памяти.\n";
        }
    }
    int get_code(){
        return groupCode;
    }
    void displayInfo() const {
        cout << "\nНомер группы: " << groupCode << "\nПреподователи: ";
        for (int i = 0; i < instructor.size(); i++) {
            instructor[i].displayInfo();
        }
    }
    ~Group() {
        cout << "Деструктор сработал для группы №" << groupCode << endl;
    }
};

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

int main() {
    set_terminate(TermFunc);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector <Person*> all_persons;
    vector <Student> students;
    vector <Professor> professors;
    vector <Group> groups;
    while (1) {
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
            try {
                cin >> studentID;
                if (studentID < 10000000 || studentID > 99999999) {
                    throw UniversityException();
                }
            }
            catch (UniversityException& ex) {
                cout << ex.what();  
            }
            catch (exception& ex) {
                cout << ex.what() << endl;
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
            new_professor.setProfessor(name, age, post, salary);
            while(true){
                is_found = 0;
                cout << "Введите группу в которой работает преподаватель";
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
                try{
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
            for (int i = 0; i < students.size();i++) {
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
    system("cls");
    return 0;
}