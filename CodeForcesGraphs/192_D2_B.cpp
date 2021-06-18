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

int n,m;

vi v[100001];
int visited[100001];

void solve(int node){
	cout<<n-1<<endl;
	f1(i,n){
		if(i==node)	continue;
		cout<<i<<" "<<node<<endl;
	}
}

int makeGraph(){
	int a,b;
	f1(i,m){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);		

	}
	f1(i,n){
		if((int)v[i].size()==0){

		auto it = find(forbid.begin(), forbid.end(), ans);
it
	}
	
return -1;
}
	cout<<ans<<endl;

it = find(forbid.begin(), forbid.end(), ans);
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	//cin >> tc;
    int tc = 1;

    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
		cin>>n>>m;
        f1(i,n){
        	v[i].clear();
        	visited[i]=0;
        }
       	

        solve(makeGraph());

for(int l :

 v[ch])	cout<<i<<" ";

cout<<endl;
    }

}