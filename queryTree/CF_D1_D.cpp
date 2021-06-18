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

vctor<int> v[100001];
int s[100001],e[100001],ft[200002];
int n,m,timer = 1;

void dfs(int node, int parent){
	ft[timer]=node;
	s[node]=timer;
	timer++;

	for(int child : v[node]){
		if(child!=parent)
			dfs(child,node);
	}

	ft[timer]=node;
	e[node]=timer;
	timer++;
}

void solve() {
	int a,b;
	cin>>n>>m;
	f1(1,m){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}

	dfs(1,-1)
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