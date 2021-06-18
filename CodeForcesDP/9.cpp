/*
	Link - https://codeforces.com/gym/302977/problem/A
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

// DP Approach
// Base Case -> f(0) = 1 & f(1) = 0
// recursion -> f(n) = (f(n-2)*1)*2 = 2*f(n-2)
void solve() {
	int n;
	cin>>n;
	ll dp[n+1];
	memset(dp,-1,sizeof(dp));
	dp[0]=1;dp[1]=0;
	f(i,2,n)
		dp[i]=2*dp[i-2];
	cout<<dp[n]<<"\n";
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