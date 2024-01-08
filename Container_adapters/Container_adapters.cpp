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
    cout << "1. Добавить медицинского работника" << endl;
    cout << "2. Удалить медицинского работника" << endl;
    cout << "3. Редактировать медицинского работника" << endl;
    cout << "4. Вывести содержимое контейнера" << endl;
    cout << "5. Сохранить содержимое в файл" << endl;
    cout << "6. Поиск медицинского работника" << endl;
    cout << "7. Сортировка медицинских работников" << endl;
    cout << "8. Выход" << endl;
    cout << "Выберите действие: ";
}

void addMedicalWorker(vector<MedicalWorker>& workers) {
    MedicalWorker worker;
    cout << "Введите имя медицинского работника: ";
    getline(cin >> ws, worker.name);
    cout << "Введите специализацию медицинского работника: ";
    getline(cin >> ws, worker.specialization);

    workers.push_back(worker);
    cout << "Медицинский работник добавлен." << endl;
}

void removeMedicalWorker(vector<MedicalWorker>& workers) {
    string name;
    cout << "Введите имя медицинского работника, которого хотите удалить: ";
    getline(cin >> ws, name);

    auto it = find_if(workers.begin(), workers.end(), [&](const MedicalWorker& worker) {
        return worker.name == name;
        });

    if (it != workers.end()) {
        workers.erase(it);
        cout << "Медицинский работник удален." << std::endl;
    }
    else {
        cout << "Медицинский работник с таким именем не найден." << std::endl;
    }
}

void editMedicalWorker(vector<MedicalWorker>& workers) {
    string name;
    cout << "Введите имя медицинского работника, которого хотите отредактировать: ";
    getline(cin >> ws, name);

    auto it = find_if(workers.begin(), workers.end(), [&](const MedicalWorker& worker) {
        return worker.name == name;
        });

    if (it != workers.end()) {
        MedicalWorker& worker = *it;
        cout << "Введите новое имя медицинского работника: ";
        getline(cin >> ws, worker.name);
        cout << "Введите новую специализацию медицинского работника: ";
        getline(cin >> ws, worker.specialization);
        cout << "Медицинский работник отредактирован." << endl;
    }
    else {
        cout << "Медицинский работник с таким именем не найден." << endl;
    }
}

void displayMedicalWorkers(const vector<MedicalWorker>& workers) {
    if (workers.empty()) {
        cout << "Нет доступных данных о медицинских работниках." << endl;
    }
    else {
        cout << "Список медицинских работников:" << endl;
        cout << setw(15) << left << "Имя" << "Специализация" << endl;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;

        for (const auto& worker : workers) {
            cout << setw(15) << left << worker.name << " " << worker.specialization << endl;
        }
    }
}

void saveMedicalWorkersToFile(const vector<MedicalWorker>& workers, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Ошибка при открытии файла." << endl;
        return;
    }

    for (const auto& worker : workers) {
        file << "Имя: " << worker.name << ", Специализация: " << worker.specialization << endl;
    }

    cout << "Данные успешно сохранены в файл." << endl;

    file.close();
}

void searchMedicalWorker(const std::vector<MedicalWorker>& workers) {
    string name;
    cout << "Введите имя медицинского работника, которого хотите найти: ";
    getline(cin >> ws, name);

    auto it = find_if(workers.begin(), workers.end(), [&](const MedicalWorker& worker) {
        return worker.name == name;
        });

    if (it != workers.end()) {
        const MedicalWorker& worker = *it;
        cout << "Медицинский работник найден: " << endl;
        cout << "Имя: " << worker.name << ", Специализация: " << worker.specialization << endl;
    }
    else {
        cout << "Медицинский работник с таким именем не найден." << endl;
    }
}

void sortMedicalWorkers(vector<MedicalWorker>& workers) {
    sort(workers.begin(), workers.end(), [](const MedicalWorker& worker1, const MedicalWorker& worker2) {
        return worker1.name < worker2.name;
        });

    cout << "Список медицинских работников отсортирован." << std::endl;
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
            cout << "Выход." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
            break;
        }
    }

    return 0;
}
