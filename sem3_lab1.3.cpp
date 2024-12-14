#include <iostream>
using namespace std;

int main() {
    const int n = 10;
    short* arr = new short[n]; 

    cout << "Enter 10 elements of an array of type short (between -32768 and 32767):\n";
    for (int i = 0; i < n; ++i) {
        int input;
        cout << "Element " << i + 1 << ": ";
        cin >> input;

        // Проверка на диапазон значений типа short
        if (input < -32768 || input > 32767) {
            cout << "Error: Number is out of the range for type short. Program will terminate.\n";
            delete[] arr;  
            return 1;  
        }
        
        arr[i] = static_cast<short>(input);  // Присваиваем значение, если оно корректно
    }

    // Вывод содержимого массива
    cout << "\nArray contents:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Вывод адреса начала массива и расстояния каждого элемента от начала
    cout << "\nStarting address of the array: " << static_cast<void*>(arr) << "\n";
    cout << "Details of each element's position from the array start:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Element at index " << i << " with value " << arr[i] 
             << " is stored at address: " << static_cast<void*>(arr + i)
             << ". Offset from start: " << i << " elements.\n";
    }

    delete[] arr;  // Освобождение памяти
    return 0;
}
