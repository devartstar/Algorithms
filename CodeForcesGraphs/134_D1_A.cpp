/*
		!!! ACCEPTED
  	https://codeforces.com/problemset/problem/217/A
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
int visited[100001];
vpii points;
vi parent;
int n;

void applyUnion(int a, int b){
	parent[a]=b;
}

int applyFind(int node){
	if(parent[node]==-1)
		return node;
	return parent[node]=applyFind(parent[node]);
}

void solve(){
	f1(i,n-1){
		for(int j=i+1; j<=n; j++){
			int a=i,b=j;
			if(points[i].first == points[j].first || points[i].second == points[j].second){
				//cout<<"lol "<<points[a].first<<","<<points[a].second<<" "<<points[b].first<<","<<points[b].second<<endl;
				a=applyFind(a);
				b=applyFind(b);
				if(a!=b){
					applyUnion(a,b);
				}
			}
		}
	}
	//f1(i,n)	cout<<parent[i]<<" ";
	//cout<<endl;
	int c=0;
	f1(i,n)
		if(parent[i]==-1)	c++;
	cout<<c-1<<endl;
}

void makeGraph(){
	int x,y;
	f1(i,n){
		cin>>x>>y;
		points[i].first=x;
		points[i].second=y;
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	//cin >> tc;
    int tc = 1;

    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        cin>>n;
        parent.resize(n+1);
        points.resize(n+1);
        f1(i,n){
        	//v[i].clear();
        	visited[i]=0;
        	parent[i]=-1;
        }

        makeGraph();
	    solve();
    }
}