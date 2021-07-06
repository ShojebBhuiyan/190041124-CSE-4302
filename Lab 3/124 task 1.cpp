#include <iostream>

using namespace std;

class RationalNumber
{
    private:
        int numerator;
        int denominator;
    
    public:
        void assign(int numerator, int denominator)
        {
            this->numerator = numerator;
            if (denominator) this->denominator = denominator;
            else cout << "Denominator can't be 0.\n";
        }
        
        double convert()
        {
            return (double)numerator / (double)denominator;
        }

        void invert()
        {
            if (numerator) swap(this->numerator, this->denominator);
            else cout << "Numerator is 0 which is invalid as a denominator.\n";
        }

        void print()
        {
            cout << "The Rational Number is " << numerator << "/" << denominator << '\n';
        }
};

int main()
{
    RationalNumber test;
    test.assign(3,5);
    test.print();
    cout << test.convert() << '\n';

    test.invert();
    test.print();
    cout << test.convert() << '\n';

    return 0;
}