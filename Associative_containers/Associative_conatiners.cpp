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

void addMedicalWorker(map<string, MedicalWorker>& workers) {
    MedicalWorker worker;
    cout << "Введите имя медицинского работника: ";
    getline(cin >> ws, worker.name);
    cout << "Введите специализацию медицинского работника: ";
    getline(cin >> ws, worker.specialization);

    workers.insert(make_pair(worker.name, worker));
    cout << "Медицинский работник добавлен." << endl;
}

void removeMedicalWorker(map<string, MedicalWorker>& workers) {
    string name;
    cout << "Введите имя медицинского работника, которого хотите удалить: ";
    getline(cin >> ws, name);

    auto it = workers.find(name);
    if (it != workers.end()) {
        workers.erase(it);
        cout << "Медицинский работник удален." << endl;
    }
    else {
        cout << "Медицинский работник с таким именем не найден." << endl;
    }
}

void editMedicalWorker(map<string, MedicalWorker>& workers) {
    string name;
    cout << "Введите имя медицинского работника, которого хотите отредактировать: ";
    getline(cin >> ws, name);

    auto it = workers.find(name);
    if (it != workers.end()) {
        MedicalWorker& worker = it->second;
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

void displayMedicalWorkers(const map<string, MedicalWorker>& workers) {
    if (workers.empty()) {
        cout << "Нет доступных данных о медицинских работниках." << endl;
    }
    else {
        cout << "Список медицинских работников:" << endl;
        for (const auto& pair : workers) {
            const MedicalWorker& worker = pair.second;
            cout << "Имя: " << worker.name << ", Специализация: " << worker.specialization << endl;
        }
    }
}

void saveMedicalWorkersToFile(const map<string, MedicalWorker>& workers, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла." << endl;
        return;
    }

    for (const auto& pair : workers) {
        const MedicalWorker& worker = pair.second;
        {
            file << "Имя: " << worker.name << ", Специализация: " << worker.specialization << endl;
        }

        cout << "Данные успешно сохранены в файл." << endl;
    }

    file.close();
}

void searchMedicalWorker(const map<string, MedicalWorker>& workers) {
    string name;
    cout << "Введите имя медицинского работника, которого хотите найти: ";
    getline(cin >> ws, name);

    auto it = workers.find(name);
    if (it != workers.end()) {
        const MedicalWorker& worker = it->second;
        cout << "Медицинский работник найден: " << endl;
        cout << "Имя: " << worker.name << ", Специализация: " << worker.specialization << endl;
    }
    else {
        cout << "Медицинский работник с таким именем не найден." << endl;
    }
}

void sortMedicalWorkers(map<string, MedicalWorker>& workers) {
    map<string, MedicalWorker> sortedWorkers(workers.begin(), workers.end());
    workers = sortedWorkers;
    cout << "Список медицинских работников отсортирован." << endl;
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
            cout << "Выход." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
            break;
        }
    }

    return 0;
}
