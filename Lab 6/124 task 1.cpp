#include <iostream>
using namespace std;

class Counter
{
    private:
    int count;
    int step;

    public:
    Counter(): count(0), step(1)
        { }
    Counter(int c, int s): count(c), step(s)
        { }
    
    void setIncrementStep(int step_val = 1)
    {
        if (step_val < 0) cout << "Increment Step cannot be negative.\n";
        else step = step_val;
    }

    int getCount() const { return count; }

    void increment() { count += step; }

    void resetCount() { count = 0; }

    Counter operator + (Counter) const;
    Counter operator + (int) const;
    void operator += (Counter);
    Counter operator ++ ();
    Counter operator ++ (int);
};

Counter Counter::operator + (Counter c3) const
{
    return Counter(count + c3.count, min(step, c3.step));
}

Counter Counter::operator + (int var) const
{
    return Counter(count + var, step);
}

void Counter::operator += (Counter c2)
{
    count += c2.count;
}

Counter Counter::operator ++ ()
{
    return Counter(++count, step);
}

Counter Counter::operator ++ (int)
{
    return Counter(count++, step);
}

int main()
{
    Counter c1,c2,c3(3, 2);

    cout<<c1.getCount()<<' '<<c2.getCount()<<' '<<c3.getCount()<<endl;

    c1 += c3;

    //cout<<c1.getCount();

    int val = 5;

    c1 = c2 + val;

    //cout<<c1.getCount();

    c1++;
    ++c1;

    //cout<<c1.getCount();


    return 0;
}