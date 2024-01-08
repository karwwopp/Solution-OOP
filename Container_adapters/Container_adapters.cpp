#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include<string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include<Windows.h>
using namespace std;

struct MedicalWorker {
    string name;
    string specialization;
};

void displayMenu() {
    cout << "1. �������� ������������ ���������" << endl;
    cout << "2. ������� ������������ ���������" << endl;
    cout << "3. ������������� ������������ ���������" << endl;
    cout << "4. ������� ���������� ����������" << endl;
    cout << "5. ��������� ���������� � ����" << endl;
    cout << "6. ����� ������������ ���������" << endl;
    cout << "7. ���������� ����������� ����������" << endl;
    cout << "8. �����" << endl;
    cout << "�������� ��������: ";
}

void addMedicalWorker(vector<MedicalWorker>& workers) {
    MedicalWorker worker;
    cout << "������� ��� ������������ ���������: ";
    getline(cin >> ws, worker.name);
    cout << "������� ������������� ������������ ���������: ";
    getline(cin >> ws, worker.specialization);

    workers.push_back(worker);
    cout << "����������� �������� ��������." << endl;
}

void removeMedicalWorker(vector<MedicalWorker>& workers) {
    string name;
    cout << "������� ��� ������������ ���������, �������� ������ �������: ";
    getline(cin >> ws, name);

    auto it = find_if(workers.begin(), workers.end(), [&](const MedicalWorker& worker) {
        return worker.name == name;
        });

    if (it != workers.end()) {
        workers.erase(it);
        cout << "����������� �������� ������." << std::endl;
    }
    else {
        cout << "����������� �������� � ����� ������ �� ������." << std::endl;
    }
}

void editMedicalWorker(vector<MedicalWorker>& workers) {
    string name;
    cout << "������� ��� ������������ ���������, �������� ������ ���������������: ";
    getline(cin >> ws, name);

    auto it = find_if(workers.begin(), workers.end(), [&](const MedicalWorker& worker) {
        return worker.name == name;
        });

    if (it != workers.end()) {
        MedicalWorker& worker = *it;
        cout << "������� ����� ��� ������������ ���������: ";
        getline(cin >> ws, worker.name);
        cout << "������� ����� ������������� ������������ ���������: ";
        getline(cin >> ws, worker.specialization);
        cout << "����������� �������� ��������������." << endl;
    }
    else {
        cout << "����������� �������� � ����� ������ �� ������." << endl;
    }
}

void displayMedicalWorkers(const vector<MedicalWorker>& workers) {
    if (workers.empty()) {
        cout << "��� ��������� ������ � ����������� ����������." << endl;
    }
    else {
        cout << "������ ����������� ����������:" << endl;
        cout << setw(15) << left << "���" << "�������������" << endl;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;

        for (const auto& worker : workers) {
            cout << setw(15) << left << worker.name << " " << worker.specialization << endl;
        }
    }
}

void saveMedicalWorkersToFile(const vector<MedicalWorker>& workers, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "������ ��� �������� �����." << endl;
        return;
    }

    for (const auto& worker : workers) {
        file << "���: " << worker.name << ", �������������: " << worker.specialization << endl;
    }

    cout << "������ ������� ��������� � ����." << endl;

    file.close();
}

void searchMedicalWorker(const std::vector<MedicalWorker>& workers) {
    string name;
    cout << "������� ��� ������������ ���������, �������� ������ �����: ";
    getline(cin >> ws, name);

    auto it = find_if(workers.begin(), workers.end(), [&](const MedicalWorker& worker) {
        return worker.name == name;
        });

    if (it != workers.end()) {
        const MedicalWorker& worker = *it;
        cout << "����������� �������� ������: " << endl;
        cout << "���: " << worker.name << ", �������������: " << worker.specialization << endl;
    }
    else {
        cout << "����������� �������� � ����� ������ �� ������." << endl;
    }
}

void sortMedicalWorkers(vector<MedicalWorker>& workers) {
    sort(workers.begin(), workers.end(), [](const MedicalWorker& worker1, const MedicalWorker& worker2) {
        return worker1.name < worker2.name;
        });

    cout << "������ ����������� ���������� ������������." << std::endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<MedicalWorker> workers;
    string filename = "workers.txt";

    int choice = 0;
    while (choice != 8) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addMedicalWorker(workers);
            break;
        case 2:
            removeMedicalWorker(workers);
            break;
        case 3:
            editMedicalWorker(workers);
            break;
        case 4:
            displayMedicalWorkers(workers);
            break;
        case 5:
            saveMedicalWorkersToFile(workers, filename);
            break;
        case 6:
            searchMedicalWorker(workers);
            break;
        case 7:
            sortMedicalWorkers(workers);
            break;
        case 8:
            cout << "�����." << endl;
            break;
        default:
            cout << "�������� �����. ���������� ��� ���." << endl;
            break;
        }
    }

    return 0;
}
