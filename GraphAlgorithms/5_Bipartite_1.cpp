/*
A Professor is doing a Research in which he is testing the sexuality of the bugs.....
given the interations between the we have to find if the bugs are asexual oo sexual
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> v[2001];
int visited[2001];
int color[2001];

bool Bipartite_dfs(int node, int colr)
{
    visited[node] = 1;
    color[node] = colr;

    for (auto it = v[node].begin(); it != v[node].end(); it++)
    {
        if (!visited[*it])
        {
            bool flag = Bipartite_dfs(*it, colr ^ 1);
            if (flag == false)
            {
                return false;
            }
        }
        else if (color[*it] == color[node])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b;
        cin >> n >> m;

        set<int> nodes;
        for (int i = 0; i < m; i++)
        {
            v[i].clear();
            visited[i] = 0;

            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
            nodes.insert(a);
            nodes.insert(b);
        }

        bool fin_ans = true;
        for (int i : nodes)
        {
            if (!visited[i])
            {
                bool ans = Bipartite_dfs(i, 0);
                if (!ans)
                {
                    fin_ans = false;
                }
            }
        }

        if (fin_ans)
        {
            cout << "All Not Asexual" << endl;
        }
        else
        {
            cout << "Atleast one Asexual" << endl;
        }
    }
}