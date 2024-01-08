#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class UniversityException : public exception {
private:
public:
    const char* what() const override {
        return "������������ ����� ������������� ������";
    }
};

class Person {
protected:
    string name;
    int age;
public:
    Person() : name(""), age(0) {}
    Person(string n, int a) : name(n), age(a) {
        cout << "����������� �������� ��� ��������: " << name << endl;
    }
    Person(const Person &other) : name(other.name), age(other.age) {}
    void displayInfo() const {
        cout << "���: " << name << ", �������: " << age;
    }
    ~Person() {
        cout << "���������� �������� ��� ��������: " << name << endl;
    }
};

class Work {
private:
    float salary;
    string post;
public:
    Work() : post(""), salary(0) {}
    Work(string p, float s) : post(p), salary(s) {
        cout << "����������� �������� ��� ���������: " << post << endl;
    }
    Work(const Work& other) {
        salary = other.salary;
        post = other.post;
    }
    void displayInfo() {
        cout << "���������: " << post;
        cout << "��������: " << salary;
    }
    void setWork(string post, float salary) {
        this->post = post;
        this->salary = salary;
    }
    ~Work() {
        cout << "���������� �������� ��� ���������: " << post << endl;
    }
};

class Student : public Person {
private:
     int studentID;
     Work work;
public:
    Student() : Person(), studentID(0), work() {}
    Student(string n, int a, int id) : Person(n, a), studentID(id), work() {
        cout << "����������� �������� ��� ��������: " << name << endl;
    }
    Student(string n, int a, int id,string post,float salary) : Person(n, a), studentID(id), work(post,salary) {
        cout << "����������� �������� ��� ��������: " << name << endl;
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
        cout << "����� ������������� ������: " << studentID <<  endl;
    }
    ~Student() {
        cout << "���������� �������� ��� ��������: " << name << endl;
    }
};

class Professor : public Person {
private:
    Work work;
public:
    Professor() : Person(), work() {}
    Professor(string n, int a, string post, float salary) : Person(n, a), work(post, salary) {
        cout << "����������� �������� ��� ����������: " << name << endl;
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
        cout << "���������� �������� ��� ����������: " << name << endl;
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
            cout << "������ ��������� ������.\n";
        }
        cout << "����������� �������� ��� �������" << groupCode << endl;
    }
    void addCode(int group) {
        groupCode = group;
    }
    void addProfessor(Professor prof) {
        try {
            instructor.push_back(prof);
        }
        catch (bad_alloc ex) {
            cout << "������ ��������� ������.\n";
        }
    }
    void addStudent(Student stud) {
        try {
            students.push_back(stud);
        }
        catch (bad_alloc ex) {
            cout << "������ ��������� ������.\n";
        }
    }
    int get_code(){
        return groupCode;
    }
    void displayInfo() const {
        cout << "\n����� ������: " << groupCode << "\n�������������: ";
        for (int i = 0; i < instructor.size(); i++) {
            instructor[i].displayInfo();
        }
    }
    ~Group() {
        cout << "���������� �������� ��� ������ �" << groupCode << endl;
    }
};

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
            cout << "������� ��� ��������: ";
            getchar();
            getline(cin, name);
            cout << "������� ������� ��������: ";
            cin >> age;
            cout << "������� ����� ������������� ������: ";
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
            new_professor.setProfessor(name, age, post, salary);
            while(true){
                is_found = 0;
                cout << "������� ������ � ������� �������� �������������";
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
                try{
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
            for (int i = 0; i < students.size();i++) {
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
    system("cls");
    return 0;
}