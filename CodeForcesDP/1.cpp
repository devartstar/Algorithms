/*
	Link - https://codeforces.com/problemset/problem/996/A
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
	ll n;
	cin>>n;
	vll v{1,5,10,20,100};

	int n1=n,a;
	int c=0;
	while(n1>0){
		n1/=10;
		c++;
	}
	if(c>2){
			a = n%100;
			n/=100;
	}else{
		a=n;
	}
	ll dp[a+1];
	memset(dp,1000000001,sizeof(dp));
	//f0(i,n+1)	cout<<dp[i]<<" ";
	//cout<<"\n";
	dp[0]=0;
	for(int i=1;i<=a;i++){
		for(ll x : v){
			if(i-x>=0)
				dp[i] = min(dp[i],1+dp[i-x]);
		}
	}
	//f0(i,n+1)	cout<<dp[i]<<" ";
	//cout<<"\n";
	int ans = c>2?dp[a]+n:dp[a];
	cout<<ans<<"\n";
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