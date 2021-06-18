/*              	
		!!! Binary Lifiting - O(log(n))	
		We will make a jump of length L such that
		1.	l is a power of 2
		2.  l <= d
		eg.	(d,l) = {(13,8), (5,4), (1,1)}
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

vi v[1001];
int maxN=10;
int level[1001];
int LCA[1001][11];

void dfs(int node, int lev, int parent){
	level[node]=lev;
	LCA[node][0] = parent;
	for(int child : v[node]){
		if(child!=parent){
   			dfs(child,lev+1,node);
		}
	}
}

void init(int n){
	dfs(1,0,-1);
	f1(j,maxN){
		f1(i,n){
   			if(LCA[i][j-1]!=-1){
   				LCA[i][j]=LCA[LCA[i][j-1]][j-1];
   			}
		}
	}
}

int getLCA(int a, int b){
	if(level[b]<level[a])
		swap(a,b);
	int d = level[b]-level[a];
	while(d>0){
		int i = log2(d);
		b=LCA[b][i];
		d-=(1<<i);	
	}
	if(a==b)
		return a;
	for(int i=maxN;i>=0;i--){
		if(LCA[a][i]!=-1 && LCA[a][i]!=LCA[b][i]){
			a=LCA[a][i];
			b=LCA[b][i];
		}
	}
	return LCA[a][0];
}

int getDistance(int a, int b){
	int lca = getLCA(a,b);
	return level[a]+level[b]-2*lca;
}

void solve() {
	int n,a,b,q;
	cin>>n;

	f1(i,n){
		f0(j,maxN){
			LCA[i][j]=-1;
		}
	}

	f1(i,n-1){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	/*
	//	Displaying the Adjacency list
		*/

	f1(i,n){
		for(int child : v[i]){
			cout<<child<<" ";
		}
		cout<<endl;
	}

	init(n);	// to form the sparse table for LCA

	cin>>q;
	while(q--){
		cin>>a>>b;
		cout<<getDistance(a,b)<<endl;
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