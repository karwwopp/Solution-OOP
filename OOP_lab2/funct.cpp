#include "Header.h"

vector<shared_ptr<File>> allFiles;
vector<shared_ptr<User>> allUsers;

void CreateUserPrompt() {
    cout << "������� ��� ������������: \n";
    string name;
    getline(cin, name);
    allUsers.push_back(make_shared<User>(name));
}

void CreateFilePrompt() {
    cout << "������� ��� �����:\n";
    string name;
    getline(cin, name);
    cout << "������� ������ �����:\n";
    string format;
    getline(cin, format);

    auto file = make_shared<File>(name, format);
    file->askForContent();
    allFiles.push_back(file);
}

void printFiles() {
    cout << left << setw(15) << "��� �����"
        << left << setw(15) << "������ �����"
        << left << setw(30) << "���������� �����" << endl;

    for (const auto& file : allFiles) {
        cout << left << setw(15) << file->getName()
            << left << setw(15) << file->getFormat()
            << left << setw(30) << file->getContent() << endl;
    }
}

void ConvertFilePrompt() {
    cout << "������� ��� ����� ��� �����������:\n";
    string name;
    getline(cin, name);

    auto it = find_if(allFiles.begin(), allFiles.end(), [&](const shared_ptr<File>& file) { return file->getName() == name; });
    if (it == allFiles.end()) {
        cout << "���� � ������ " << name << " �� ������.\n";
        return;
    }
    cout << "������� �������� ������:\n";
    string sourceFormat;
    getline(cin, sourceFormat);

    cout << "������� ������, � ������� ������ ��������������:\n";
    string destinationFormat;
    getline(cin, destinationFormat);

    FormatConverter converter(sourceFormat, destinationFormat);
    converter.convert(*it);

    cout << "����������� ���������.\n";
}

void EditFilePrompt() {
    cout << "������� ��� ����� ��� ��������������:\n";
    string name;
    getline(cin, name);

    auto it = find_if(allFiles.begin(), allFiles.end(), [&](const shared_ptr<File>& file) { return file->getName() == name; });
    if (it == allFiles.end()) {
        cout << "���� � ������ " << name << " �� ������.\n";
        return;
    }

    cout << "������� ����� ���������� �����:\n";
    string newContent;
    getline(cin, newContent);

    (*it)->editContent(newContent);

    cout << "���������� ����� ���������.\n";
}

int isnumber() {
    int n;
    while (1) {
        while (!(cin >> n)) {
            cin.clear();
            cin.ignore(1024, '\n');   cout << "�������� ����. ���������� �����! " << endl;
        }  if (cin.get() != '\n') {
            cout << "�������� ����. ���������� �����! " << endl;   cin.clear();
            cin.ignore(1025, '\n');   continue;
        }
        if (n < 0 || n > 5) {
            cout << "�������� ����. ���������� �����! " << endl;
            continue;
        }
        else break;
    }
    return n;
}
