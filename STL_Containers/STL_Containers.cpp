#include <iostream>
#include <windows.h>
#include <vector>
#include <array>
#include <list>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

void viewing(string name, int speed, string special)
{
    cout << '|' << setw(20) << left << name << '|' << setw(10) << speed << '|' << setw(20) << special << "|" << endl;
    cout << "---------------------------------------------------\n";
}

class Network {
protected:
    int speed;
    string name;
public:
    Network(string name, int speed) : name(name), speed(speed) {}
    virtual void show() = 0;
    int get_speed() {
        return speed;
    }
    string get_name() {
        return name;
    }
    void set_speed(int new_speed) {
        speed = new_speed;
    }
    void set_name(string new_name) {
        name = new_name;
    }
};

class LocalNetwork : public Network {
private:
    string subnet;
public:
    LocalNetwork() : Network("",0), subnet("") {}
    LocalNetwork(string name, int speed, string subnet) : Network(name, speed), subnet(subnet) {}
    void show() override
    {
        viewing(name, speed, subnet);
    }
    friend ostream& operator<<(ostream& os, LocalNetwork &out) {
        os << '|' << setw(20) << left << out.name << '|' << setw(10) << out.speed << '|' << setw(20) << out.subnet << "|" << endl;
        os << "---------------------------------------------------\n";
        return os;
    }
    string get_subnet() {
        return this->subnet;
    }
};

class RegionalNetwork : public Network {
private:
    string region;
public:
    RegionalNetwork(string name, int speed, string region) : Network(name, speed), region(region) {}
    void show() override
    {
        viewing(name, speed, region);
    }
    friend ostream& operator<<(ostream& os, RegionalNetwork &out) {
        os << '|' << setw(20) << left << out.name << '|' << setw(10) << out.speed << '|' << setw(20) << out.region << "|" << endl;
        os << "---------------------------------------------------\n";
        return os;
    }
    int get_speed() {
        return speed;
    }
    string get_name() {
        return name;
    }
    void set_speed(int new_speed) {
        speed = new_speed;
    }
    void set_name(string new_name) {
        name = new_name;
    }
    bool operator>(RegionalNetwork& a) {
        if(this->get_speed()> a.get_speed())
            return true;
        return false;
    }
    bool operator<(RegionalNetwork &a) {
        if(this->get_speed()> a.get_speed())
            return false;
        return true;
    }
};


class GlobalNetwork : public Network {
private:
    string country;
public:
    GlobalNetwork(string name, int speed, string country) : Network(name, speed), country(country) {}
    void show() override
    {
        viewing(name, speed, country);
    }
    friend ostream& operator<<(ostream& os, GlobalNetwork &out) {
        os << '|' << setw(20) << left << out.name << '|' << setw(10) << out.speed << '|' << setw(20) << out.country << "|" << endl;
        os << "---------------------------------------------------\n";
        return os;
    }
};

int menu()
{

    int choice = 9;
    while (choice > 8)
    {
        system("cls");
        cout << "1)�������� ����\n2)����������� ��� ����\n3)�������� ����\n4)���������� ����\n5)�������������� ���� �� ��������\n6)����� ���� �� ��������\n7)������ ����� � ����\n8)�����\n��� �����:";
        cin >> choice;
        if (cin.good() && choice <= 8 && choice > 0)
        {
            break;
        }
        cin.clear();
        cout << "�������� �����.��������� �������.\n";
        cin.ignore(1024, '\n');
        system("pause");
    }
    return choice;
}

