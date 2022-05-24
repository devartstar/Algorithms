#include <bits/stdc++.h>
using namespace std;

vector<int> v[1001];
int visited[1001] = {0};



void dfs(int node)
{
    visited[node] = 1;

    for (auto it = v[node].begin(); it != v[node].end(); it++)
    {
        if (!visited[*it])
        {
            dfs(*it);
        }
    }
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    set<int> nodes;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        nodes.insert(a);
        nodes.insert(b);
    }

    int count = 0;
    for (int i : nodes)
    {
        if (!visited[i])
        {
            dfs(i);
            count++;
        }
    }

    cout << count << endl;
}