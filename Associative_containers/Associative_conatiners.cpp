#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <map>
#include <unordered_map>
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

void addMedicalWorker(map<string, MedicalWorker>& workers) {
    MedicalWorker worker;
    cout << "������� ��� ������������ ���������: ";
    getline(cin >> ws, worker.name);
    cout << "������� ������������� ������������ ���������: ";
    getline(cin >> ws, worker.specialization);

    workers.insert(make_pair(worker.name, worker));
    cout << "����������� �������� ��������." << endl;
}

void removeMedicalWorker(map<string, MedicalWorker>& workers) {
    string name;
    cout << "������� ��� ������������ ���������, �������� ������ �������: ";
    getline(cin >> ws, name);

    auto it = workers.find(name);
    if (it != workers.end()) {
        workers.erase(it);
        cout << "����������� �������� ������." << endl;
    }
    else {
        cout << "����������� �������� � ����� ������ �� ������." << endl;
    }
}

void editMedicalWorker(map<string, MedicalWorker>& workers) {
    string name;
    cout << "������� ��� ������������ ���������, �������� ������ ���������������: ";
    getline(cin >> ws, name);

    auto it = workers.find(name);
    if (it != workers.end()) {
        MedicalWorker& worker = it->second;
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

void displayMedicalWorkers(const map<string, MedicalWorker>& workers) {
    if (workers.empty()) {
        cout << "��� ��������� ������ � ����������� ����������." << endl;
    }
    else {
        cout << "������ ����������� ����������:" << endl;
        for (const auto& pair : workers) {
            const MedicalWorker& worker = pair.second;
            cout << "���: " << worker.name << ", �������������: " << worker.specialization << endl;
        }
    }
}

void saveMedicalWorkersToFile(const map<string, MedicalWorker>& workers, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "������ �������� �����." << endl;
        return;
    }

    for (const auto& pair : workers) {
        const MedicalWorker& worker = pair.second;
        {
            file << "���: " << worker.name << ", �������������: " << worker.specialization << endl;
        }

        cout << "������ ������� ��������� � ����." << endl;
    }

    file.close();
}

void searchMedicalWorker(const map<string, MedicalWorker>& workers) {
    string name;
    cout << "������� ��� ������������ ���������, �������� ������ �����: ";
    getline(cin >> ws, name);

    auto it = workers.find(name);
    if (it != workers.end()) {
        const MedicalWorker& worker = it->second;
        cout << "����������� �������� ������: " << endl;
        cout << "���: " << worker.name << ", �������������: " << worker.specialization << endl;
    }
    else {
        cout << "����������� �������� � ����� ������ �� ������." << endl;
    }
}

void sortMedicalWorkers(map<string, MedicalWorker>& workers) {
    map<string, MedicalWorker> sortedWorkers(workers.begin(), workers.end());
    workers = sortedWorkers;
    cout << "������ ����������� ���������� ������������." << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    map<string, MedicalWorker> workers;
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
