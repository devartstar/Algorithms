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
 
void bfs(int src){
	visited[src]=1;
	dist[src]=1;
	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int child : v[node]){
			if(!visited[child]){
				q.push(child);
				dist[child]=dist[node]+1;
				visited[child]=1;
			}
		}
	}
}
 
void makeGraph(){
	int a,b;
	f0(i,m){
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
        }
        makeGraph();
        bfs(1);
        vi result;
        vi result1;
        f1(i,n)
        	if(dist[i]%2)
        		result.pb(i);
        	else
        		result1.pb(i);
        int s1=(int)result.size();
        int s2=(int)result1.size();
        if(s1>s2){
        	cout<<s2<<"\n";
        	f0(i,s2)	cout<<result1[i]<<" ";
        	cout<<"\n";
        }else{
        	cout<<s1<<"\n";
        	f0(i,s1)	cout<<result[i]<<" ";
        	cout<<"\n";
        }
    }
}