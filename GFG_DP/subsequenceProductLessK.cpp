/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 15.06.2021 			|
	|	Time   - 07:14:05				|	
	|									|
	-------------------------------------
	
	!!!	IMPORTANT
	Link - https://www.geeksforgeeks.org/count-subsequences-product-less-k/
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
	int n,k;
	cin>>n>>k;
	vi v(n);
	f0(i,n)	cin>>v[i];
	int dp[k+1][n+1];
	memset(dp,0,sizeof(dp));
	
	f1(i,k){
		f1(j,n){
			dp[i][j]=dp[i][j-1];			// jth element not considered
			if(v[j-1]<=i && v[j-1]>0)		// jth element considered
				dp[i][j]+=dp[i/v[j-1]][j-1] + 1;
		}
	}
	/*
	f0(i,k+1){
		f0(j,n+1)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
	*/
	cout<<dp[k][n]<<"\n";
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