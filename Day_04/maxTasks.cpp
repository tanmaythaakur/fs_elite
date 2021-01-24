#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int start, end;
    bool available = true;
    Node *left, *right;
};

class SegmentTreeTasks
{
public:
    int ans = 0;

    Node *build(int start, int end)
    {
        Node *root = new Node();
        root->start = start;
        root->end = end;
        root->available = true;

        if (start < end)
        {
            int mid = start + (end - start) / 2;
            root->left = build(start, mid);
            root->right = build(mid + 1, end);
        }
        return root;
    }

    bool doable(Node *root, int start, int end)
    {
        if (root == NULL || root->start > end || root->end < start || root->available == false)
            return false;
        if (root->start == root->end)
        {
            root->available = false;
            return true;
        }

        bool ans = doable(root->left, start, end);
        if (!ans)
            ans = doable(root->right, start, end);

        root->available = root->left->available || root->right->available;
        return ans;
    }

    int maxPrograms(vector<vector<int>> &programs)
    {
        sort(programs.begin(), programs.end(), (vector<int> & a, vector<int> & b){return (a[1] != b[1]) ? a[1] < b[1] : a[0] < b[0]});
        int start = programs[0][0];
        int end = programs[programs.size() - 1][1];

        Node *root = build(start, end);

        for (vector<int> program : programs)
        {
            ans += (doable(root, program[0], program[1]));
        }
        return ans;
    }
};

int main()
{
    // Call maxPrograms function here
    return 0;
}