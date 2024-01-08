#include <iostream> 
#include <fstream> 
#include <vector> 
#include<Windows.h> 

// ����������� ������� ����� ��� �������� 
class Object {
public:
    virtual void input() = 0;
    virtual void output() = 0;
    virtual void edit() = 0;
    virtual Object* clone() = 0;
};

// �����-������� ��� �������� �������� 
class ObjectFactory {
public:
    virtual Object* create() = 0;
};

// ���������� ������ �������� 
class ObjectA : public Object {
public:
    void input() override {
        // ����� ���� ������ ��� ������� ���� A � ���������� 
        std::cout << "������� ������ ������� ���� A: ";
        std::cin >> data;
    }

    void output() override {
        // ����� ����� ������ ������� ���� A �� ����� 
        std::cout << "������ ���� A: " << data << std::endl;
    }

    void edit() override {
        // ����� �������������� ������ ������� ���� A 
        std::cout << "������� ����� ������ ������� ���� A: ";
        std::cin >> data;
    }

    Object* clone() override {
        // ����������� ������� ���� A 
        return new ObjectA(*this);
    }

private:
    int data;
};

class ObjectB : public Object {
public:
    void input() override {
        // ����� ���� ������ ��� ������� ���� B � ���������� 
        std::cout << "������� ������ ������� ���� B: ";
        std::cin >> data;
    }

    void output() override {
        // ����� ����� ������ ������� ���� B �� ����� 
        std::cout << "������ ���� B: " << data << std::endl;
    }

    void edit() override {
        // ����� �������������� ������ ������� ���� B 
        std::cout << "������� ����� ������ ������� ���� B: ";
        std::cin >> data;
    }

    Object* clone() override {
        // ����������� ������� ���� B 
        return new ObjectB(*this);
    }

private:
    float data;
};

// ���������� ������ ������ 
class ObjectAFactory : public ObjectFactory {
public:
    Object* create() override {
        return new ObjectA();
    }
};

class ObjectBFactory : public ObjectFactory {
public:
    Object* create() override {
        return new ObjectB();
    }
};

// ������� ����� ��������� 
class Editor {
public:
    int getNumberOfObjects() const {
        return objects.size();
    }
    void addObject(ObjectFactory* factory) {
        // �������� ������ ������� � ������� ������� � ���������� ��� � ������ �������� 
        Object* object = factory->create();
        objects.push_back(object);
    }

    void removeObject(int index) {
        // �������� ������� �� ������ �� ������� 
        delete objects[index];
        objects.erase(objects.begin() + index);
    }

    void editObject(int index) {
        // �������������� ������� �� ������� 
        objects[index]->edit();
    }

    void displayObjects() {
        // ����� ����������� ���� �������� �� ����� 
        for (int i = 0; i < objects.size(); ++i) {
            objects[i]->output();
        }
    }

    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (int i = 0; i < objects.size(); ++i) {
                file << "������ " << i + 1 << ": ";
                objects[i]->output();
            }
            file.close();
        }
        else {
            std::cout << "������ �������� �����." << std::endl;
        }
    }

private:
    std::vector<Object*> objects;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Editor editor;
    int choice;

    do {
        std::cout << "�������� ��������:" << std::endl;
        std::cout << "1. �������� ������" << std::endl;
        std::cout << "2. ������� ������" << std::endl;
        std::cout << "3. ������������� ������" << std::endl;
        std::cout << "4. ������� ���������� ��������" << std::endl;
        std::cout << "5. ��������� � ����" << std::endl;
        std::cout << "0. �����" << std::endl;
        std::cout << "������� ����� ��������: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1: {
            int objectType;
            std::cout << "�������� ��� ������� (1 - A, 2 - B): ";
            std::cin >> objectType;

            ObjectFactory* factory = nullptr;

            switch (objectType) {
            case 1:
                factory = new ObjectAFactory();
                break;
            case 2:
                factory = new ObjectBFactory();
                break;
            default:
                std::cout << "������������ ��� �������." << std::endl;
                break;
            }

            if (factory) {
                editor.addObject(factory);
                std::cout << "������ ������� ��������." << std::endl;
            }

            break;
        }
        case 2: {
            int index;
            std::cout << "������� ������ ������� ��� ��������: ";
            std::cin >> index;

            if (index >= 0 && index < editor.getNumberOfObjects()) {
                editor.removeObject(index);
                std::cout << "������ ������� ������." << std::endl;
            }
            else {
                std::cout << "������������ ������ �������." << std::endl;
            }

            break;
        }
        case 3: {
            int index;
            std::cout << "������� ������ ������� ��� ��������������: ";
            std::cin >> index;

            if (index >= 0 && index < editor.getNumberOfObjects()) {
                editor.editObject(index);
                std::cout << "������ ������� ��������������." << std::endl;
            }
            else {
                std::cout << "������������ ������ �������." << std::endl;
            }

            break;
        }
        case 4:
            editor.displayObjects();
            break;
        case 5: {
            std::string filename;
            std::cout << "������� ��� ����� ��� ����������: ";
            std::cin >> filename;
            editor.saveToFile(filename);
            break;
        }
        case 0:
            std::cout << "�����." << std::endl;
            break;
        default:
            std::cout << "������������ ����� ��������." << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}