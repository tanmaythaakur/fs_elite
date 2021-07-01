#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int andd = a;

    for (int i = a; i <= b; i++)
    {
        andd = andd & i;
        if (andd == 0)
            break;
    }

    cout << andd << endl;

    return 0;
}