int check() {
    int number;
    cin >> number;
    while (cin.fail() || cin.get() != '\n' || number < 0) {
        {
            cout << "\nO����� �����.\n��������� �������:";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> number;
        }
    }
    return number;
}



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int num = 10;
    int count = 0;
    array<LocalNetwork, num> LAN;
    list<RegionalNetwork> MAN;
    vector<GlobalNetwork> WAN;
    ofstream File;
    int choice;
    while (true) {
        switch (menu()) {
        case 1:
            system("cls");
            cout << "�������� ����, ������� ������ ��������:\n1)���������\n2)�������������\n3)����������\n��� �����:";
            choice = check();
            switch (choice)
            {
            case 1:
            {
                if (count == 10) {
                    cout << "������� ������������ ���������� ��������� �����";
                    break;
                }
                string new_subnet;
                string new_name;
                int speed;
                cout << "������� �������� ����:";
                getline(cin, new_name);
                cout << "������� ��������(��/c) ����:";
                speed = check();
                cout << "������� �������� �������:";
                getline(cin, new_subnet);
                LocalNetwork new_item(new_name, speed, new_subnet);
                LAN[count] = new_item;
                cout << "���� ������� ��������\n";
                count++;
            };
            break;
            case 2:
            {
                string new_region;
                string new_name;
                int speed;
                cout << "������� �������� ����:";
                getline(cin, new_name);
                cout << "������� ��������(��/c) ����:";
                speed = check();
                cout << "������� �������� �������:";
                getline(cin, new_region);
                RegionalNetwork new_item(new_name, speed, new_region);
                MAN.push_back(new_item);
                cout << "���� ������� ��������\n";
            };
            break;
            case 3:
            {
                string new_country;
                string new_name;
                int speed;
                cout << "������� �������� ����:";
                getline(cin, new_name);
                cout << "������� ��������(��/c) ����:";
                speed = check();
                cout << "������� �������� ������:";
                getline(cin, new_country);
                WAN.emplace_back(new_name, speed, new_country);
                cout << "���� ������� ���������\n";
            };
            break;
            default:cout << "�������� �����\n";
                break;
            }
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "�������� ����, ������ ������� ������ �����������:\n1)���������\n2)������������\n3)����������\n��� �����:";
            choice = check();
            switch (choice) {
            case 1:
            {
                system("cls");
                if (count == 0) {
                    cout << "���� ��������� �����";
                    system("pause");
                    break;
                }
                cout << "---------------------------------------------------\n";
                cout << "|                ��������� ����                   |\n";
                cout << "---------------------------------------------------\n";
                cout << '|' << setw(20) << left << "�������� " << '|' << setw(10) << "�������� " << '|' << setw(20) << "�������� ������� |\n";
                cout << "--------------------------------------------------\n";
                for (int i = 0; i < count; i++) {
                    LAN[i].show();
                }
            };
            break;
            case 2:
            {
                system("cls");
                if (MAN.size() == 0) {
                    cout << "���� ������������ �����";
                    system("pause");

                    break;
                }
                cout << "---------------------------------------------------\n";
                cout << "|                ������������ ����                |\n";
                cout << "---------------------------------------------------\n";
                cout << '|' << setw(20) << left << "�������� " << '|' << setw(10) << "�������� " << '|' << setw(20) << "�������� ������� |\n";
                cout << "-----------------------------------------------\n";
                for (auto iter = MAN.begin(); iter != MAN.end(); iter++) {
                    iter->show();
                }
            };
            break;
            case 3:
            {
                system("cls");
                if (WAN.size() == 0) {
                    cout << "���� ������������ �����";
                    system("pause");

                    break;
                }
                cout << "---------------------------------------------------\n";
                cout << "|                 ���������� ����                 |\n";
                cout << "---------------------------------------------------\n";
                cout << '|' << setw(20) << left << "�������� " << '|' << setw(10) << "�������� " << '|' << setw(17) << "�������� ������ |\n";
                cout << "--------------------------------------------------\n";
                for (auto iter = WAN.begin(); iter != WAN.end(); iter++) {
                    iter->show();
                }
                break;
            };
            default: cout << "�������� �����\n";
                break;
            }
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "�������� ����, ������� ������ �������:\n1)��������� ����\n2)������������ ����\n3)���������� ����\n��� �����:";
            choice = check();
            switch(choice) {
            case 1:
            {
                system("cls");
                cout << "������� ����� ��������� ����, ������� ������ �������:";
                choice = check();
                if (choice < 0 || choice > count) {
                    cout << "���� � ����� ������� �����������\n";
                    system("pause");
                    break;
                }
                for (int i = choice; i < count; i++) {
                    LAN[i] = LAN[i + 1];
                }
                count--;
                cout << "���� ������� �������\n";
            };
                break;
            case 2:
            {
                system("cls");
                cout << "������� ����� ������������ ����, ������� ������ �������:";
                choice = check();
                if (choice < 0 || choice > MAN.size()) {
                    cout << "���� � ����� ������� �����������\n";
                    system("pause");
                    break;
                }
                auto iter = MAN.begin();
                advance(iter, choice - 1);
                MAN.erase(iter);
            };
                break;
            case 3: {
                system("cls");
                cout << "������� ����� ���������� ����, ������� ������ �������:";
                choice = check();
                if (choice < 0 || choice > WAN.size()) {
                    cout << "���� � ����� ������� �����������\n";
                    system("pause");
                    break;
                }
                auto iter = WAN.begin();
                iter +=(choice - 1);
                WAN.erase(iter,iter + 1);
            };
                break;
            }
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "�������� ����, ������� ������ ������������� �� ��������:\n1)���������� ����\n2)������������ ����\n3)���������� ����\n��� �����:";
            choice = check();
            switch (choice) {
            case 1:
            {
                if (count == 0) {
                    cout << "������ ��������� ����� ����";
                    system("pause");
                    break;
                }
                for (int i = 0; i < count; i++) {
                    for (int j = 0; j < count - 1; j++) {
                        if (LAN[j].get_subnet() > LAN[j + 1].get_subnet()) {
                            swap(LAN[j], LAN[j + 1]);
                        }
                    }
                }
            };
                break;
            case 2: {
                if (MAN.empty()) {
                    cout << "������ ������������ ����� ����";
                    system("pause");
                    break;
                }
                MAN.sort();
            };
                break;
            case 3: {
                if (WAN.empty()) {
                    cout << "������ ���������� ����� ����";
                    system("pause");
                    break;
                }
                for (int i = 0; i < WAN.size() - 1; i++) {
                    for (int j = 0; j < WAN.size() - 1; j++) {
                        if (WAN[j].get_speed() < WAN[j + 1].get_speed()) {
                            swap(WAN[j], WAN[j + 1]);
                        }
                    }
                }
            };
                break;
            }
            break;
        case 5:
            system("cls");
            cout << "�������� ����, ������� ������ ���������������:\n1)��������� ����\n2)������������ ����\n3)���������� ����\n��� �����:";
            choice = check();
            switch (choice) {
            case 1:
            {
                system("cls");
                cout << "������� ����� ��������� ���� ������� ������ ��������";
                choice = check();
                if (choice < 0 || choice > count) {
                    cout << "��������� ���� � �������� ������� �����������\n";
                    break;
                }
                cout << "������� ����� �������� ��� ������ ����: ";
                int speed;
                speed = check();
                LAN[choice - 1].set_speed(speed);
            };
                break;
            case 2:
            {
                system("cls");
                cout << "������� ����� ������������ ���� ������� ������ ��������: ";
                choice = check();
                if (choice < 0 || choice > MAN.size()) {
                    cout << "������������ ���� � �������� ������� �����������\n";
                    break;
                }
                cout << "������� ����� �������� ��� ������ ����: ";
                int speed;
                speed = check();
                auto iter = next(MAN.begin(), choice - 1);
                iter->set_speed(speed);
            };
                break;
            case 3:
            {
                system("cls");
                cout << "������� ����� ���������� ���� ������� ������ ��������";
                choice = check();
                if (choice < 0 || choice > WAN.size()) {
                    cout << "���������� ���� � �������� ������� �����������\n";
                    break;
                }
                cout << "������� ����� �������� ��� ������ ����: ";
                int speed;
                speed = check();
                WAN[choice - 1].set_speed(speed);
            };
                break;
            }
            system("pause");
            break;
        case 6:
            system("cls");
            cout << "�������� ����� ����� ����� ����������� �����:\n1)��������� ����\n2)������������ ����\n3)���������� ����\n��� �����:";
            choice = check();
            switch (choice) {
            case 1:
            {
                system("cls");
                cout << "������� �������� ����: ";
                string name;
                bool is_found = 0;
                getline(cin, name);
                for (int i = 0; i < count; i++) {
                    if (name == LAN[i].get_name()) {
                        is_found = 1;
                    }
                }
                if (is_found) {
                    cout << "--------------------------------------------------";
                    for (int i = 0; i < count; i++) {
                        if (name == LAN[i].get_name()) {
                            LAN[i].show();
                        }
                    }

                }
                else {
                    cout << "���� � ����� ��������� �� �������\n";
                    system("pause");
                }
            };
            break;
            case 2:
            {
                system("cls");
                cout << "������� �������� ����: ";
                string name;
                bool is_found = 0;
                getline(cin, name);
                for (auto iter = MAN.begin();iter != MAN.end(); iter++) {
                    if (name == iter->get_name()) {
                        is_found = 1;
                    }
                }
                if (is_found) {
                    cout << "--------------------------------------------------";
                    for (auto iter = MAN.begin();iter != MAN.end(); iter++) {
                        if (name == iter->get_name()) {
                            iter->show();
                        }
                    }

                }
                else {
                    cout << "���� � ����� ��������� �� �������\n";
                    system("pause");
                }
            };
            break;
            case 3:
            {
                system("cls");
                cout << "������� �������� ����: ";
                string name;
                bool is_found = 0;
                getline(cin, name);
                for (int i = 0; i < WAN.size(); i++) {
                    if (name == WAN[i].get_name()) {
                        is_found = 1;
                    }
                }
                if (is_found) {
                    cout << "--------------------------------------------------";
                    for (int i = 0; i < WAN.size(); i++) {
                        if (name == WAN[i].get_name()) {
                            WAN[i].show();
                        }
                    }

                }
                else {
                    cout << "���� � ����� ��������� �� �������\n";
                    system("pause");
                }
            };
            break;
            }
            system("pause");
            break;
        case 7:
            system("cls");
            File.open("Networks.txt");
            if (!File.is_open()) {
                cout << "������ �������� �����\n";
                system("pause");
                break;
            }
            File << "---------------------------------------------------\n";
            File << "|                ��������� ����                   |\n";
            File << "---------------------------------------------------\n";
            File << '|' << setw(20) << left << "�������� " << '|' << setw(10) << "�������� " << '|' << setw(20) << "�������� ������� |\n";
            File << "--------------------------------------------------\n";
            for (int i = 0; i < count; i++) {
                File << LAN[i];
            }
            File << "---------------------------------------------------\n";
            File << "|                ������������ ����                |\n";
            File << "---------------------------------------------------\n";
            File << '|' << setw(20) << left << "�������� " << '|' << setw(10) << "�������� " << '|' << setw(20) << "�������� ������� |\n";
            File << "-----------------------------------------------\n";
            for (auto iter = MAN.begin(); iter != MAN.end(); iter++) {
                File << *iter;
            }
            File << "---------------------------------------------------\n";
            File << "|                 ���������� ����                 |\n";
            File << "---------------------------------------------------\n";
            File << '|' << setw(20) << left << "�������� " << '|' << setw(10) << "�������� " << '|' << setw(20) << "�������� ������ |\n";
            File << "--------------------------------------------------\n";
            for (auto iter = WAN.begin(); iter != WAN.end(); iter++) {
                File << *iter;
            }
            cout << "������ ������� ��������\n";
            system("pause");
            File.close();
            break;
        case 8:return 0;
        default: cout << "�������� �����";
            break;
        }
    }
}