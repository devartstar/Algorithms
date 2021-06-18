/*
	Link - https://codeforces.com/gym/302977/problem/D
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
	int n,k;
	cin>>n>>k;
	vi th(n);
	vi a(n);
	f0(i,n)
		cin>>th[i];
	f0(i,n)
		cin>>a[i];
	ll total=0;
	f0(i,n)
		total += (a[i]*th[i]);	
	//cout<<total<<"\n";
	ll sum=0;
	f(i,0,k-1){
		sum += (a[i]^1)*th[i];
		//cout<<sum<<" ";
	}
	//cout<<sum<<"\n";
	ll dp[n-k+1];
	dp[0]=sum;
	ll ans=dp[0];
	f(i,1,n-k){
		dp[i] = dp[i-1] - (a[i-1]^1)*(th[i-1]) + (a[i+k-1]^1)*(th[i+k-1]);
		ans=max(ans,dp[i]);	
	}
	cout<<total+ans<<"\n";
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