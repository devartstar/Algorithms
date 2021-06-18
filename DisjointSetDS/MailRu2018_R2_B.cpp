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

ll v[100005];

void solve() {					
	int n,m,l;
	cin>>n>>m>>l;
	v[0]=-1;
	ll c=0;
	f1(i,n){
		cin>>v[i];
		c+= (v[i]>l && v[i-1]<=l);
	}
	v[n+1]=-1;				
	while(m--){
		int a;
		cin>>a;
		if(a==0)
			cout<<c<<endl;
		else{
			int x,y;
			cin>>x>>y;
			c-=(v[x]>l && v[x-1]<=l);
			c-=(v[x]<=l && v[x+1]>l);
			v[x]+=y;
			c+=(v[x]>l && v[x-1]<=l);
			c+=(v[x]<=l && v[x+1]>l);
		}
	}	
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
    	solve();
    }
}