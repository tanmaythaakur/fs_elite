#include <bits/stdc++.h>
using namespace std;

int knapSack(vector<vector<int>> &offers, vector<int> &toBuy, int n)
{
    if (n == 0)
    {
        cout << "N became 0" << endl;
        for (int x : toBuy)
        {
            if (x != 0)
                return 9999999;
        }
        return 0;
    }

    bool allTaken = true;
    for (int i = 0; i < toBuy.size(); i++)
    {
        if (toBuy[i] != 0)
        {
            allTaken = false;
            break;
        }
    }
    if (allTaken)
    {
        cout << "All taken at " << n << endl;
        return 0;
    }

    bool num_of_items_in_offer_is_less_than_toBuyList = true;

    for (int i = 0; i < toBuy.size(); i++)
    {
        if (offers[n - 1][i] > toBuy[i])
            num_of_items_in_offer_is_less_than_toBuyList = false;
        break;
    }
    if (num_of_items_in_offer_is_less_than_toBuyList == false)
    {
        return knapSack(offers, toBuy, n - 1);
    }

    vector<int> temp(toBuy.size());

    for (int i = 0; i < toBuy.size(); i++)
    {
        temp[i] = toBuy[i] - offers[n - 1][i];
    }
    // cout << "Ended\n";
    return min(offers[n - 1].back() + knapSack(offers, temp, n), knapSack(offers, toBuy, n - 1));
    // cout << "Ended\n";
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    vector<vector<int>> offers(k, vector<int>(n + 1, 0));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cin >> offers[i][j];
        }
    }
    vector<int> toBuy(n);
    for (int i = 0; i < n; i++)
        cin >> toBuy[i];

    int actualPrice = 0;
    for (int i = 0; i < n; i++)
    {
        actualPrice += (prices[i] * toBuy[i]);
    }

    int count = knapSack(offers, toBuy, n);
    cout << actualPrice << " " << count << endl;
    cout << min(actualPrice, count) << endl;
    return 0;
}

/*
2 2
3 6
3 1 12
2 3 17
6 6
*/