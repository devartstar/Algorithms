/*
  	https://codeforces.com/problemset/problem/129/B
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
vi in;
int n,m;

void solve(){
	int c=0;
	queue<int> q;
	while(find(in.begin(),in.end(),1)!=in.end()){
		c++;
		f1(i,n)
			if(in[i]==1)
				q.push(i);
					
		while(!q.empty()){
			int x = q.front();
			q.pop();
			in[x]=-1;
			for(int child : v[x]){
				in[child]--;
	 		}
		}
	
	}

	cout<<c<<endl;
		
}

void makeGraph(){
	int a,b;

	f1(i,m){
		cin>>a>>b;
		v[b].pb(a);
		v[a].pb(b);
		in[b]++;
		in[a]++;
	}
	
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	//cin >> tc;
    int tc = 1;

    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
       	cin>>n>>m;
       	visited.resize(n+1);
       	in.resize(n+1);
		f1(i,n){
        	v[i].clear();
        	visited[i]=0;   
        	in[i]=0;
        }
        makeGraph();
        solve();
    }
}