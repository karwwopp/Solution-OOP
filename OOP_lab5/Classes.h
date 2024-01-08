#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <iomanip>
#include <fstream>

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
        cout << left << setw(15) << name << setw(20) << age;
    }
    ~Person() {
        if (name.size() != 0) {
            cout << "���������� �������� ��� ��������: " << name << endl;
        }
    }
};

class Work {
protected:
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
    float getSalary() {
        return salary;
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
    void getPost() {
        work.getPost();
    }
    void displayInfo() const {
        Person::displayInfo();
        cout.setf(ios::uppercase);
        cout << left << setw(20) << studentID << setw(10) << hex << studentID << setw(10) << oct << studentID << endl;
        cout.unsetf(ios::oct);
        cout.setf(ios::dec);
        cout.unsetf(ios::uppercase);
    }
    int getID() {
        return studentID;
    }
    string getname() {
        return name;
    }
    int getage() {
        return age;
    }
    void setID(int ID) {
        studentID = ID;
    }
    void setname(string n) {
        name = n;
    }
    void setage(int a) {
        age = a;
    }
    ~Student() {
        if (name.size() != 0) {
            cout << "���������� �������� ��� ��������: " << name << endl;
        }
    }
    friend ostream& operator<< (ostream& os, Student& student) {
        os << student.name << "\n" << student.age << " " << student.studentID << "\n";
        if (student.work.getPost() == "") {
            os << "0" << "\n";
        }
        else
        {
            os << "1" << "\n";
            os << student.work.getPost() << "\n";
            os << student.work.getSalary() << "\n";
        }
        return os;
    }
    friend istream& operator>>(istream& is, Student& student) {
        is >> student.name >> student.age >> student.studentID;
        bool check = 0;
        is >> check;
        if (check) {
            string post;
            is >> post;
            float salary;
            is >> salary;
            student.work.setWork(post, salary);
        }
        else
            student.work.setWork("", 0);
        return is;
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
        if (instructor.size() == 0) {
            cout << "��� ��������������\n";
        }
        else {
            cout << left << setw(15) << "���" << setw(20) << "�������" << endl;
            cout << left << setfill('-') << setw(35) << " " << endl << setfill(' ');
            for (int i = 0; i < instructor.size(); i++) {
                instructor[i].displayInfo();
                cout << "\n";
            }
        }
        if (students.size() == 0) {
            cout << "��� ���������\n";
        }
        else {
            cout << "��������: \n";
            cout << left << setfill(' ') << setw(15) << "���" << setw(20) << "�������" << setw(20) << "����� ����. ������" << setw(10) << "16" << setw(10) << "8" << endl;
            cout << left << setfill('-') << setw(55) << " " << endl << setfill(' ') << endl;
            for (int i = 0; i < students.size(); i++) {
                students[i].displayInfo();
                cout << "\n";
            }
        }
    }
    ~Group() {
    }
};