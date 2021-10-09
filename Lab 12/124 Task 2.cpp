#include <bits/stdc++.h>
using namespace std;

template <typename T>
T amax(T arr[], int size, int n)
{
    T temp[size];

    copy(arr, arr + size, temp);
    sort(temp, temp + size, greater<T>());
    return temp[n - 1];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<amax(arr, n, 3)<<endl;

    double arr1[] = {1.11, 2.22, 3.33, 4.44, 5.55};
    n = sizeof(arr1)/sizeof(arr1[0]);
    cout<<amax(arr1, n, 4)<<endl;

    return 0;
}