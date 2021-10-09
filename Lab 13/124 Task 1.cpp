#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[4];
    set <int> s;

    for(int i = 0; i < 8; i++)
    {
        if (i % 2)
            s.insert(i);
            
        else
            arr[i/2] = i;
    }

    vector <int> x(8);
    merge(arr, arr + 4, s.begin(), s.end(), x.begin());

    for(int i = 0; i < x.size(); i++)
        cout<<x[i]<<" ";

    return 0;
}