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
const ll INF = 1e18;

void solve() {
	ll n,W;
	cin>>n>>W;
	vll w(n);
	vll v(n);
	ll total_value=0;
	f0(i,n){
		cin>>w[i]>>v[i];
		total_value+=v[i];
	}
	ll dp[total_value+1];
	f0(i,total_value+1)
		dp[i]=INF;
	dp[0]=0;
	f0(i,n){
		for(int val = total_value - v[i]; val>=0; val--){
			dp[val+v[i]]=min(dp[val]+w[i], dp[val+v[i]]);
		}
	}
	ll ans = 0;
	for(ll i=0;i<=total_value;i++)
		if(dp[i]<=W)
			ans=max(ans,i);
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