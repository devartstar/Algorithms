// This Problem Is Based On ''' SINGLE SOURCE SHORTES PATH ON TREES '''
/*
Bishu is a guy with couple of Girlfriends in different cities 
out of which he has to choose the one who is nearest to him
If more than one is nearest, the one with least city index is his gf
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> ar[1001];
int visited[1001], dist[1001];

void dfs(int node, int distance)
{
    visited[node] = 1;
    dist[node] = distance;

    for (int child : ar[node])
    {
        if (!visited[child])
            dfs(child, dist[node] + 1);
    }
}

int main()
{
    int n, q, a, b;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    dfs(1, 0);
    int ans = -1, min_dist = 1e9;
    cin >> q;
    while (q--)
    {
        int girl_city;
        cin >> girl_city;
        if (dist[girl_city] < min_dist)
        {
            min_dist = dist[girl_city];
            ans = girl_city;
        }
        else
        {
            if (dist[girl_city] == min_dist && girl_city < ans)
            {
                ans = girl_city;
            }
        }
    }

    cout << ans << endl;
}