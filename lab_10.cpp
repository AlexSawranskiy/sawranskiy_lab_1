#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// A class for handling exceptions
class Error 
{
public:
    Error(const string& message) : message(message) {}
    const char* what() const noexcept { return message.c_str(); }
private:
    string message;
};

// Template class Vector
template <typename T>
class Vector 
{
private:
    vector<T> data;

public:
    // Access by index
    T& operator[](size_t index) 
    {
        if (index >= data.size()) 
        {
            throw Error("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const 
    {
        if (index >= data.size()) {
            throw Error("Index out of range");
        }
        return data[index];
    }

    // Determining the size of a vector
    size_t operator()() const 
    {
        return data.size();
    }

    // Adding an item
    void push_back(const T& value) 
    {
        data.push_back(value);
    }

    // The prefix form of the operator --
    Vector& operator--() 
    {
        if (!data.empty()) 
        {
            data.erase(data.begin());
        }
        else 
        {
            throw Error("Cannot remove from an empty vector");
        }
        return *this;
    }

    // The postfix form of the operator --
    Vector operator--(int) 
    {
        Vector temp = *this;
        if (!data.empty()) 
        {
            data.pop_back();
        }

        else {
            throw Error("Cannot remove from an empty vector");
        }
        return temp;
    }

    // Derivation of vector elements
    void print() const 
    {
        for (const T& value : data) 
        {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main() 
{
    try 
    {
        // Creating a Vector object with elements of type int
        Vector<int> v_int;
        v_int.push_back(10);
        v_int.push_back(20);
        v_int.push_back(30);

        cout << "Initial int vector: ";
        v_int.print();

        // Access by index
        cout << "Element at index 1: " << v_int[1] << endl;

        // Determining the size of a vector
        cout << "Int vector size: " << v_int() << endl;

        // The prefix form of the operator --
        --v_int;
        cout << "After prefix -- : ";
        v_int.print();

        // The postfix form of the operator --
        v_int--;
        cout << "After postfix --: ";
        v_int.print();

        // Creating a Vector object with double elements
        Vector<double> v_double;
        v_double.push_back(1.1);
        v_double.push_back(2.2);
        v_double.push_back(3.3);

        cout << "Initial double vector: ";
        v_double.print();

        // Access by index
        cout << "Element at index 1: " << v_double[1] << endl;

        // Determining the size of a vector
        cout << "Double vector size: " << v_double() << endl;

        // The prefix form of the operator --
        --v_double;
        cout << "After prefix -- : ";
        v_double.print();

        // The postfix form of the operator --
        v_double--;
        cout << "After postfix --: ";
        v_double.print();
    }
    catch (const Error& e) 
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
