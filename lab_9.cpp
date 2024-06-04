#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Vector {
private:
    vector<int> data;

public:
    // Access by index
    int& operator[](size_t index) 
    {
        if (index >= data.size()) 
        {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    const int& operator[](size_t index) const 
    {
        if (index >= data.size()) 
        {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    // Determining the size of a vector
    size_t operator()() const 
    {
        return data.size();
    }

    // Adding an item
    void push_back(int value) 
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
        return temp;
    }

    // Derivation of vector elements
    void print() const 
    {
        for (int value : data) 
        {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main() 
{
    Vector v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "Initial vector: ";
    v.print();

    // Access by index
    cout << "Element at index 1: " << v[1] << endl;

    // Determining the size of a vector
    cout << "Vector size: " << v() << endl;

    // Prefix form operator --
    --v;
    cout << "After prefix -- : ";
    v.print();

    // The postfix form of the operator --
    v--;
    cout << "After postfix --: ";
    v.print();

    return 0;
}