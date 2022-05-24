// dp[i][j] -> number of possible choices
// i -> upto element index i
// j -> weight till now allowed

/*
dp[i][j] = Max(
				dp[i-1][j]   	 				(not take i'th)  
				,
				dp[i-1][j-wt[i]] + profit[i] 	(take the i'th)
			)
*/

/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - ___________________ 	|	
	|    	                            |
	-------------------------------------

	Link - 
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define ull unsigned long long
#define lld long double
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
#define ff first
#define ss second
#define mp make_pair

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll w) {cerr << w;}
void _print(int w) {cerr << w;}
void _print(string w) {cerr << w;}
void _print(char w) {cerr << w;}
void _print(lld w) {cerr << w;}
void _print(double w) {cerr << w;}
void _print(ull w) {cerr << w;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const int MAX_N = 1e3 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, w;
vpii v(MAX_N);				// v[i] = {weight, profit}
ll dp[MAX_N][MAX_N];

// take only once
ll solve1(int ind, int wt) {
	if (ind == 0 && w == 0)
		return 0;
	if (ind == 0 && w != 0) 
		return -INF;
		
	if(dp[ind][wt] != -1)
		return dp[ind][wt];
		
	ll ans = solve1(ind - 1, wt);
	if(wt - v[ind].ff >= 0)
		ans = max(ans, solve1(ind - 1, wt - v[ind].ff) + v[ind].ss);
	return dp[ind][wt] = ans;
}

//---------------------------------------------------
/*
dp(i,w) = max(
				dp(i, w - w[i]) + p[i],
				dp(i-1, w)
			)
*/
// take infinte times
ll solve2(int ind, int wt) {
	if (ind == 0 && w == 0)
		return 0;
	if (ind == 0 && w != 0)
		return -INF;

	if(dp[ind][wt] != -1)
		return dp[ind][wt];
	// ll ans = -INF;
	// int k = 0;
	// // ->here if every item has K occurences max
	// while(wt - v[ind].ff * k >= 0){
	// 	ans = max(ans, solve2(ind - 1, wt - k*v[ind].ff) + k*v[ind].ss);
	// 	k++;
	// }
	ll ans = solve1(ind - 1, wt);
	if(wt - v[ind].ff >= 0)
		ans = max(ans, solve1(ind, wt - v[ind].ff) + v[ind].ss);
	return dp[ind][wt] = max(ans, dp[ind][wt]);
}

void solve() {
	cin >> n >> w;
	f0(i, n) cin >> v[i].ff >> v[i].ss;
	// one item
	memset(dp, -1, sizeof(dp));
	cout << solve1(n - 1, w) << endl;
	
	// multiple item
	memset(dp, -1, sizeof(dp));
	cout << solve2(n - 1, w) << endl;


	// take only once
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	f0(i,n) {
		f0(j,w+1) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].ff] + v[i].ss);
		}
	}
	cout << dp[n - 1][w] << endl;

	// take infinte times
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	f0(i,n) {
		f0(j,w+1) {
			int k = 0;
			dp[i][j] = -INF;
			while(j - v[i].ff * k >= 0){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i].ff *k] + k*v[i].ss);
				k++;
			}
		}
	}
	cout << dp[n - 1][w] << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt","r",stdin);
	  freopen("output.txt","w",stdout);
	  freopen("error.txt", "w", stderr);
	#endif
	int tc = 1;
	//cin >> tc;
	f1(t,tc) {
		// cout << "Case #" << t  << ": ";
		solve();
	}
}