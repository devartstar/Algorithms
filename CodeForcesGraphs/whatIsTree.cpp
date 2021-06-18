/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 16.06.2021 			|
	|	Time   - 14:00:06				|	
	|									|
	-------------------------------------
	
	Link - https://codeforces.com/gym/331541/problem/G
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

int n,q;
vi v[100001];
int visited[100001];
int dist[100001];

void dfs(int node, int d){
	visited[node]=1;
	dist[node]=d;
	for(int child : v[node]){
		if(!visited[child])
			dfs(child,dist[node]+1);
	}
}

void makeGraph(){
	int a,b;
	f0(i,n-1){
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
        // cout << "Case #" << t  << ": ";
        f1(i,n){
        	v[i].clear();
        	visited[i]=0;
        }
        cin>>n>>q;
        makeGraph();
        dfs(1,0);
        
        int freq[100001]={0};
		f0(i,n+1)	freq[dist[i]]++;
		
		/*
		cout<<"dist array \n";
		f0(i,n+1)	cout<<dist[i]<<" ";
		cout<<"\n";
        
		cout<<"freq array \n";
		f0(i,n+1)	cout<<freq[i]<<" ";
		cout<<"\n";
		*/
		
        while(q--){
        	int a,b;
        	cin>>a>>b;
        	if(a==0){
        		if(freq[b]==0)	cout<<-1<<"\n";
        		else if(b==0)	cout<<1<<"\n";
        		else			cout<<freq[b]<<"\n";
        	}
        	else if(a==1){
        		if(b<=n)	cout<<dist[b]<<"\n";
        		else 		cout<<-1<<"\n";
        	}
        }
    }
}