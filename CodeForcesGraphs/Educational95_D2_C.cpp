/*			ACCEPTED -- DP IMPLEMENTATION
  	https://codeforces.com/problemset/problem/1418/C
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

int dp[200005][2];
//TURN = 1 	Friends session
//TURN = 2 	My session
vector<int> v;
int n;

int ok(int i,int turn){
	int m = 1e9;
	if(i>=n)
		return 0;
	if(dp[i][turn]!=-1)
		return dp[i][turn];
	if(turn){
		if(i<n && v[i]==1){
			m=min(m,ok(i+1,turn^1)+1);	
		}
		if(i<n && v[i]==0){
			m=min(m,ok(i+1,turn^1));
		}
		if(i+1<n && v[i]==1 && v[i+1]==0){
			m=min(m,ok(i+2,turn^1)+1);
		}
		if(i+1<n && v[i]==0 && v[i+1]==1){
			m=min(m,ok(i+2,turn^1)+1);
		}
		if(i+1<n && v[i]==0 && v[i+1]==0){
			m=min(m,ok(i+2,turn^1));
		}
		if(i+1<n && v[i]==1 && v[i+1]==1){
			m=min(m,ok(i+2,turn^1)+2);
		}
		return dp[i][turn]=m;
	}else{
		m=min(ok(i+1,turn^1),ok(i+2,turn^1));
		return dp[i][turn]=m;
	}
}

void solve() {
	cin>>n;
	v.resize(n);
	f0(i,n)
		cin>>v[i];
	ok(0,1);
	cout<<dp[0][1]<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        memset(dp,-1,sizeof(dp));
        solve();
    }
}