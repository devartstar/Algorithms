/*
	Link - https://codeforces.com/gym/302977/problem/E
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
const ll INF = 1e17;


void solve() {
	ll n,l,p;
	cin>>n>>l>>p;
	vll a(n);
	vll b(l);
	f0(i,n)	cin>>a[i];
	f0(i,l)	cin>>b[i];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	ll dp[l+1][n+1];
	f0(i,l+1)
		f0(j,n+1)
			dp[i][j]=INF;

	dp[0][0]=0;		
			
	f0(i,l){
		f0(j,n+1){
			//dont take the person
			dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
			//take the person
			if(j<n)
				dp[i+1][j+1]=min(dp[i+1][j+1], max(dp[i][j],abs(a[j]-b[i])+abs(b[i]-p)));
		}
	}
	cout<<dp[l][n]<<"\n";
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