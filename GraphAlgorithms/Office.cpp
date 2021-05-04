/*
counting number of connected components and 
the number of elements in each connected component
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int visited[100001] = {0};
int cc_comp;

void dfs(int node)
{
    visited[node] = 1;
    cc_comp++;

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
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b;
        cin >> n >> m;

        for (int i = 0; i <= n; i++)
        {
            v[i].clear();
            visited[i] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        int cnt = 0;
        long long res = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                cc_comp = 0;
                dfs(i);
                cnt++;
                res = (res * cc_comp) % (1000000007);
            }
        }
        cout << cnt << " " << res << endl;
    }
}
