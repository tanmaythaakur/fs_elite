#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    unordered_set<string> sett;
    int n = str.size();
    string pref, suff;
    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {
            pref = str.substr(i, n - j);
            suff = str.substr(n - j);
            // cout << pref << " " << suff << endl;
            if (pref.size() > 0)
                sett.insert(pref);
            if (suff.size() > 0)
                sett.insert(suff);
        }
    }

    cout << sett.size() << endl;

    return 0;
}