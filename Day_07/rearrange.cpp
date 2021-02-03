#include <bits/stdc++.h>
using namespace std;

unordered_map<string, set<string>> adj;
vector<string> ans;

vector<string> split(string line)
{
    vector<string> arr;
    string curr;

    for (char ch : line)
    {
        if (ch == ',')
        {
            arr.push_back(curr);
            curr = "";
        }
        else
            curr += ch;
    }
    arr.push_back(curr);
    return arr;
}

void dfs(string curr)
{

    while (adj[curr].size() != 0)
    {
        string to = *(adj[curr].begin());
        adj[curr].erase(to);
        dfs(to);
    }
    // for (string to : adj[curr])
    // {
    //     cout << curr << " HERE\n";
    //     adj[curr].erase(to);
    //     cout << "To " << to << endl;
    //     dfs(to);
    // }
    ans.push_back(curr);
}

int main()
{
    string line;
    getline(cin, line);
    vector<string> tickets = split(line);
    for (string ticket : tickets)
    {
        string from = ticket.substr(0, 3);
        string to = ticket.substr(4, 3);

        adj[from].insert(to);
    }

    dfs("BZA");
    reverse(ans.begin(), ans.end());

    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}