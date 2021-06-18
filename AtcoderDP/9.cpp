/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 11.06.2021 			|
	|	Time   - 00:47:54				|	
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
const ll INF = 1e9;


void solve() {
	int n;
	cin>>n;
	vector<double> prob(n+1);
	f1(i,n)
		cin>>prob[i];
	double dp[n+1][n+1]; // dp [heads][tails]  // can also be done in 1d array of dp
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	f0(i,n+1){
		f0(j,n+1){
			if(i==0 && j==0)	continue;
			if(i-1>=0)
				dp[i][j]+=dp[i-1][j]*prob[i+j];
			if(j-1>=0)
				dp[i][j]+=dp[i][j-1]*(1-prob[i+j]);
		}
	}
	double ans = 0.0;
	f0(i,n+1){
		int j=n-i;
		if(i>j)
			ans+=dp[i][j];
	}
	printf("%.10lf",ans);
	
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