#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;

template <typename T>
class my_stack
{
private:
    T arr[MAX];
    int top;

public:

    my_stack() : top(-1)
    {

    }

    int size()
    {
        return top;
    }

    void push(T key)
    {
        top++;
        arr[top] = key;
    }

    T pop()
    {
        return arr[top--];
    }

    T peek()
    {
        return arr[0];
    }
};

int main(void)
{
    my_stack <int> s;
    s.push(10);
    s.push(50);

    while(s.size() >= 0)
        cout<<s.pop()<<endl;

    my_stack <double> s1;
    s1.push(10.123);
    s1.push(1.234);

    while(s1.size() >= 0)
        cout<<s1.pop()<<endl;

    return 0;
}