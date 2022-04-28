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

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int dp[10][90][90][2][2];
/*
i 		-> position index
val 	-> value of actual number
sum		-> sum of digits upto pos i
x		-> true / false for lower bound
y		-> true / false for upper bound
*/
ll a1[10], b1[10];
ll p10[10];
ll a, b, k;
ll num_digits;

ll rec(ll i, ll val, ll sum, ll x, ll y) {
	if(i == num_digits) {
		if(sum % k == 0 && val % k == 0)
			return 1;
		else
			return 0;
	}

	if(dp[i][val][sum][x][y] != -1)
		return dp[i][val][sum][x][y];

	ll lb = x ? 0 : a1[i];	// if x is true -> {0, 1, ....} else {a1[i], a1[i]+1, ...}
	ll ub = y ? 9 : b1[i];

	// digits for pos i to be between lb & ub
	ll res = 0;
	for (ll j = lb; j <= ub; j++) {
		ll nval = val + ((p10[num_digits - i - 1] * j) % k);
		nval %= k;
		ll x_, y_ ;
		x_ = (j > a1[i]) ? 1 : x;
		y_ = (j < b1[i]) ? 1 : y;
		res += rec(i + 1, nval, sum + j, x_, y_);
	}

	return dp[i][val][sum][x][y] = res;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> a >> b >> k;
	// sum of digits og number N <= 1 << 31 can never be greater than 90
	if(k > 90) {
		cout << 0 << endl;
		return;
	}
	// powers of 10 mod k
	p10[0] = 1;
	f1(i, 9) p10[i] = p10[i - 1] * 10 % k;
	vi u, v;
	ll temp = a;
	while(temp > 0) {
		u.pb(temp % 10);
		temp /= 10;
	}
	temp = b;
	while(temp > 0) {
		v.pb(temp % 10);
		temp /= 10;
	}
	while((ll)u.size() < (ll)v.size())
		u.pb(0);
	reverse(all(u));
	reverse(all(v));
	num_digits = (ll)u.size();
	f0(i, num_digits) a1[i] = u[i], b1[i] = v[i];

	cout << rec(0, 0, 0, 0, 0) << endl;
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
	cin >> tc;
	f1(t,tc) {
		cout << "Case #" << t  << ": ";
		solve();
	}
}