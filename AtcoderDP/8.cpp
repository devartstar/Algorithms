/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 10.06.2021 			|
	|	Time   - 23:53:43				|	
	|									|
	-------------------------------------
	
	Link - https://atcoder.jp/contests/dp/tasks/dp_h
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
	int h,w;
	cin>>h>>w;
	char v[h][w];
	f0(i,h){
		string s;
		cin>>s;
		f0(j,w)
			v[i][j]=s[j];
	}
	
	ll dp[h+1][w+1];
	memset(dp,0,sizeof(dp));
	
	dp[1][1]=1;
	
	f1(i,h){
		f1(j,w){
			if(i==1 && j==1)	continue;
			if(v[i-1][j-1]=='#')
				dp[i][j]=0;
			else if(v[i-1][j-1]=='.'){
				dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
			}
		}
	}
	
			
	cout<<dp[h][w]<<"\n";		
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