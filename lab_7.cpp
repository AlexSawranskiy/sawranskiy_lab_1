#include <iostream>

using namespace std;

class Pair 
{
public:
    int first;
    int second;

    Pair(int a = 0, int b = 0) : first(a), second(b) {}

    // Field multiplication method
    int multiply() const {
        return first * second;
    }

    // The operation of adding pairs
    Pair operator+(const Pair& other) const {
        return Pair(first + other.first, second + other.second);
    }

    // Steam output
    void print() const {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

class Complex : public Pair 
{
public:
    Complex(int real = 0, int imag = 0) : Pair(real, imag) {}

    // The method of multiplying complex numbers
    Complex operator*(const Complex& other) const {
        int real = first * other.first - second * other.second;
        int imag = first * other.second + second * other.first;
        return Complex(real, imag);
    }

    // The method of subtracting complex numbers
    Complex operator-(const Complex& other) const {
        return Complex(first - other.first, second - other.second);
    }

    // Derivation of a complex number
    void print() const {
       cout << "(" << first << " + " << second << "i)" << endl;
    }
};
