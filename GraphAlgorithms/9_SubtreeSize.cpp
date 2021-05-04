#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int visited[100001] = {0};
int sub_tree[100001] = {0};

int dfs(int node)
{
    visited[node] = 1;
    int curr_size = 1;

    for (int i : v[node])
    {
        if (!visited[i])
        {
            curr_size += dfs(i);
        }
    }

    sub_tree[node] = curr_size;
    return curr_size;
}

int main()
{
    int n, a, b; // no need for m as in a tree ' m=n-1'
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int ans = dfs(1);
    // this sub_tree[i] in the array contains the sizt subtree size of node i
    for (int i = 1; i <= n; i++)
    {
        cout << sub_tree[i] << " ";
    }
    cout << endl;
}