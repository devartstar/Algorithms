/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 09.06.2021 			|
	|	Time   - 00:43:14				|	
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

void rodProfit(){
	int tot_len,n;
	cin>>tot_len>>n;
	vi length(n);
	vi price(n);
	f0(i,n)	cin>>length[i];
	f0(i,n)	cin>>price[i];
	int dp[n+1][tot_len+1];
	memset(dp,0,sizeof(dp));
	f(i,1,n){
		f(j,1,tot_len){
			dp[i][j] = j-length[i-1]>=0 ? max(dp[i-1][j], dp[i][j-length[i-1]] + price[i-1]) : dp[i-1][j]; 
		}
	}
	cout<<dp[n][tot_len]<<"\n";
}

// solving using 1-Dim DP
void solve() {
	int tot_len,n;	//n is the length of the rod
	cin>>tot_len>>n;
	vi length(n);
	vi price(n);
	f0(i,n)	cin>>length[i];
	f0(i,n)	cin>>price[i];
	int dp[tot_len+1];
	memset(dp,0,sizeof(dp));
	f(i,0,tot_len){
		f0(j,n){
			if(i+length[j]<=tot_len)
				dp[i+length[j]]=max(dp[i+length[j]],dp[i]+price[j]);	
		}
	}
	cout<<dp[tot_len]<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        //solve();
        rodProfit();
    }
}