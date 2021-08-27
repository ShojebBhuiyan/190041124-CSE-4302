#include <iostream>

using namespace std;

class Count
{
    private:
        int count;
        int val;

    /*
        Count(Count& c): val(24) //Copy Initialization
        {
            count = c.count;
        }

        Count operator = (const Count& c) //Assignment Operator
        {
            count = c.count;
            return *this;
        }
    */
    public:
        Count():count(0), val(0)
        { }

        Count(int a, int b):count(a), val(b)
        { }

        Count(Count& c): val(24) //Copy Initialization
        {
            count = c.count;
        }

        Count operator = (const Count& c) //Assignment Operator
        {
            count = c.count;
            return *this;
        }

        void display()
        {
            cout << "Count: " << count << " Value: " << val << endl;
        }

};

int main()
{
    Count c1, c2(3,2);
    c1.display();
    c2.display();
    c1 = c2;
    c1.display();
    Count c3 = c2;
    c3.display();
    return 0;
}