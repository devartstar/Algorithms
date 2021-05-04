#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int visited[100001] = {0};
int d[100001] = {-1};

void dfs(int node, int dist)
{
    visited[node] = 1;
    d[node] = dist;

    for (int child : v[node])
    {
        if (!visited[child])
        {
            dfs(child, d[node] + 1);
        }
    }
}

void solve1()
{
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1, 0);
    int x = distance(d, max_element(d, d + n + 1));

    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
        d[i] = -1;
    }

    dfs(x, 0);

    auto ans = max_element(d, d + n + 1);
    int y = distance(d, ans);
    cout << "(" << x << "," << y << ") = " << *ans << endl;
}

int main()
{
    //Choice 1 --- O(n)
    //Choice 2 --- O(n^2)

    solve1();
}