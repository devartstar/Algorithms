/*
		!!! ACCEPTED
  	https://codeforces.com/problemset/problem/893/C
*/
/*
// !!!!!	DSU Implementation
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

int n,m;
vi parent;
vi bribe;

void applyUnion(int a, int b){
	if(bribe[a]<bribe[b])	parent[b]=a;
	else	parent[a]=b;
}

int applyFind(int a){
	if(parent[a]==-1)	return a;
	return parent[a]=applyFind(parent[a]);
}

void solve() {
	int a,b;		
	f1(i,n)	cin>>bribe[i];
	f1(i,m){
		cin>>a>>b;
		a=applyFind(a);
		b=applyFind(b);
		if(a!=b)
			applyUnion(a,b);
	}
	ll sum =0;
	f1(i,n)
		if(parent[i]==-1)
			sum+=bribe[i];
	cout<<sum<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
		cin>>n>>m;
		parent.resize(n+1);
		bribe.resize(n+1);
		f1(i,n)	parent[i]=-1;
        solve();
    }
}
*/

//	!!!!!	DFS Implementation
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
#define fll0(i, n) for (long long i = 0; i < n; i++) // 0 based indexing
#define fll1(i, n) for (long long i = 1; i <= n; i++) // 1 based indexing
#define fll(i, a, b) for (long long i = a; i <= b; i++) // 1 based indexing
#define pb push_back
#define fi first
#define se second


const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vi v[100001];
vi visited;
vi bribe;
int n,m,val;

void dfs(int node){
	visited[node]=1;
	val=min(val,bribe[node]);

	for(int child : v[node]){
		if(!visited[child])
			dfs(child);
	}
}

void solve(){
	ll sum=0;	
	f1(i,n){
		if(!visited[i]){
			val=INF;
			dfs(i);
			sum+=val;
		}
	}
	cout<<sum<<endl;
}

void makeGraph(){
	f1(i,n)
		cin>>bribe[i];
	int x,y;	
	f1(i,m){
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);		
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	//cin >> tc;
    int tc = 1;

    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        f1(i,n){
        	v[i].clear();
        	visited[i]=0;
        }
        cin>>n>>m;
        bribe.resize(n+1);
        visited.resize(n+1);
        f1(i,n){
        	v[i].clear();
        	visited[i]=0;
        }
        makeGraph();
        solve();
    }
}