/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - ___________________ 	|	
    |    	                            |
    -------------------------------------

    Link - 
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define ull unsigned long long
#define lld long double
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define pll pair<long, long>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define all(v) v.begin(),v.end()
#define f0(i, n) for (int i = 0; i < n; i++) // 0 based indexing
#define f1(i, n) for (int i = 1; i <= n; i++) // 1 based indexing
#define f(i, a, b) for (int i = a; i <= b; i++) // 1 based indexing
#define fll0(i, n) for (long long i = 0; i < n; i++) // 0 based indexing
#define fll1(i, n) for (long long i = 1; i <= n; i++) // 1 based indexing
#define fll(i, a, b) for (long long i = a; i <= b; i++) // 1 based indexing
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define endl '\n'

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll w) {cerr << w;}
void _print(int w) {cerr << w;}
void _print(string w) {cerr << w;}
void _print(char w) {cerr << w;}
void _print(lld w) {cerr << w;}
void _print(double w) {cerr << w;}
void _print(ull w) {cerr << w;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n,m;
vi v[100001];
int visited[100001];
int color[100001];

bool dfs(int node, int parent, bool col){
    visited[node] = true;
    color[node] = col;

    for(int child : v[node]){
        if(!visited[child]){
            bool temp = dfs(child, node, col^1);
            if(temp == false)   return false;
        }else{
            if(color[parent] == col)    return false;
        }
    }

    return true;
}

//--------------------------------------------------------------------------------------

void solveBipartite(){
    bool ans  = true;
    f1(i,n){
        if(!visited[i]) ans = ans & dfs(i, -1, 0);
    }
    if(ans) cout<<"Bipartite"<<endl;// BIPARTITE
    else    cout<<"Not Bipartite"<<endl;// NOT BIPARTITE

}

//--------------------------------------------------------------------------------------

bool cycleDetectionUndirected(int node, int parent){
    visited[node] = 1;

    for(int child : v[node]){
        if(!visited[child]){
            bool temp = cycleDetectionUndirected(child, node);
            if(temp == true)    return true;
        }else if(child!=parent) return true;
    }
}

//--------------------------------------------------------------------------------------

vi graph[MAX_N];    // directed graph
vi visited(MAX_N);  // 0 -> not visited | 1 -> under process | 2 -> visited
bool cycleDetectionDirected(int node,int parent){
    visited[node] = 1;

    for(int child : v[node]){
        if(visited[child] == 0){
            if(cycleDetectionDirected(child, node) == true)    
                return true;
        }else{
            if(visited[child] == 1) 
                return true;
        }
    }

    visited[node] = 2;
    return false;
}

//--------------------------------------------------------------------------------------

vi graph[MAX_N];    // directed graph
vi visited(MAX_N);  // 0 -> not visited | 1 -> under process | 2 -> visited
vi in_time(MAX_N);
vi out_time(MAX_N);
int timer = 1;
void inouttime(int node){
    visited[node] = 1;
    in_time[node] = timer++;

    for(int child : graph[node]){
        if(!visited[child]) inouttime(child);
    }

    out_time[node] = timer++;
}

//--------------------------------------------------------------------------------------

vi graph[MAX_N];
vi visited(MAX_N);
vi dist(MAX_N);
void diameter(int node, int d){
    visited[node] = 1;
    dist[node] = d;
    for(int child : graph[node]){
        if(!visited[child]) diameter(child, d+1);
    }
}

// dfs(0,0);
// f1(i,n)  visited[i] = false, dist[i] = 0;
// auto it = dist.begin();
// int node = distance(dist, max_element(it, it+n+1));
// dfs(node, 0);
// auto it1 = dist.begin();
// cout<<*max_element(it, it+n+1)<<endl;

//--------------------------------------------------------------------------------------

vi graph[MAX_N];
vi visited(MAX_N);
vi subtree_size(MAX_N);

int subtreeSizeDFS(int node){
    visited[node] = 1;
    int current_size = 1;

    for(int child : graph[node]){
        if(!visited[child]) current_size += subtreeSizeDFS(child);
    }

    subtree_size[node] = current_size;
    return current_size;
}

//--------------------------------------------------------------------------------------

vi graph[MAX_N];
vi visited(MAX_N);
vi dist(MAX_N);

void sspBFS(int start_node){
    queue<int> q;
    q.push(start_node);
    dist[start_node] = 0;
    visited[start_node] = true;

    while(!q.empty()){
        int parent = q.front();
        q.pop();
        for(int node : graph[parent]){
            if(!visited[node]){
                q.push(node);
                dist[node] = dist[parent] + 1;
                visited[node] = true;
            }
        }
    }
}

//--------------------------------------------------------------------------------------


void makeGraph(){
    cin>>n>>m;
    f1(i,m){
        int x, y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
      freopen("error.txt", "w", stderr);
    #endif
    int tc = 1;
    //cin >> tc;
    
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        f1(i,n){
            v[i].clear();
            visited[i]=0;
        }
        makeGraph();
        // solve();
    }
}