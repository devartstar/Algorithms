/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 10.06.2021 			|
	|	Time   - 20:51:46				|	
	|									|
	-------------------------------------
	
	Link -  https://atcoder.jp/contests/dp/tasks/dp_g
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

vector<int> v[MAX_N];
int visited[MAX_N];
int in_degree[MAX_N];
int d[MAX_N];

void dfs_fakeVertex(int node,int dist){
	visited[node]=1;
	d[node]=max(d[node],dist);
	
	for(int child : v[node]){
		if(d[node]+1>=d[child])
			dfs_fakeVertex(child,d[node]+1);
	}
}

void solve1(){
	int n,m,a,b;
	cin>>n>>m;
	f0(i,m){
		cin>>a>>b;
		v[a].pb(b);
	}
	f1(i,n)
		v[0].pb(i);
	dfs_fakeVertex(0,0);
	/*
	f0(i,n+1)
		cout<<d[i]<<" ";
	cout<<"\n";
	*/
	int ans = d[0]-1;
	f1(i,n){
		ans=max(ans,d[i]);
	}
	cout<<ans-1<<"\n";
}

void dfs(int node){
	assert(!visited[node]);
	visited[node]=1;
	for(int child : v[node]){
		d[child] = max(d[child], d[node]+1);
		in_degree[child]--;
		if(in_degree[child]==0)
			dfs(child);
	}
}

void solve() {
	int n,m;
	cin>>n>>m;
	f0(i,m){
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
		in_degree[b]++;
	}
	f1(i,n)
		if(!visited[i] && in_degree[i]==0)
			dfs(i);
	int answer = 0;
	 f1(i,n)
	 	answer=max(answer, d[i]);
	 cout<<answer<<"\n";	
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve1();
    }
}