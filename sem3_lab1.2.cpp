#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
    const int n = 10;
    double* arr = new double[n];

    while (true) {
        cout << "Enter 10 elements of an array of type double (with decimal point):\n";
        bool validInput = true;

        for (int i = 0; i < n; ++i) {
            string input;
            cout << "Element " << i + 1 << ": ";
            cin >> input;

            // Проверка на присутствие десятичной точки в вводе
            if (input.find('.') == string::npos) {
                cout << "Invalid input! Please enter a decimal (double) value.\n";
                validInput = false;
                break;
            }

            // Преобразование строки в double
            try {
                arr[i] = stod(input);
            } catch (const invalid_argument&) {
                cout << "Invalid input! Please enter a valid decimal (double) value.\n";
                validInput = false;
                break;
            }
        }

        // Если ввод корректный, выходим из цикла
        if (validInput) break;

        // Очистка буфера ввода
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Вывод содержимого массива
    cout << "\nArray contents:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Вывод адреса начала массива
    cout << "\nStarting address of the array: " << arr << "\n";

    // Вывод адресов каждого элемента и расстояний от начала массива
    cout << "\nConclusion about the distance of each element:\n";
    for (int i = 0; i < n; ++i) {
        cout << "At index " << i << ", value: " << arr[i]
             << " is stored at address: " << (arr + i)
             << ". Offset from start: " << i << " elements.\n";
    }

    // Освобождение памяти
    delete[] arr;

    return 0;
}
