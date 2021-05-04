#include <bits/stdc++.h>
using namespace std;

vector<int> v[2001];
int visited[2001];
int in[2001];
int out[2001];
int timer = 1;

void dfs(int node)
{
    visited[node] = 1;
    in[node] = timer++;

    for (auto it = v[node].begin(); it != v[node].end(); it++)
    {
        if (!visited[*it])
        {
            dfs(*it);
        }
    }
    out[node] = timer++;
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    set<int> nodes;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        nodes.insert(a);
        nodes.insert(b);
    }

    auto it = nodes.begin();
    dfs(*it);

    //In_time
    for (int i = 1; i <= n; i++)
    {
        cout << in[i] << " ";
    }
    cout << endl;

    //Out_time
    for (int i = 1; i <= n; i++)
    {
        cout << out[i] << " ";
    }
}