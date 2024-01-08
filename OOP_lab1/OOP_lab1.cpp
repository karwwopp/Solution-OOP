#include "header.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Person* Persons;
	Student* Students;
	Worker* Workers;
	StudentWorker* StudentWorkers;
	int NumberOfPeople;
	do {
		switch (menu()) {
		case 1:
			system("cls");
			cout << "Введите кол-во людей которое хотите ввести: ";
			NumberOfPeople = check();
			while (NumberOfPeople < 0) {
				cout << "Невозможно ввести такое количество людей\n Попробуйте еще раз: ";
				NumberOfPeople = check();
			}
			Persons = new Person[NumberOfPeople];
			for (int i = 0; i < NumberOfPeople; i++) {
				system("cls");
				cout << "Введите имя №" << i + 1 << " Человека: ";
				string Name;
				cin >> Name;
				Persons[i].set_name(Name);
				cout << "Введите фамилию №" << i + 1 << " Человека: ";
				string Surname;
				cin >> Surname;
				Persons[i].set_surname(Surname);
			}
			system("cls");
			for (int i = 0; i < NumberOfPeople; i++) {
				cout << "Имя №" << i + 1 << " Человека: " << Persons[i].get_name() << "\n";
				cout << "Фамилия №" << i + 1 << " Человека: " << Persons[i].get_surname() << "\n\n";
			}
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "Введите кол-во студентов которое хотите ввести: ";
			NumberOfPeople = check();
			while (NumberOfPeople < 0) {
				cout << "Невозможно ввести такое количество студентов\n Попробутйе еще раз: ";
				NumberOfPeople = check();
			}
			Students = new Student[NumberOfPeople];
			for (int i = 0; i < NumberOfPeople; i++) {
				system("cls");
				cout << "Введите имя №" << i + 1 << " Студента: ";
				string Name;
				cin >> Name;
				Students[i].set_name(Name);
				cout << "Введите фамилию №" << i + 1 << " Студента: ";
				string Surname;
				cin >> Surname;
				Students[i].set_surname(Surname);
				cout << "Введите факультет №" << i + 1 << " Студента: ";
				string Faculty;
				getchar();
				getline(cin, Faculty);
				Students[i].set_faculty(Faculty);
				cout << "Введите специальность №" << i + 1 << " Студента: ";
				string Speciality;
				getchar();
				getline(cin, Speciality);
				Students[i].set_speciality(Speciality);
				cout << "Введите Средний балл №" << i + 1 << " Студента: ";
				float Average;
				Average = check_double();
				Students[i].set_average(Average);
			}
			system("cls");
			for (int i = 0; i < NumberOfPeople; i++) {
				cout << "Имя №" << i + 1 << " Студента: " << Students[i].get_name() << "\n";
				cout << "Фамилия №" << i + 1 << " Студента: " << Students[i].get_surname() << "\n\n";
				cout << "Фаукльтет №" << i + 1 << "Студента" << Students[i].get_faculty() << "\n";
				cout << "Специальность №" << i + 1 << "Студента" << Students[i].get_speciality() << "\n";
				cout << "Средний балл №" << i + 1 << "Студента" << Students[i].get_average() << "\n";

			}
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "Введите кол-во Работников которое хотите ввести: ";
			NumberOfPeople = check();
			while (NumberOfPeople < 0) {
				cout << "Невозможно ввести такое количество Работников\n Попробутйе еще раз: ";
				NumberOfPeople = check();
			}
			Workers = new Worker[NumberOfPeople];
			for (int i = 0; i < NumberOfPeople; i++) {
				system("cls");
				cout << "Введите имя №" << i + 1 << " Работника: ";
				string Name;
				cin >> Name;
				Workers[i].set_name(Name);
				cout << "Введите фамилию №" << i + 1 << " Работника: ";
				string Surname;
				cin >> Surname;
				Workers[i].set_surname(Surname);
				cout << "Введите Должность №" << i + 1 << " Работника: ";
				string Post;
				getchar();
				getline(cin,Post);
				Workers[i].set_post(Post);
				cout << "Введите Зарплату №" << i + 1 << " Работника: ";
				int Salary;
				Salary = check();
				Workers[i].set_salary(Salary);

			}
			system("cls");
			for (int i = 0; i < NumberOfPeople; i++) {
				cout << "Имя №" << i + 1 << " Работника: " << Workers[i].get_name() << "\n";
				cout << "Фамилия №" << i + 1 << " Работника: " << Workers[i].get_surname() << "\n";
				cout << "Должность №" << i + 1 << " Работника: " << Workers[i].get_post() << "\n";
				cout << "Зарплата №" << i + 1 << " Работника" << Workers[i].get_salary() << "\n\n";
			}
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "Введите кол-во Студентов-Работников которое хотите ввести: ";
			NumberOfPeople = check();
			while (NumberOfPeople < 0) {
				cout << "Невозможно ввести такое количество Студентов-Работников\n Попробутйе еще раз: ";
				NumberOfPeople = check();
			}
			StudentWorkers = new StudentWorker[NumberOfPeople];
			for (int i = 0; i < NumberOfPeople; i++) {
				system("cls");
				cout << "Введите имя №" << i + 1 << " Студента-Работника: ";
				string Name;
				cin >> Name;
				StudentWorkers[i].set_name(Name);
				cout << "Введите фамилию №" << i + 1 << " Студента-Работника: ";
				string Surname;
				cin >> Surname;
				StudentWorkers[i].set_surname(Surname);
				cout << "Введите факультет №" << i + 1 << " Студента-Работника: ";
				string Faculty;
				getchar();
				getline(cin, Faculty);
				StudentWorkers[i].set_faculty(Faculty);
				cout << "Введите специальность №" << i + 1 << " Студента-Работника: ";
				string Speciality;
				getchar();
				getline(cin, Speciality);
				StudentWorkers[i].set_speciality(Speciality);
				cout << "Введите Средний балл №" << i + 1 << " Студента-Работника: ";
				float Average;
				Average = check_double();
				StudentWorkers[i].set_average(Average);
				cout << "Введите Должность №" << i + 1 << " Студента-Работника: ";
				string Post;
				getchar();
				getline(cin, Post);
				StudentWorkers[i].set_post(Post);
				cout << "Введите Зарплату №" << i + 1 << " Студента-Работника: ";
				float Salary;
				Salary = check_double();
				StudentWorkers[i].set_salary(Salary);
			}
			system("cls");
			for (int i = 0; i < NumberOfPeople; i++) {
				cout << "Имя №" << i + 1 << " Студента-Работника: " << StudentWorkers[i].get_name() << "\n";
				cout << "Фамилия №" << i + 1 << " Студента-Работника: " << StudentWorkers[i].get_surname() << "\n";
				cout << "Фаукльтет №" << i + 1 << "Студента-Работника" << StudentWorkers[i].get_faculty() << "\n";
				cout << "Специальность №" << i + 1 << "Студента-Работника" << StudentWorkers[i].get_speciality() << "\n";
				cout << "Средний балл №" << i + 1 << "Студента-Работника" << StudentWorkers[i].get_average() << "\n";
				cout << "Должность №" << i + 1 << "Студента-Работника" << StudentWorkers[i].get_post() << "\n";
				cout << "Зарплата №" << i + 1 << "Студента-Работника" << StudentWorkers[i].get_salary() << "\n";




 			}
			system("pause");
			break;
		case 5:return 0;
		}
		
	} while (1);
}