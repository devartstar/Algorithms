/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 08.06.2021 			|
	|	Time   - 11:39:06				|	
	|									|
	-------------------------------------
	
	Link - https://codeforces.com/gym/302977/problem/H
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
	vi s(n);
	vi c(n);
	f0(i,n)	cin>>s[i];
	f0(i,n)	cin>>c[i];
	ll dp[3][n];
	
	ll ans=INF;
	f0(i,n){
		dp[0][i]=c[i];
		f(j,1,2){
			dp[j][i]=INF;
			f0(k,i){
				if(s[k]<s[i])
					dp[j][i]=min(dp[j][i],dp[j-1][k]+c[i]);
			}
		}
		ans=min(ans,dp[2][i]);
	}
	if(ans==INF)	cout<<-1<<"\n";
	else	cout<<ans<<"\n";
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