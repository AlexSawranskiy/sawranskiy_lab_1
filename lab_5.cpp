#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    vector<string> pages;

public:
    // The default constructor
    Book() : title("Unknown"), author("Unknown"), year(0), pages(1, "Empty page") {}

    // Constructor with parameters
    Book(const string& title, const string& author, int year, const vector<string>& pages)
        : title(title), author(author), year(year), pages(pages) {}

    // Destructor
    ~Book() {}

    // Indexing operator
    string& operator[](size_t index) 
    {
        return pages.at(index);
    }

    const string& operator[](size_t index) const 
    {
        return pages.at(index);
    }

    // Function call operator
    void operator()() const 
    {
        cout << "Title: " << title << ", Author: " << author << ", Year: " << year << endl;
    }

    // Input operator
    friend istream& operator>>(istream& is, Book& book) 
    {
        cout << "Enter the title of the book: ";
        getline(is, book.title);

        cout << "Enter the author of the book: ";
        getline(is, book.author);
        cout << "Enter the year of publication: ";

        is >> book.year;
        is.ignore();

        cout << "Enter the number of pages: ";
        size_t pageCount;

        is >> pageCount;
        is.ignore();
        
        book.pages.resize(pageCount);

        for (size_t i = 0; i < pageCount; ++i) {
            cout << "Enter the page text " << i + 1 << ": ";
            getline(is, book.pages[i]);
        }
        return is;
    }

    // Output operator
    friend ostream& operator<<(ostream& os, const Book& book) 
    {
        os << "Title: " << book.title << "\nAuthor: " << book.author << "\nYear: " << book.year << "\nPages:\n";
        for (size_t i = 0; i < book.pages.size(); ++i) 
        {
            os << "Page " << i + 1 << ": " << book.pages[i] << "\n";
        }
        return os;
    }
};

int main() {
    // Dynamic creation of a book object
    Book* book1 = new Book("C++ Programming", "Bjarne Stroustrup", 1985, { "Introduction", "Classes", "Inheritance", "Templates" });
    (*book1)();
    cout << "Page 1: " << (*book1)[0] << endl;

    // Using the derivation operator
    cout << *book1 << endl;

    // Using the input operator
    Book book2;
    cin >> book2;
    cout << book2 << endl;

    // Work with an array of objects
    size_t bookCount;

    cout << "Enter the number of books: ";
    cin >> bookCount;
    cin.ignore();

    Book* books = new Book[bookCount];
    for (size_t i = 0; i < bookCount; ++i) 
    {
        cin >> books[i];
    }

    for (size_t i = 0; i < bookCount; ++i) 
    {
        cout << books[i] << endl;
    }

    // Cleaning memory
    delete book1;
    delete[] books;

    return 0;
}
