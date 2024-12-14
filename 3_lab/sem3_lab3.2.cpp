#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

// Базовый класс
class Base {
public:
    virtual void show() const {
        cout << "Base" << endl;
    }
    virtual ~Base() = default;
};

// Производный класс
class Derived : public Base {
public:
    void show() const override {
        cout << "Derived" << endl;
    }
};

// Хранилище объектов
vector<shared_ptr<Base>> storage;

// Функция для добавления объектов в хранилище
void add(const shared_ptr<Base>& obj) {
    storage.push_back(obj);
}

int main() {
    srand(time(nullptr));

    // Создание объектов
    for (int i = 0; i < 10; ++i) { // Создаем 10 объектов случайного типа
        if (rand() % 2 == 0) {
            // Четное случайное число — создаем Base
            add(make_shared<Base>());
        } else {
            // Нечетное случайное число — создаем Derived
            add(make_shared<Derived>());
        }
    }

    // Демонстрация поведения
    cout << "Objects in storage behave as follows:" << endl;
    for (const auto& obj : storage) {
        obj->show();
    }

    // Освобождение ресурсов
    storage.clear();
    cout << "All resources are freed." << endl;

    return 0;
}
