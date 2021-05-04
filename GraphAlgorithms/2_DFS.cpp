#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<int, bool> visited;
    map<int, vector<int>> graph;

    void addEdge(int a, int b);
    void showList();
    void DFS(int node);
};

void Graph::addEdge(int a, int b)
{
    // (a,b) --- means a directed node from a to b
    graph[a].push_back(b);

    /*
    //for Undirected Graph - 
    graph[a].push_back(b);
    graph[b].push_back(a);
    */
}

void Graph::showList()
{
    for (auto it = graph.begin(); it != graph.end(); it++)
    {
        cout << it->first << " ---> ";
        for (auto itr = (it->second).begin(); itr < (it->second).end(); itr++)
        {
            cout << *itr << " -> ";
        }
        cout << "end" << endl;
    }
}

void Graph::DFS(int node)
{
    visited[node] = true;
    cout << node << " ";

    for (auto i = graph[node].begin(); i < graph[node].end(); i++)
    {
        if (!visited[*i])
        {
            DFS(*i);
        }
    }
}

int main()
{
    Graph g;
    int m, a, b;
    // cout << "Enter Number of Edges -- ";
    // cin>>m;
    // for(int i=0;i<m;i++){
    //     cin>>a>>b;
    //     g.addEdge(a,b);
    // }
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);

    g.showList();

    cout << "DFS Traversal from node 0 is - " << endl;
    g.DFS(0);
}
