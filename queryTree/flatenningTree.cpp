/*
  	Euler Tour Technique
  	!!!	Representation of a tree in form of a array
  	!!! Specially for solving Subtree Queries of a Tree
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

vector<int> v[100001];
int timer=1;
int s[100001], t[100001], ft[200002];
int n,m;

void dfs(int node, int parent){
	// entering time
	s[node]=timer;
	ft[timer]=node;
	timer++;
	for(int child : v[node]){
		if(child==parent)	continue;
		dfs(child,node);
	}
	//returning timer
	t[node]=timer;
	ft[timer]=node;
	timer++;
}

void solve() {
	int a,b;
	cin>>n>>m;
	f1(i,m){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}

	dfs(1,-1);
	f1(i,n)	cout<<s[i]<<" ";
	cout<<endl;
	f1(i,n)	cout<<t[i]<<" ";
	cout<<endl;
	f1(i,2*n)	cout<<ft[i]<<" ";
	cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(x,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}