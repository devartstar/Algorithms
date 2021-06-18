/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 12.06.2021 			|
	|	Time   - 00:37:17				|
	|									|
	-------------------------------------
	
	Link - https://codeforces.com/contest/1538/problem/G
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

/*
	!!! // DYNAMIC PROGRAMMING
	dp[i][j] = max number of gifts using i red and j blue balls
	base case dp[0][0] = 0
	recursion ->
		dp[i][j]=max(dp[i][j], dp[i-a][j-b]+1)
		dp[i][j]=max(dp[i][j], dp[i-b][j-a]+1)

// giving TLE
void solve() {
	ll x,y,a,b;
	cin>>x>>y>>a>>b;
	ll dp[x+1][y+1];
	memset(dp,0,sizeof(dp));
	f0(i,x+1){
		f0(j,y+1){
			if(i-a>=0 && j-b>=0)
				dp[i][j]=max(dp[i][j], dp[i-a][j-b]+1);
			if(i-b>=0 && j-a>=0)
				dp[i][j]=max(dp[i][j], dp[i-b][j-a]+1);
		}
	}
	cout<<dp[x][y]<<"\n";
}


void solve(){
	ll x,y,a,b;
	cin>>x>>y>>a>>b;
	set<ll> s;
	// dp[val] - number of gifts can be packed using val reds balloons
	ll dp[x+1]={0};
	dp[0]=0;
	ll i=0;
	while(!s.empty()){
		i=*s.begin();
		s.erase(s.begin());
		if(i+a<=x){
			dp[i+a]=max(dp[i+a],dp[i]+1);
			s.insert(i+a);
		}
		if(i+b<=x){
			dp[i+b]=max(dp[i+b],dp[i]+1);
			s.insert(i+b);
		}
	}
	ll ans=-1;
	f0(j,x+1){
		ans=max(ans,dp[j]);
	}
	cout<<ans<<"\n";
}
*/
void solve(){
	int x,y,a,b;
	cin>>x>>y>>a>>b;
	if(a>b)	swap(a,b);
	ll lv=0, rv=1e9+7;
	while(lv<rv){
		ll mid = lv + (rv - lv)/2;
		ll xx = x, yy=y;
		xx-=a*mid;
		yy-=a*mid;
		
		bool pos = (xx>=0 && yy>=0);
		if(b>a)
			if(xx/(b-a)+yy/(b-a)<mid)	pos=0;
			
		if(pos)	lv=mid+1;
		else	rv=mid;
	}
	cout<<lv-1<<"\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}