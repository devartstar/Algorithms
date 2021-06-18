/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 08.06.2021 			|
	|	Time   - 08:43:58				|	
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
#define pb push_back
#define fi first
#define se second


const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// Not working for some test cases !!!
void solve() {
	ll n,k,p;
	cin>>n>>k>>p;
	vll a(n),b(k);
	f0(i,n)	cin>>a[i];
	f0(i,k)	cin>>b[i];
	sort(all(a));
	sort(all(b));
	ll dp[k+1][n+1];
	f0(i,k+1)
		f0(j,n+1)
			dp[i][j]=INF;
	dp[0][0]=0;
	
	f1(i,k)
		f1(j,n){
			dp[i][j]=min(dp[i][j],dp[i-1][j]);	// not taking the i'th key
			dp[i][j]=min(dp[i][j],max(dp[i-1][j-1],abs(a[j-1]-b[i-1])+abs(b[i-1]-p)));	// taking the i'th key
		}
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