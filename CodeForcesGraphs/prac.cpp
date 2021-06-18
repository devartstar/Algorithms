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
vi v[100001];
int visited[100001];
int parent[100001];
vpii back_edges;

void cycleDetection(int node, int par){
	//	Remove all the back edges
	visited[node]=1;
	for(int child : v[node]){
		if(!visited[child]){
			cycleDetection(child,node);
		}else if(child!=par){
			back_edges.pb(make_pair(child,par));
			v[par].erase(remove(v[par].begin(), v[par].end(), child), v[par].end());
			v[child].erase(remove(v[child].begin(), v[child].end(), par), v[child].end());
			cout<<"the AL "<<child<<","<<par<<"\n";
			f0(i,n){
				cout<<i<<" : ";
				for(int x : v[i])	cout<<x<<" ";
				cout<<"\n";
			}
		}
	}
}

void makeGraph(){
	cin>>n>>m;
	int a,b;
	f0(i,m)	cin>>a>>b, v[a].pb(b), v[b].pb(a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
	//cin >> tc;
	
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        f1(i,n){
        	v[i].clear();
        	visited[i]=0;
        }
        makeGraph();
		cycleDetection(1,-1);
        for(pii x : back_edges)	cout<<x.first<<" "<<x.second<<"\n";
    }
}