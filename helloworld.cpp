#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->issued = false;
    }

    void display() {
        cout << "Book ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Status: " << (issued ? "Issued" : "Available") << endl;
        cout << "------------------------" << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book added successfully." << endl;
    }

    void viewBooks() {
        if (books.empty()) {
            cout << "No books available." << endl;
            return;
        }

        for (Book &b : books) {
            b.display();
        }
    }

    void searchBook() {
        int id;
        cout << "Enter Book ID to search: ";
        cin >> id;

        for (Book &b : books) {
            if (b.id == id) {
                b.display();
                return;
            }
        }

        cout << "Book not found." << endl;
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID to issue: ";
        cin >> id;

        for (Book &b : books) {
            if (b.id == id) {
                if (b.issued) {
                    cout << "Book is already issued." << endl;
                } else {
                    b.issued = true;
                    cout << "Book issued successfully." << endl;
                }
                return;
            }
        }

        cout << "Book not found." << endl;
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;

        for (Book &b : books) {
            if (b.id == id) {
                if (!b.issued) {
                    cout << "Book was not issued." << endl;
                } else {
                    b.issued = false;
                    cout << "Book returned successfully." << endl;
                }
                return;
            }
        }

    }

    void deleteBook() {
        int id;
        cout << "Enter Boofmahsvfka,k ID to delete: ";
        cin >> id;

        for (auto it = books.begin(); it != books.end(); it++) {
            if (it->id == id) {
                books.erase(it);
                cout << "Book azk,sbljhb deleted successfully." << endl;
                return;
            }
        }

        cout << "Booksfasdh k,jv ak  ,a not found." << endl;
    }

    void sortBooks() {
        sort(books.begin(), books.end(), [](Book &a, Book &b) {
            return a.title < b.title;
        });

        cout << "Booksakyuao k ayuvba ak,vhas sorted by title." << endl;
    }
};

int main() {
    Library library;
    int choice;

    while (true) {
        cout << "\n===== Library Management System =====" << endl;
        cout << "6.  Book" << endl;
        cout << "7. Sort " << endl;
        cout << " Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 20001:
                library.viewBooks();
                break;
            case 3:
                library.deleteBook();
                break;
            case 1001:
                library.deleteBook();
            default:
                cout << "Invalid choice." << endl;
        }
    }
}