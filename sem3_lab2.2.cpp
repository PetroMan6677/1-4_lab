#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore();
    }

    void putdata() const {
        cout << "Title: " << title << "\n";
        cout << "Price: $" << price << "\n";
    }
};

// Класс Sales для хранения общей стоимости проданных книг за последние три месяца
class Sales {
protected:
    float sales[3];

public:
    void getdata() {
        cout << "Enter total sales amount for the last 3 months:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Total sales for month " << i + 1 << ": ";
            cin >> sales[i];
        }
        cin.ignore();
    }

    void putdata() const {
        cout << "Total sales for the last 3 months:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": $" << sales[i] << "\n";
        }
    }
};

// Класс Book от Publication и Sales
class Book : public Publication, public Sales {
private:
    int page_count;

public:
    void getdata() {
        Publication::getdata();
        cout << "Enter number of pages: ";
        cin >> page_count;
        cin.ignore();
        Sales::getdata();  // Получаем данные о продажах
    }

    void putdata() const {
        Publication::putdata();
        cout << "Pages: " << page_count << "\n";
        Sales::putdata();  // Выводим данные о продажах
    }
};

// Класс Type от Publication и Sales
class Type : public Publication, public Sales {
private:
    float record_time;

public:
    void getdata() {
        Publication::getdata();
        cout << "Enter record time (in minutes): ";
        cin >> record_time;
        cin.ignore(); 
        Sales::getdata();  // Получаем данные о продажах
    }

    void putdata() const {
        Publication::putdata();
        cout << "Record time: " << record_time << " minutes\n";
        Sales::putdata();  // Выводим данные о продажах
    }
};

int main() {
    Book myBook;
    Type myType;

    cout << "Enter details for the book:\n";
    myBook.getdata();
    
    cout << "\nEnter details for the audiobook:\n";
    myType.getdata();

    cout << "\nDisplaying Book Details:\n";
    myBook.putdata();
    
    cout << "\nDisplaying Audiobook Details:\n";
    myType.putdata();

    return 0;
}
