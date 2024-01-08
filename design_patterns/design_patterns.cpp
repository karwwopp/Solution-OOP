#include <iostream> 
#include <fstream> 
#include <vector> 
#include<Windows.h> 

// Абстрактный базовый класс для объектов 
class Object {
public:
    virtual void input() = 0;
    virtual void output() = 0;
    virtual void edit() = 0;
    virtual Object* clone() = 0;
};

// Класс-фабрика для создания объектов 
class ObjectFactory {
public:
    virtual Object* create() = 0;
};

// Конкретные классы объектов 
class ObjectA : public Object {
public:
    void input() override {
        // Здесь ввод данных для объекта типа A с клавиатуры 
        std::cout << "Введите данные объекта типа A: ";
        std::cin >> data;
    }

    void output() override {
        // Здесь вывод данных объекта типа A на экран 
        std::cout << "Объект типа A: " << data << std::endl;
    }

    void edit() override {
        // Здесь редактирование данных объекта типа A 
        std::cout << "Введите новые данные объекта типа A: ";
        std::cin >> data;
    }

    Object* clone() override {
        // Копирование объекта типа A 
        return new ObjectA(*this);
    }

private:
    int data;
};

class ObjectB : public Object {
public:
    void input() override {
        // Здесь ввод данных для объекта типа B с клавиатуры 
        std::cout << "Введите данные объекта типа B: ";
        std::cin >> data;
    }

    void output() override {
        // Здесь вывод данных объекта типа B на экран 
        std::cout << "Объект типа B: " << data << std::endl;
    }

    void edit() override {
        // Здесь редактирование данных объекта типа B 
        std::cout << "Введите новые данные объекта типа B: ";
        std::cin >> data;
    }

    Object* clone() override {
        // Копирование объекта типа B 
        return new ObjectB(*this);
    }

private:
    float data;
};

// Конкретные классы фабрик 
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

// Главный класс редактора 
class Editor {
public:
    int getNumberOfObjects() const {
        return objects.size();
    }
    void addObject(ObjectFactory* factory) {
        // Создание нового объекта с помощью фабрики и добавление его в список объектов 
        Object* object = factory->create();
        objects.push_back(object);
    }

    void removeObject(int index) {
        // Удаление объекта из списка по индексу 
        delete objects[index];
        objects.erase(objects.begin() + index);
    }

    void editObject(int index) {
        // Редактирование объекта по индексу 
        objects[index]->edit();
    }

    void displayObjects() {
        // Вывод содержимого всех объектов на экран 
        for (int i = 0; i < objects.size(); ++i) {
            objects[i]->output();
        }
    }

    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (int i = 0; i < objects.size(); ++i) {
                file << "Объект " << i + 1 << ": ";
                objects[i]->output();
            }
            file.close();
        }
        else {
            std::cout << "Ошибка открытия файла." << std::endl;
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
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Добавить объект" << std::endl;
        std::cout << "2. Удалить объект" << std::endl;
        std::cout << "3. Редактировать объект" << std::endl;
        std::cout << "4. Вывести содержимое объектов" << std::endl;
        std::cout << "5. Сохранить в файл" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Введите номер действия: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1: {
            int objectType;
            std::cout << "Выберите тип объекта (1 - A, 2 - B): ";
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
                std::cout << "Некорректный тип объекта." << std::endl;
                break;
            }

            if (factory) {
                editor.addObject(factory);
                std::cout << "Объект успешно добавлен." << std::endl;
            }

            break;
        }
        case 2: {
            int index;
            std::cout << "Введите индекс объекта для удаления: ";
            std::cin >> index;

            if (index >= 0 && index < editor.getNumberOfObjects()) {
                editor.removeObject(index);
                std::cout << "Объект успешно удален." << std::endl;
            }
            else {
                std::cout << "Некорректный индекс объекта." << std::endl;
            }

            break;
        }
        case 3: {
            int index;
            std::cout << "Введите индекс объекта для редактирования: ";
            std::cin >> index;

            if (index >= 0 && index < editor.getNumberOfObjects()) {
                editor.editObject(index);
                std::cout << "Объект успешно отредактирован." << std::endl;
            }
            else {
                std::cout << "Некорректный индекс объекта." << std::endl;
            }

            break;
        }
        case 4:
            editor.displayObjects();
            break;
        case 5: {
            std::string filename;
            std::cout << "Введите имя файла для сохранения: ";
            std::cin >> filename;
            editor.saveToFile(filename);
            break;
        }
        case 0:
            std::cout << "Выход." << std::endl;
            break;
        default:
            std::cout << "Некорректный номер действия." << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}