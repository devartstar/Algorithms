/*
	Link - https://codeforces.com/problemset/problem/894/A 
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


void solve() {
	string s;
	int n;
	cin>>s;
	n=(int)s.length();
	int c=0;
	vi vb;
	vi va;
	f0(i,n){
		if(s[i]=='Q')
			c++;
		else if(s[i]=='A')
			vb.pb(c);	
	}
	f0(i,(int)vb.size()){
		va.pb(c-vb[i]);
	}
	ll ans=0;
	f0(i,(int)vb.size()){
		ans+= vb[i]*va[i];
	}
	cout<<ans<<"\n";
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