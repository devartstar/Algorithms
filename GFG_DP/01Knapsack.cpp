/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 08.06.2021 			|
	|	Time   - 20:43:14				|	
	|									|
	-------------------------------------
	
	Link - https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
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
	int n,tot;
	cin>>n>>tot;
	vi weight(n+1);
	vi value(n+1);
	f(i,1,n)	cin>>weight[i];
	f(i,1,n)	cin>>value[i];
	ll dp[n+1][tot+1];
	f0(i,tot+1)	dp[0][i]=0;
	f0(i,n+1)	dp[i][0]=0;
	// for bounded knapsack outer loop is the items loop
	// for bounded knapsack the outer loop is the total's loop
	f(i,1,n){
		f(j,0,tot){
			dp[i][j]=j-weight[i]>=0?max(dp[i-1][j-weight[i]]+value[i],dp[i-1][j]):dp[i-1][j];
		}
	}
	f0(i,n+1){
		f0(j,tot+1)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
	
	cout<<dp[n][tot]<<"\n";
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