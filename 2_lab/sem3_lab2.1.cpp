#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    // Метод для ввода данных о публикации
    void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore();
    }

    // Метод для вывода данных о публикации
    void putdata() const {
        cout << "Title: " << title << "\n";
        cout << "Price: $" << price << "\n";
    }
};

// Класс Book от Publication
class Book : public Publication {
private:
    int page_count;

public:
    // Метод для ввода данных о книге
    void getdata() {
        Publication::getdata();
        cout << "Enter number of pages: ";
        cin >> page_count;
        cin.ignore();
    }

    // Метод для вывода данных о книге
    void putdata() const {
        Publication::putdata();
        cout << "Pages: " << page_count << "\n";
    }
};

// Класс Type от Publication
class Type : public Publication {
private:
    float record_time;

public:
    // Метод для ввода данных о аудиокниге
    void getdata() {
        Publication::getdata();
        cout << "Enter record time (in minutes): ";
        cin >> record_time;
        cin.ignore(); 
    }

    // Метод для вывода данных о аудиокниге
    void putdata() const {
        Publication::putdata();
        cout << "Record time: " << record_time << " minutes\n";
    }
};

int main() {
    Book myBook;
    Type myType;

    cout << "Enter details for the book:\n";
    myBook.getdata();
    
    cout << "\nEnter details for the audio type:\n";
    myType.getdata();

    cout << "\nDisplaying Book Details:\n";
    myBook.putdata();
    
    cout << "\nDisplaying Audiobook Details:\n";
    myType.putdata();

    return 0;
}
