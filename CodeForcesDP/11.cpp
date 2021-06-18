/*
	Link - https://codeforces.com/gym/302977/problem/C
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


void solve() {
	int n;
	cin>>n;
	
	ll dp[n+1][8];
	f0(i,n+1)
		f0(j,8)
			dp[i][j]=INF;
	dp[0][0]=0;
	f0(i,n){
		ll cost;
		string s;
		int string_mask=0; 
		cin>>cost>>s;
		// masking the string s
		f0(j,3){
			char c = 'C' - j;
			bool have = false;
			for(char d : s){
				if(c==d)	have = true;
			}
			if(have)
				string_mask+=(1<<j);	// 2^j
		}
		//cout<<string_mask<<"\n";
		// push dp -- Future states are modified
		f0(mask,8){
			dp[i+1][mask]=min(dp[i][mask],dp[i+1][mask]);
			dp[i+1][mask | string_mask]=min(dp[i+1][mask | string_mask],dp[i][mask]+cost);
		}
	}

	if(dp[n][7]==INF)
		cout<<-1<<"\n";
	else
		cout<<dp[n][7]<<"\n";
	
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