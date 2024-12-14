#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Базовый класс Detail
class Detail {
protected:
    string name;

    // Защищенный конструктор
    Detail(const string& name) : name(name) {}

public:
    virtual ~Detail() = default;

    // Чисто виртуальный метод для полиморфизма
    virtual void display() const = 0;

    // Дружественная шаблонная функция
    template <typename T, typename... Args>
    friend shared_ptr<T> create(Args&&... args);
};

// Производный класс Assembly
class Assembly : public Detail {
protected:
    int components;

    // Защищенный конструктор
    Assembly(const string& name, int components) 
        : Detail(name), components(components) {}

public:
    void display() const override {
        cout << "Assembly: " << name << ", Components: " << components << "\n";
    }

    // Дружественная шаблонная функция
    template <typename T, typename... Args>
    friend shared_ptr<T> create(Args&&... args);
};

// Шаблонная дружественная функция
template <typename T, typename... Args>
shared_ptr<T> create(Args&&... args) {
    static_assert(is_base_of<Detail, T>::value, "T must inherit from Detail");
    return shared_ptr<T>(new T(forward<Args>(args)...));
}

int main() {
    // Вектор для хранения
    vector<shared_ptr<Detail>> storage;

    // Создание объектов через дружественную функцию
    storage.push_back(create<Assembly>("Wheel", 10));
    storage.push_back(create<Assembly>("Engine", 20));

    for (const auto& detail : storage) {
        detail->display();
    }

    return 0;
}
