/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 09.06.2021 			|
	|	Time   - 01:04:20				|	
	|									|
	-------------------------------------
	
	Link - https://www.geeksforgeeks.org/tiling-with-dominoes/
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

// No of ways for exclusively 3*2 blocks = 3
// No of ways for exclusively 3*4 blocks = 2
void solve() {
	int n,exc2=3,exc4=2;
	cin>>n;
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	f0(i,n+1){
		if(i+2<=n)
			dp[i+2]+=(dp[i]*exc2);
		if(i+4<=n)
			dp[i+4]+=(dp[i]*exc4);
	}
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