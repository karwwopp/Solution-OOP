#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

void TermFunc();
int Menu();

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
    void displayInfo() const {
        cout << "\n���: " << name << ", �������: " << age;
    }
    ~Person() {
        if (name.size() != 0) {
            cout << "���������� �������� ��� ��������: " << name << endl;
        }
    }
};

class Work {
private:
    float salary;
    string post;
public:
    Work() : post(""), salary(0) {}
    Work(string p, float s) : post(p), salary(s) {
    }
    Work(const Work& other) {
        salary = other.salary;
        post = other.post;
    }
    void displayInfo() {
        cout << "���������: " << post;
        cout << "��������: " << salary;
    }
    string getPost() {
        return post;
    }
    void setWork(string post, float salary) {
        this->post = post;
        this->salary = salary;
    }
    ~Work() {
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
    Student(string n, int a, int id, string post, float salary) : Person(n, a), studentID(id), work(post, salary) {
        cout << "����������� �������� ��� ��������: " << name << endl;
    }
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
        cout << ", ����� ������������� ������: " << studentID << endl;
    }
    ~Student() {
        if (name.size() != 0) {
            cout << "���������� �������� ��� ��������: " << name << endl;
        }
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
    void displayInfo() const {
        Person::displayInfo();
    }
    void setProfessor(string n, int a, string p, float s) {
        name = n;
        age = a;
        work.setWork(p, s);
    }
    ~Professor() {
        if (!(name.size() == 0)) {
            cout << "���������� �������� ��� ����������: " << name << endl;
        }
    }
};

class Group {
private:
    int groupCode;
    vector <Professor> instructor;
    vector <Student> students;
public:
    Group() : groupCode(0) {}
    Group(int code, Professor prof) {
        try {
            if (code < 1000) {
                throw 1;
            }
        }
        catch (int) {
            cout << "����� ������ �� ����� ���� ������ 4-� �������� �����\n";
        }
        groupCode = code;
        try {
            instructor.push_back(prof);
        }
        catch (bad_alloc ex) {
            cout << "������ ��������� ������.\n";
        }
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
    int get_code() {
        return groupCode;
    }
    void displayInfo() const {
        cout << "\n����� ������: " << groupCode << "\n�������������: \n";
        for (int i = 0; i < instructor.size(); i++) {
            instructor[i].displayInfo();
            cout << "\n";
        }
        cout << "��������: \n";
        for (int i = 0; i < students.size(); i++) {
            students[i].displayInfo();
            cout << "\n";
        }
    }
    ~Group() {
    }
};