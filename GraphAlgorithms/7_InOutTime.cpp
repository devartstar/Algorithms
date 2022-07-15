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


/*
ll n, m;
vll graph[1001];
vector<ll> in_time(1001), out_time(1001);
vector<bool> visited(1001);
ll timer;

bool dfs(int node) {
     visited[node] = true;
     in_time[node] = timer++;
     for(int child : graph[node]) {
          if(!visited[child]) dfs(child);
     }
     out_time[node] = timer++;
}

void solve() {
     cin >> n >> m;
     for(int i = 0; i < m; i++) {
          int x, y; cin >> x >> y;
          graph[x].push_back(y);
          graph[y].push_back(x);
     }
     for(int i = 1; i <= n; i++) {
          if(!visited[i]) dfs(i);
     }
     for(int i = 1; i <= n; i++) cout<<in_time[i]<<" "<<out_time[i]<<endl;
}
*/