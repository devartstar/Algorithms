/*
 	Square root decompositon for answering minimum range queries
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

vector<int> v;
vector<int> b;
int n,q,bs=3;

int getMin(int l, int r){
 	int lb = l/bs;
 	int rb = r/bs;
 	int mn = MAX_N;

 	if(lb==rb){
 	 	for(int i=l; i<=r; i++){
 	 	 	mn = min(mn,v[i]);
 	 	}
 	}else{
 	 	for(int i = l; i<bs*lb; i++)
 	 		mn = min(mn, v[i]);
 	   	for(int i = lb+1; i<rb; i++)
 	 		mn = min(mn, b[i]);
 	   	for(int i = bs*rb; i<r; i++)
 	 		mn = min(mn, v[i]);
 	}
 	return mn;
}

void solve() {
	cin>>n;
	v.resize(n);
	b.resize(n/bs+1);
	f0(i,n){
		cin>>v[i];
		if(b[i/bs]==0)
			b[i/bs]=v[i];
		else
			b[i/bs]=min(b[i/bs],v[i]);
	}
	for(int i : b)	cout<<i<<" ";
	cout<<endl;
	int l,r;
	cin>>q;
	while(q--){
		cin>>l>>r;
		cout<<getMin(l,r)<<endl;
	}
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