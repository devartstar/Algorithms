/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 09.06.2021 			|
	|	Time   - 21:09:36				|	
	|									|
	-------------------------------------
	
	Link - https://www.geeksforgeeks.org/count-even-length-binary-sequences-with-same-sum-of-first-and-second-half-bits/
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

int dp[1001][1001];

/*
	dp[i][j] - i'th
	BASE CASE 
*/

int countSeqUtils(int n, int diff){
	if(abs(diff)>n)
		return 0;
	if(n==1 && diff==0)
		return 2;
	if(n==1 && diff==1)
		return 1;
	if(dp[n][n+diff]!=-1){	// subproblem already solved
		return dp[n][n+diff];
	}
	int result = countSeqUtils(n-1,diff)*2 + countSeqUtils(n-1,diff+1) + countSeqUtils(n-1,diff-1);
	return dp[n][n+diff]=result;
}

void solve() {
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	
	cout<<countSeqUtils(n,0)<<"\n";
	
	f0(i,n){
		f0(j,n)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
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