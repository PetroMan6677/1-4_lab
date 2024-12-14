#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of array elements: ";
    cin >> n;

    int* arr = new int[n];  

    // Заполнение массива
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
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

    delete[] arr; 

    return 0;
}
