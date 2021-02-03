#include <bits/stdc++.h>
using namespace std;

vector<int> makeIntArr(string &s)
{
    vector<int> arr;
    int i = 0;
    string temp;

    while (i < s.length())
    {
        if (s[i] == ' ')
        {
            arr.push_back(stoi(temp));
            temp = "";
        }
        else
        {
            temp += s[i];
        }
        i++;
    }
    arr.push_back(stoi(temp));

    return arr;
}

int main()
{
    string temp;
    getline(cin, temp);

    vector<int> arr = makeIntArr(temp);
    int n = arr.size();
    vector<int> maxleft, maxright; // nearest greater to left/right
    int maxval = -1;

    for (int i = 0; i < n; i++)
    {
        if (maxval == -1)
        {
            maxleft.push_back(-1);
            maxval = arr[i];
            continue;
        }
        maxval = max(maxval, arr[i]);
        maxleft.push_back(maxval);
    }
    
    maxval = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (maxval == -1)
        {
            maxright.push_back(-1);
            maxval = arr[i];
            continue;
        }
        maxval = max(arr[i], maxval);
        maxright.push_back(maxval);
    }
    reverse(maxright.begin(), maxright.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxleft[i] == -1 || maxright[i] == -1)
            continue;
        ans += min(maxleft[i], maxright[i]) - arr[i];
    }
    cout << ans << endl;

    return 0;
}