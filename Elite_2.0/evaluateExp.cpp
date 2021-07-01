#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
void print(vector<string> ans)
{
    cout << "[";
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i];
        if(i != ans.size()-1)
            cout << ", ";
    }
    cout << "]\n";
}


void solve(string str, int idx, string curr)
{
    if(idx >= str.size()) {
        ans.push_back(curr);
        return;
    }

    string t;
    
    while(idx < str.size() && str[idx] != '[') {
        t += str[idx];
        idx++;
    }
    idx++;
    if(idx >= str.size()) {
        ans.push_back(curr+t);
        return;
    }
    string temp = "";
    vector<string> currStrings;
    while(idx < str.size() && str[idx] != ']')
    {
        if(str[idx] == ',') {
            currStrings.push_back(temp);
            temp = "";
        }
        else {
            temp += str[idx];
        }
        idx++;
    }
    currStrings.push_back(temp);
    // print(currStrings);
    idx++;
    for(string s: currStrings) {
        solve(str, idx, curr + t + s);
    }
}



int main()
{
    string str;
    cin >> str;
    string curr = "";
    solve(str, 0, curr);
    print(ans);
    return 0;
}