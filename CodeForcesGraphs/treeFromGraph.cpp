/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 17.06.2021 			|
	|	Time   - 00:33:47				|	
	|									|
	-------------------------------------
	
	
	Link - https://codeforces.com/gym/331541/problem/H
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define vi vector<int>
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
#define fi first
#define se second

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n,m;
vector<int> v[100001];
int visited[100001];
int parent[100001];

void dfs(int node, int par){
	visited[node]=1;
	parent[node]=par;
	
	for(int child : v[node]){
		if(!visited[child]){
			dfs(child,node);
		}
	}
}

void solve() {
	cin>>n>>m;
	f0(i,m){
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1,-1);
	for(int i=2;i<=n;i++){
		cout<<i<<" "<<parent[i]<<"\n";
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