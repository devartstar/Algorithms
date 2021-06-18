/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 15.06.2021 			|
	|	Time   - 09:51:00				|	
	|									|
	-------------------------------------
	
	Link - https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-three-are-consecutive/
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
const ll INF = 1e9;


void solve() {
	int n;
	cin>>n;
	vi v(n);
	f0(i,n)	cin>>v[i];
	int dp[n];
	dp[0]=v[0];
	dp[1]=v[0]+v[1];
	dp[2]=max(v[0]+v[1], max(v[0]+v[2], v[1]+v[2]));
	for(int i=3;i<n;i++){
		dp[i] = max(dp[i-1], max(dp[i-2]+v[i], dp[i-3]+v[i]+v[i-1]));
	}
	cout<<dp[n-1]<<"\n";
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