#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int menu();

int check();

float check_double();

class Person {
protected:
	string name;
	string surname;
public:
	Person();
	Person(string new_name, string new_surname);
	Person(const Person& other);
	void set_name(string name);
	void set_surname(string new_surname);
	string get_name();
	string get_surname();
};

class Student : public virtual Person {
protected:
	string faculty;
	string speciality;
	float average_score;
public:
	Student();
	Student(const Student& other);
	Student(string new_faculty, string new_speciality, float new_average_score);
	void set_faculty(string new_faculty);
	void set_speciality(string new_speciality);
	void set_average(float new_average);
	string get_faculty();
	string get_speciality();
	float get_average();
};

class Worker : public virtual Person {
protected:
	float salary;
	string post;
public:
	Worker();
	Worker(const Worker& other);
	Worker(float new_salary, string new_post);
	void set_salary(float new_salary);
	void set_post(string new_post);
	float get_salary();
	string get_post();
};

class StudentWorker : public Student, public Worker {
};