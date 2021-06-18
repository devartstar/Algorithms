/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - ___curd___ 			|
	|	Time   - __curt__				|	
	|									|
	-------------------------------------
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
vi v[1000001];
int visited[1000001];
int dist[1000001];
vi result;

void dfs(int node, int d){
	visited[node]=1;
	dist[node]=d;
	if(d%2==0)
		result.pb(node);
	for(int child : v[node]){
		if(!visited[child])
			dfs(child, dist[node]+1);
	}
}

void makeGraph(){
	f0(i,m){
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
	cin >> tc;
	
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        cin>>n>>m;
        f1(i,n){
        	v[i].clear();
        	visited[i]=0;
        	dist[i]=0;
        	result.clear();
        }
        makeGraph();
        int max_deg=(int)v[1].size();
        int val=1;
        f1(i,n){
        	if((int)v[i].size()>max_deg){
        		max_deg=(int)v[i].size();
        		val=i;
        	}
        }
        dfs(val,0);
        cout<<(int)result.size()<<"\n";
        f0(i,(int)result.size()){
        	cout<<result[i]<<" ";
        }
        cout<<"\n";
    }
}

