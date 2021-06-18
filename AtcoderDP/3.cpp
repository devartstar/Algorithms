/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 10.06.2021 			|
	|	Time   - 00:41:23				|	
	|									|
	-------------------------------------
	
	Link - https://atcoder.jp/contests/dp/tasks/dp_c
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

struct Point{
	ll a,b,c;
};

void solve() {
	ll n;
	cin>>n;
	vector<Point> v(n);
	f0(i,n)
		cin>>v[i].a>>v[i].b>>v[i].c;
	Point dp[n];
	f0(i,n){
		dp[i].a=INF;
		dp[i].b=INF;
		dp[i].c=INF;	
	}
	dp[0].a=v[0].a;
	dp[0].b=v[0].b;
	dp[0].c=v[0].c;
	f(i,1,n-1){
		dp[i].a=v[i].a+max(dp[i-1].b,dp[i-1].c);
		dp[i].b=v[i].b+max(dp[i-1].c,dp[i-1].a);
		dp[i].c=v[i].c+max(dp[i-1].a,dp[i-1].b);
	}
	cout<<max(dp[n-1].a,max(dp[n-1].b,dp[n-1].c))<<"\n";
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