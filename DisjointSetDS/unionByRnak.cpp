/*
  	Using Path Compression + Union By Rank
	!!! reduces complexity by almost constant order
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

vi parent;
vi ra;

/*
In path compression all the children, grandchildren...etc 
will point out to the root
*/
//Iterative function
int applyFindPathCompressionIterative(int a){	
	vector<int> v;
	while(parent[a]>0){
		v.pb(a);
		a=parent[a];
	}
	f0(i,(int)v.size()){
		parent[v[i]]=a;
	}
	return a;
}
//Recursive Function
int applyFindPathCompressionRecursive(int a){	
	if(parent[a]<0)	
		return a;
	else
		return parent[a] = applyFindPathCompressionRecursive(parent[a]);
}

void applyUnionByRank(int a,int b){	// a and b are root
	if(ra[a]>ra[b]){
		parent[b]=a;
		ra[a]+=ra[b];
	}else{
		parent[a]=b;
		ra[b]+=ra[a];
	}
}
    
void solve() {
	int n,m,a,b;
	cin>>n>>m;
	parent.resize(n+1);
	ra.resize(n+1);
	f1(i,n){
		parent[i]=-1;
		ra[i]=-1;	
	}	
	f1(i,m){
		cin>>a>>b;
		a=applyFindPathCompressionRecursive(a);
		b=applyFindPathCompressionRecursive(b);
		if(a!=b)	
			applyUnionByRank(a,b);
	}

	f1(i,n)	cout<<parent[i]<<" ";	// root node shows -x (x number of elements in the set)
    cout<<endl;						// other nodes points out to the root node
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