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
	ll n,a,b;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	pair<ll,ll> dp[n+1];
	f0(i,n)
		dp[i].first=dp[i].second=0;
	f0(i,n){
		if(i==0){
			dp[0].fi = a+b;
			dp[0].se = INF;
			continue;
		}
		if(s[i - 1] == '0' && s[i] == '1') {
			dp[i].fi = INF;
			dp[i].se = min(dp[i - 1].fi + a,dp[i - 1].se) + a + b * 2;
		}
		if(s[i - 1] == '1' && s[i] == '1') {
			dp[i].fi = INF;
			dp[i].se = dp[i - 1].se + a + b * 2;
		}
		if(s[i - 1] == '1' && s[i] == '0') {
			dp[i].fi = dp[i - 1].se + a * 2 + b * 2;
			dp[i].se = dp[i - 1].se + a + b * 2;
		}
		if(s[i - 1] == '0' && s[i] == '0') {
			dp[i].fi = dp[i - 1].fi + a + b;
			dp[i].se = dp[i - 1].se + a + b * 2;
		}
	}
	cout<<dp[n-1].fi+b<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}