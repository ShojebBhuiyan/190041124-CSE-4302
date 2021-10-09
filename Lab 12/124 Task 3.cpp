#include <bits/stdc++.h>
using namespace std;
const int MAX = 2;

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

    class Overflow
    {
    };

    class Underflow
    {
    };

    int size()
    {
        return top;
    }

    void push(T key)
    {
        if (top == MAX - 1)
            throw Overflow();
        else
        {
            top++;
            arr[top] = key;
        }
    }

    T pop()
    {
        if (top == -1)
            throw Underflow();
        else

            return arr[top--];
    }

    T peek()
    {
        if (top == -1)
            return Underflow();
        else
            return arr[0];
    }
};

int main()
{
    try
    {
        my_stack <int> s;
        s.push(10);
        s.push(50);

        while(s.size() >= 0)
            cout<<s.pop()<<endl;

        //s.pop();

        my_stack <double> s1;
        s1.push(10.123);
        s1.push(1.234);
        //s1.push(3.99);

        while(s1.size() >= 0)
            cout<<s1.pop()<<endl;
    }

    catch(my_stack <int>::Overflow)
    {
        cout<<"Exception : Stack Overflow"<<endl;
    }

    catch(my_stack <int>::Underflow)
    {
        cout<<"Exception : Stack Underflow"<<endl;
    }

    catch(my_stack <double>::Overflow)
    {
        cout<<"Exception : Stack Overflow"<<endl;
    }

    catch(my_stack <double>::Underflow)
    {
        cout<<"Exception : Stack Underflow"<<endl;
    }

    return 0;
}