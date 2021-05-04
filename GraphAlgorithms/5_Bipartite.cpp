#include <bits/stdc++.h>
using namespace std;

vector<int> v[1001];
int visited[1001] = {0};
int color[1001] = {0};

bool dfs(int node, int colr)
{
    visited[node] = 1;
    color[node] = colr;

    for (auto child = v[node].begin(); child != v[node].end(); child++)
    {
        if (!visited[*child])
        {
            if (dfs(*child, colr ^ 1) == false)
            {
                return false;
            }
        }
        else if (color[node] == color[*child])
        {
            return false;
        }
    }

    return true;
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
    if (!dfs(*it, 0))
    {
        cout << "Not a Bipartite Graph" << endl;
    }
    else
    {
        cout << "Bipartite Graph" << endl;
    }
}