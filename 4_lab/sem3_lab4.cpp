#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>
#include <typeinfo>

using namespace std;

// Базовый класс средство передвижения
class Vehicle {
public:
    virtual void show() const = 0; 
    virtual ~Vehicle() = default; 
};

// Производный класс велосипед
class Bicycle : public Vehicle {
public:
    void show() const override {
        cout << "Bicycle\n";
    }
};

// Производный класс автомобиль
class Car : public Vehicle {
public:
    void show() const override {
        cout << "Car\n";
    }
};

// Производный класс грузовик
class Truck : public Vehicle {
public:
    void show() const override {
        cout << "Truck\n";
    }
};

// Шаблонный класс для хранения массива указателей на объекты
template <typename T>
class Storage {
    vector<shared_ptr<T>> data; // Хранилище указателей
public:
    // Метод добавления объекта
    void add(shared_ptr<T> obj) {
        data.push_back(obj);
    }

    // Перегрузка оператора []
    shared_ptr<T> operator[](size_t index) const {
        if (index >= data.size())
            throw out_of_range("Index out of range");
        return data[index];
    }

    size_t size() const {
        return data.size();
    }
};

int main() {
    try {
        // Хранилище для объектов Vehicle
        Storage<Vehicle> storage;

        // Создание объектов
        storage.add(make_shared<Bicycle>());
        storage.add(make_shared<Car>());
        storage.add(make_shared<Truck>());

        for (size_t i = 0; i < storage.size(); ++i) {
            storage[i]->show();
        }

        // Обработка исключения при некорректном индексе
        try {
            storage[10]->show();
        } catch (const out_of_range& e) {
            cerr << "Caught exception: " << e.what() << "\n";
        }

        // Обработка underflow_error
        int result = -1; // Пример вычисления
        if (result < 0)
            throw underflow_error("Negative value encountered in computation!");

    } catch (const underflow_error& e) {
        cerr << "Underflow error: " << e.what() << "\n";
    } catch (const exception& e) {
        cerr << "General exception: " << e.what() << "\n";
    }

    cout << "Program completed successfully.\n";
    return 0;
}
