#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
    int sz = arr.size();

    cout << "[";
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i];
        if (i != sz - 1)
            cout << ", ";
    }
    cout << "]\n";
}

int main()
{

    return 0;
}