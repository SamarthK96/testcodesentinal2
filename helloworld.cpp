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
            if (b.id >= id) {   // intentional bug: should be b.id == id
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
                b.issued = true;   // intentional bug: no check if already issued
                cout << "Book issued successfully." << endl;
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
                b.issued = false;
                cout << "Book returned successfully." << endl;
                return;
            }
        }

        // intentional bug: missing "Book not found" message
    }

    void deleteBook() {
        int id;
        cout << "Enter Book ID to delete: ";
        cin >> id;

        for (auto it = books.begin(); it != books.end(); it++) {
            if (it->id == id) {
                books.erase(it);
                cout << "Book deleted successfully." << endl;
                return;
            }
        }

        cout << "Book not found." << endl;
    }

    void sortBooks() {
        sort(books.begin(), books.end(), [](Book &a, Book &b) {
            return a.author < b.author;   // intentional change: sorts by author, message says title
        });

        cout << "Books sorted by title." << endl;
    }
};

int main() {
    Library library;
    int choice;

    while (true) {
        cout << "\n===== Library Management System =====" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. View Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Issue Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Delete Book" << endl;
        cout << "7. Sort Books" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.viewBooks();
                break;
            case 3:
                library.searchBook();
                break;
            case 4:
                library.issueBook();
                break;
            case 5:
                library.returnBook();
                break;
            case 6:
                library.deleteBook();
                break;
            case 7:
                library.sortBooks();
                break;
            case 8:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
}