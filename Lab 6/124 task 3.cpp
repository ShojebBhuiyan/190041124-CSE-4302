#include <iostream>

using namespace std;

class RationalNumber
{
    private:
    int p;
    int q;
    
    void error()
    {
        if (!q)
        {
            cout << "Denominator can't be 0.\n";
            p = 0;
            q = 0;
        } 
    }

    public:
    RationalNumber()
        { };
    RationalNumber(int a, int b): p(a), q(b)
        { error(); }
    
    int getNumerator() const { return p; }
    int getDenominator() const { return q; }
    void setNumerator(int a) { p = a; }
    
    void setDenominator(int b) 
    { 
        q = b;
        error();
    }
    
    double convert_to_decimal()
    {
        if(!q) return (double) p / (double) q;
    }

    RationalNumber operator + (RationalNumber) const;
    RationalNumber operator - (RationalNumber) const;
    RationalNumber operator * (RationalNumber) const;
    RationalNumber operator / (RationalNumber) const;
};

RationalNumber RationalNumber::operator + (RationalNumber frac2) const
{
    return RationalNumber(p * frac2.q + frac2.p * q, q * frac2.q);
}

RationalNumber RationalNumber::operator - (RationalNumber frac2) const
{
    return RationalNumber(p * frac2.q - frac2.p * q, q * frac2.q);
}

RationalNumber RationalNumber::operator * (RationalNumber frac2) const
{
    return RationalNumber(p * frac2.p, q * frac2.q);
}

RationalNumber RationalNumber::operator / (RationalNumber frac2) const
{
    return RationalNumber(p * frac2.q, q * frac2.p);
}

int main()
{   
    RationalNumber demo;

    int n = 1, d = 2;

    demo.setDenominator(d);
    demo.setNumerator(n);

    cout << demo.getNumerator() << "/" << demo.getDenominator() << endl;

    n = 1, d = 2;
    
    RationalNumber demo2(1, 3), demo3;

    demo3 = demo + demo2;

    cout << demo3.getNumerator() << " " << demo3.getDenominator() << endl;

    demo3 = demo * demo2;

    cout << demo3.getNumerator() << " " << demo3.getDenominator() << endl;

    cout << demo3.convert_to_decimal();

    return 0;
}