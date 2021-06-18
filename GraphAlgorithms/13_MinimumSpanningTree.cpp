/*
  	Krusal's Algorithm to find the MST
	MST - given weighted graph....remove some of the edges so that 
	tree remains connected and total edge weight is Minimum
*/
/*			!!! ACCEPTED
  	https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/
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

struct edge{
	int a;
	int b;
	int w;
};
edge arr[100001];
int parent[10001];	// for DSU

bool comp(edge x,edge y){
	return x.w<y.w;	
}

void applyUnion(int x,int y){
	parent[x]=y;
}

int applyFind(int x){
	if(parent[x]==-1)
		return x;
	return parent[x]=applyFind(parent[x]);
}

void solve() {
	int n,m,a,b;
	cin>>n>>m;
	
	f1(i,n)
		parent[i]=-1;
	f0(i,m){
		cin>>arr[i].a>>arr[i].b>>arr[i].w;
	}
	sort(arr,arr+m,comp);
	ll sum=0;
	f0(i,m){
		a=applyFind(arr[i].a);
		b=applyFind(arr[i].b);
		if(a!=b){
			sum+= arr[i].w;
			applyUnion(a,b);			
		}
	}
	// weigth of the minimum spanning tree
	cout<<sum<<endl;

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

