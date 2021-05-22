#include <bits/stdc++.h>
using namespace std;

vector<int> v[2001];
int visited[2001] = {0};

bool dfs(int node, int parent)
{
    visited[node] = 1;

    for (auto child = v[node].begin(); child != v[node].end(); child++)
    {
        if (!visited[*child])
        {
            if (dfs(*child, node) == true)
            {
                cout << node << ":::" << *child << endl;
                return true;
            }
        }
        else if (*child != node)
        {
            cout << node << ":::" << *child << endl;
            return true;
        }
    }
    return false;
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
    cout << *it << endl;
    if (dfs(*it, -1))
    {
        cout << "Contains a Cycle" << endl;
    }
    else
    {
        cout << "Dosent Contain a Cycle" << endl;
    }


}
