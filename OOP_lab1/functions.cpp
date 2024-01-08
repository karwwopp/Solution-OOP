#include "header.h"

int check() {
	int number;
	cin >> number;
	while (cin.fail() || cin.get() != '\n') {
		{
			cout << "\nOшибка ввода.\nПовторите попытку:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> number;
		}
	}
	return number;
}

float check_double() {
	float number;
	cin >> number;
	while (cin.fail() || cin.get() != '\n') {
		{
			cout << "\nOшибка ввода.\nПовторите попытку:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> number;
		}
	}
	return number;
}

int menu() {
	int choice;
	system("cls");
	cout << "1)Добавить человека\n2)Добавить cтудента\n3)Добавить работника\n4)Добавить студента-работника\n5)Выход\nВаш выбор:";
	choice = check();
	while (choice > 5 || choice < 0) {
		system("cls");
		cout << "Неверный выбор\n";
		cout << "1)Добавить человека\n2)Добавить cтудента\n3)Добавить работника\n4)Добавить студента-работника\n5)Выход\nВаш выбор:";
		choice = check();
	}
	return choice;
}

Person::Person() {
	this->name = "";
	this->surname = "";
}

Person::Person(string new_name, string new_surname) {
	this->name = new_name;
	this->surname = new_surname;
}

Person::Person(const Person& other) {
	this->name = other.name;
	this->surname = other.surname;
}

void Person::set_name(string new_name) {
	this->name = new_name;
}

void Person::set_surname(string new_surname) {
	surname = new_surname;
}

string Person::get_name() {
	return name;
}

string Person::get_surname() {
	return surname;
}

Student::Student() {
	this->faculty = "";
	this->speciality = "";
	this->average_score = 0;
}

Student::Student(const Student& other) {
	this->faculty = other.faculty;
	this->speciality = other.speciality;
	this->average_score = other.average_score;
}

Student::Student(string new_faculty, string new_speciality, float new_average_score) {
	this->faculty = new_faculty;
	this->speciality = new_speciality;
	this->average_score = new_average_score;
}

void Student::set_faculty(string new_faculty) {
	faculty = new_faculty;
}

void Student::set_speciality(string new_speciality) {
	speciality = new_speciality;
}

void Student::set_average(float new_average) {
	average_score = new_average;
}

string Student::get_faculty() {
	return faculty;
}

string Student::get_speciality() {
	return speciality;
}

float Student::get_average() {
	return average_score;
}

Worker::Worker() {
	salary = 0;
	post = "";
}

Worker::Worker(float new_salary, string new_post) {
	this->salary = new_salary;
	this->post = new_post;
}

Worker::Worker(const Worker& other) {
	this->salary = other.salary;
	this->post = other.post;
}

void Worker::set_salary(float new_salary) {
	salary = new_salary;
}

void Worker::set_post(string new_post) {
	post = new_post;
}

float Worker::get_salary() {
	return salary;
}

string Worker::get_post() {
	return post;
}