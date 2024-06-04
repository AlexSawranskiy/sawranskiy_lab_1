#include <iostream>

using namespace std;

// Abstract base class Number
class Number 
{
public:
    virtual ~Number() {}
    virtual Number* add(const Number* other) const = 0; // A purely virtual addition function
    virtual void print() const = 0; // A virtual function for derivation
};

class Rational : public Number 
{
private:
    int numerator;
    int denominator;

public:
    Rational(int num, int denom) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
    }

    Number* add(const Number* other) const override {
        const Rational* r = dynamic_cast<const Rational*>(other);
        if (r) {
            int common_denominator = denominator * r->denominator;
            int new_numerator = numerator * r->denominator + r->numerator * denominator;
            return new Rational(new_numerator, common_denominator);
        }
        return nullptr;
    }

    void print() const override {
        cout << numerator << "/" << denominator << endl;
    }
};

class Decimal : public Number {
private:
    double value;

public:
    Decimal(double val) : value(val) {}

    Number* add(const Number* other) const override 
    {
        const Decimal* d = dynamic_cast<const Decimal*>(other);
        if (d) 
        {
            return new Decimal(value + d->value);
        }
        return nullptr;
    }

    void print() const override 
    {
        cout << value << endl;
    }
};

int main() {
    try {
        // Creation of Rational objects
        Rational r1(1, 2); // 1/2
        Rational r2(1, 3); // 1/3

        // Addition of rational numbers
        Number* result_rational = r1.add(&r2);
        cout << "Rational addition result: ";
        result_rational->print();
        delete result_rational; // Freeing memory

        // Creation of Decimal objects
        Decimal d1(1.5); // 1.5
        Decimal d2(2.3); // 2.3

        // Adding decimal fractions
        Number* result_decimal = d1.add(&d2);
        cout << "Decimal addition result: ";
        result_decimal->print();
        delete result_decimal; // Freeing memory
    }
    catch (const invalid_argument& e) {
       cerr << "Error: " << e.what() << endl;
    }

    return 0;
}