/*
	!!!	
*/

#include <bits/stdc++.h>
using namespace std;

void AdjacencyMatrix()
{
    int n, m, a, b;
    cin >> n >> m; 
    //n - Edges ||| m-Vertices
    int graph[n][n];
    memset(graph, 0, sizeof(graph));
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a - 1][b - 1] = 1;
        graph[b - 1][a - 1] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}

void AdjacencyList()
{
    int n, m; 
	//n-Number of Edges ||| m-Number of Vertices
    cin >> n >> m;
    int a, b;
    vector<vector<int>> v(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " ---> ";
        for (auto j = v[i].begin(); j < v[i].end(); j++)
        {
            cout << *j + 1 << " ";
        }
        cout << endl;
    }
}

int main()
{
    int choice;
    //1 - Adjacency Matrix
    //2 - Adjacency List
    cin >> choice;
    if (choice == 1)
    {
        AdjacencyMatrix();
    }
    else if (choice == 2)
    {
        AdjacencyList();    
    }
    else
    {
        cout << "enter valid choice" << endl;
    }
}