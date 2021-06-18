/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 16.06.2021 			|
	|	Time   - 13:11:18				|	
	|									|
	-------------------------------------
	
	Link - https://codeforces.com/gym/331541/problem/Fcodeforces.com/gym/331541/problem/F
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

int n,start,stop;

vi v[10000000];
int visited[10000000];
int dist[10000000];

void bfs(int src){
	queue<int> q;
	q.push(src);
	visited[src]=1;
	dist[src]=0;
	
	while(!q.empty()){
		int parent = q.front();
		q.pop();
		for(int child : v[parent]){
			if(!visited[child]){
				q.push(child);
				dist[child]=dist[parent]+1;
				visited[child]=1;
			}
		}
	}
}

void makeGraph(){
	cin>>n;
	char arr[n][n];
	f0(i,n){
		string s;
		cin>>s;
		f0(j,n)
			arr[i][j]=s[j];
	}
	f0(i,n){
		f0(j,n){
			if(arr[i][j]!='X'){
				if(arr[i][j]=='A')	start=i*n+j;
				if(arr[i][j]=='B')	stop=n*i+j;
			
				if(i-1>=0){
					if(arr[i-1][j]!='X')	
						v[n*i+j].pb(n*(i-1)+j);		// top movement
				}	
				if(j+1<n){
					if(arr[i][j+1]!='X')	
						v[n*i+j].pb(n*i+j+1);		// right movement
				}	
				if(i+1<n){
					if(arr[i+1][j]!='X')	
						v[n*i+j].pb(n*(i+1)+j);		// down movement
				}	
				if(j-1>=0){
					if(arr[i][j-1]!='X')	
						v[n*i+j].pb(n*i+j-1);		// left movement
				}	
			}
		}
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
        makeGraph();
        bfs(start);
        
		if(dist[stop]==0 && start!=stop)
        	cout<<-1<<"\n";
        else
        	cout<<dist[stop]<<"\n";
    }
}