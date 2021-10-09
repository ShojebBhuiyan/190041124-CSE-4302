#include <bits/stdc++.h>

using namespace std;

namespace my_namespace
{
    double y = 6.4;
}

int main()
{
    double y = 4.5;
    cout << y << endl;
    cout << my_namespace::y << endl;
    
    return 0;
}