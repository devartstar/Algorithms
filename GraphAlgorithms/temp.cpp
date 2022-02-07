#include<bits/stdc++.h>
 
using namespace std;
 
int n,m;
vector<int> v[100001];
vector<int> visited(100001);

 
// This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212
bool isCyclicUtil(int node, bool visited[], bool *recStack)
{
    if(visited[node] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[node] = true;
        recStack[node] = true;
 
        // Recur for all the vertices adjacent to this vertex
        for(int child : v[node])
        {
            if ( !visited[child] && isCyclicUtil(child, visited, recStack) )
                return true;
            else if (recStack[child])
                return true;
        }
 
    }
    recStack[node] = false;  // remove the vertex from recursion stack
    return false;
}
 
// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
bool isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool visited[n+1];
    bool recStack[n+1];
    for(int i = 1; i <= n; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 1; i <= n; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}
 
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x, y;
        cin>>x>>y;
        v[x].push_back(y);
    }
 
    if(isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}