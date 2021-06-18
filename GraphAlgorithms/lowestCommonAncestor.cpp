/*
  	LOWEST COMMON ANCESTOR IN A TREE
  	-- First ancestor in a tree common to both
  	!!! NoviceApproach - O(n) for each LCA call
  	->  Make the difference in level = 0
  	->	Trace back to the top till both reaches the same node
  	->	At worst case LCA is root node
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define f0(i, n) for (int i = 0; i < n; i++) // 0 based indexing
#define f1(i, n) for (int i = 1; i <= n; i++) // 1 based indexing
#define f(i, a, b) for (int i = a; i <= b; i++) // 1 based indexing
#define pb push_back
#define fi first
#define se second


const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vi v[100001];
vi visited;
vi level;
vi parent;

void dfs(int node, int l){
	visited[node]=1;
	level[node]=l;

	for(int child : v[node]){
		if(!visited[child]){
			parent[child]=node;
			dfs(child,level[node]+1);
		}
	}
}

int findLCA(int a,int b){
	if(level[a]>level[b])	
		swap(a,b);
	int d = level[b] - level[a];
	while(d>0){
		b=parent[b];
		d--;
	}
	if(a==b)
		return a;
	while(parent[a]!=parent[b]){
		a=parent[a];
		b=parent[b];
	}
	return parent[a];
}

void solve() {
	int n,m,a,b;
	cin>>n>>m;
	visited.resize(n+1);
	level.resize(n+1);
	parent.resize(n+1);
	f0(i,m){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);			
	}
	dfs(1,1);
	/*
	//printing the level of each node
	for(int l : level)	cout<<l<< " ";
	cout<<endl;
	*/
	int q,x,y;
	cin>>q;
	while(q--){
		cin>>x>>y;
		cout<<findLCA(x,y)<<endl;		
	}
	
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}