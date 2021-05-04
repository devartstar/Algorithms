#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int visited[100001] = {0};
int dist[100001] = {0};

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    dist[src] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int child : v[parent])
        {
            if (!visited[child])
            {
                q.push(child);
                dist[child] = dist[parent] + 1;
                visited[child] = 1;
            }
        }
    }
}

void solve()
{
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        v[i].clear();
        visited[i] = 0;
        dist[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(1);

    cout << dist[n] << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}