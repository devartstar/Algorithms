/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 17.06.2021 			|
	|	Time   - 00:45:50				|	
	|									|
	-------------------------------------
	
	Link - https://codeforces.com/gym/331541/problem/I
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

int n,m,c;
vi v[100001];
int visited[100001];


// Time Complexity - O(NlogN) -- DFS faster than DSU
/*
	!!! Logic -
				ans is the sum of the size of the 
				largest 2 connected components in the graph
*/

void dfs(int node){
	visited[node]=1;
	c++;
	for(int child : v[node]){
		if(!visited[child])
			dfs(child);
	}
}

void makeGraph(){
	cin>>n>>m;
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
	//cin >> tc;
	
    f1(t,tc) {
        makeGraph();
        // nodes stores the number of nodes in every connected component
        multiset<int,greater<int>> nodes;
        f1(i,n){
        	if(!visited[i]){
        		c=0;
        		dfs(i);
        		nodes.insert(c);	
        	}
        }
		/*
		for(int s : nodes)	cout<<s<<" ";
        cout<<"\n";
        */
        auto itr = nodes.begin();
		if((int)nodes.size()==1)	cout<<*itr<<"\n";
        else						cout<<*itr + *(++itr)<<"\n";
    }
}