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
			cout << "������� ���-�� ����� ������� ������ ������: ";
			NumberOfPeople = check();
			while (NumberOfPeople < 0) {
				cout << "���������� ������ ����� ���������� �����\n ���������� ��� ���: ";
				NumberOfPeople = check();
			}
			Persons = new Person[NumberOfPeople];
			for (int i = 0; i < NumberOfPeople; i++) {
				system("cls");
				cout << "������� ��� �" << i + 1 << " ��������: ";
				string Name;
				cin >> Name;
				Persons[i].set_name(Name);
				cout << "������� ������� �" << i + 1 << " ��������: ";
				string Surname;
				cin >> Surname;
				Persons[i].set_surname(Surname);
			}
			system("cls");
			for (int i = 0; i < NumberOfPeople; i++) {
				cout << "��� �" << i + 1 << " ��������: " << Persons[i].get_name() << "\n";
				cout << "������� �" << i + 1 << " ��������: " << Persons[i].get_surname() << "\n\n";
			}
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "������� ���-�� ��������� ������� ������ ������: ";
			NumberOfPeople = check();
			while (NumberOfPeople < 0) {
				cout << "���������� ������ ����� ���������� ���������\n ���������� ��� ���: ";
				NumberOfPeople = check();
			}
			Students = new Student[NumberOfPeople];
			for (int i = 0; i < NumberOfPeople; i++) {
				system("cls");
				cout << "������� ��� �" << i + 1 << " ��������: ";
				string Name;
				cin >> Name;
				Students[i].set_name(Name);
				cout << "������� ������� �" << i + 1 << " ��������: ";
				string Surname;
				cin >> Surname;
				Students[i].set_surname(Surname);
				cout << "������� ��������� �" << i + 1 << " ��������: ";
				string Faculty;
				getchar();
				getline(cin, Faculty);
				Students[i].set_faculty(Faculty);
				cout << "������� ������������� �" << i + 1 << " ��������: ";
				string Speciality;
				getchar();
				getline(cin, Speciality);
				Students[i].set_speciality(Speciality);
				cout << "������� ������� ���� �" << i + 1 << " ��������: ";
				float Average;
				Average = check_double();
				Students[i].set_average(Average);
			}
			system("cls");
			for (int i = 0; i < NumberOfPeople; i++) {
				cout << "��� �" << i + 1 << " ��������: " << Students[i].get_name() << "\n";
				cout << "������� �" << i + 1 << " ��������: " << Students[i].get_surname() << "\n\n";
				cout << "��������� �" << i + 1 << "��������" << Students[i].get_faculty() << "\n";
				cout << "������������� �" << i + 1 << "��������" << Students[i].get_speciality() << "\n";
				cout << "������� ���� �" << i + 1 << "��������" << Students[i].get_average() << "\n";

			}
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "������� ���-�� ���������� ������� ������ ������: ";
			NumberOfPeople = check();
			while (NumberOfPeople < 0) {
				cout << "���������� ������ ����� ���������� ����������\n ���������� ��� ���: ";
				NumberOfPeople = check();
			}
			Workers = new Worker[NumberOfPeople];
			for (int i = 0; i < NumberOfPeople; i++) {
				system("cls");
				cout << "������� ��� �" << i + 1 << " ���������: ";
				string Name;
				cin >> Name;
				Workers[i].set_name(Name);
				cout << "������� ������� �" << i + 1 << " ���������: ";
				string Surname;
				cin >> Surname;
				Workers[i].set_surname(Surname);
				cout << "������� ��������� �" << i + 1 << " ���������: ";
				string Post;
				getchar();
				getline(cin,Post);
				Workers[i].set_post(Post);
				cout << "������� �������� �" << i + 1 << " ���������: ";
				int Salary;
				Salary = check();
				Workers[i].set_salary(Salary);

			}
			system("cls");
			for (int i = 0; i < NumberOfPeople; i++) {
				cout << "��� �" << i + 1 << " ���������: " << Workers[i].get_name() << "\n";
				cout << "������� �" << i + 1 << " ���������: " << Workers[i].get_surname() << "\n";
				cout << "��������� �" << i + 1 << " ���������: " << Workers[i].get_post() << "\n";
				cout << "�������� �" << i + 1 << " ���������" << Workers[i].get_salary() << "\n\n";
			}
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "������� ���-�� ���������-���������� ������� ������ ������: ";
			NumberOfPeople = check();
			while (NumberOfPeople < 0) {
				cout << "���������� ������ ����� ���������� ���������-����������\n ���������� ��� ���: ";
				NumberOfPeople = check();
			}
			StudentWorkers = new StudentWorker[NumberOfPeople];
			for (int i = 0; i < NumberOfPeople; i++) {
				system("cls");
				cout << "������� ��� �" << i + 1 << " ��������-���������: ";
				string Name;
				cin >> Name;
				StudentWorkers[i].set_name(Name);
				cout << "������� ������� �" << i + 1 << " ��������-���������: ";
				string Surname;
				cin >> Surname;
				StudentWorkers[i].set_surname(Surname);
				cout << "������� ��������� �" << i + 1 << " ��������-���������: ";
				string Faculty;
				getchar();
				getline(cin, Faculty);
				StudentWorkers[i].set_faculty(Faculty);
				cout << "������� ������������� �" << i + 1 << " ��������-���������: ";
				string Speciality;
				getchar();
				getline(cin, Speciality);
				StudentWorkers[i].set_speciality(Speciality);
				cout << "������� ������� ���� �" << i + 1 << " ��������-���������: ";
				float Average;
				Average = check_double();
				StudentWorkers[i].set_average(Average);
				cout << "������� ��������� �" << i + 1 << " ��������-���������: ";
				string Post;
				getchar();
				getline(cin, Post);
				StudentWorkers[i].set_post(Post);
				cout << "������� �������� �" << i + 1 << " ��������-���������: ";
				float Salary;
				Salary = check_double();
				StudentWorkers[i].set_salary(Salary);
			}
			system("cls");
			for (int i = 0; i < NumberOfPeople; i++) {
				cout << "��� �" << i + 1 << " ��������-���������: " << StudentWorkers[i].get_name() << "\n";
				cout << "������� �" << i + 1 << " ��������-���������: " << StudentWorkers[i].get_surname() << "\n";
				cout << "��������� �" << i + 1 << "��������-���������" << StudentWorkers[i].get_faculty() << "\n";
				cout << "������������� �" << i + 1 << "��������-���������" << StudentWorkers[i].get_speciality() << "\n";
				cout << "������� ���� �" << i + 1 << "��������-���������" << StudentWorkers[i].get_average() << "\n";
				cout << "��������� �" << i + 1 << "��������-���������" << StudentWorkers[i].get_post() << "\n";
				cout << "�������� �" << i + 1 << "��������-���������" << StudentWorkers[i].get_salary() << "\n";




 			}
			system("pause");
			break;
		case 5:return 0;
		}
		
	} while (1);
}