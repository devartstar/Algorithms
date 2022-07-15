/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - ___________________ 	|
	|    	                            |
	-------------------------------------

	Link - https://www.codechef.com/problems/DGTCNT
	(WRONG) Saving for later reference
*/

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ar array
#define ll long long
#define ull unsigned long long
#define lld long double
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<long long, long long>>
#define vb vector<bool>
#define all(v) v.begin(),v.end()
#define f0(i, n) for (int i = 0; i < n; i++) // 0 based indexing
#define f0r(i, n) for (int i = n-1; i >= 0; i--)
#define f1(i, n) for (int i = 1; i <= n; i++) // 1 based indexing
#define f1r(i, n) for (int i = n; i >= 1; i--)
#define f(i, a, b) for (int i = a; i <= b; i++) // 1 based indexing
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define fll0(i, n) for (long long i = 0; i < n; i++) // 0 based indexing
#define fll1(i, n) for (long long i = 1; i <= n; i++) // 1 based indexing
#define fll(i, a, b) for (long long i = a; i <= b; i++) // 1 based indexing
#define disp(v) for(auto x : v) cout<<x<<" "; cout<<endl;
#define disp0(v, n) for(int i = 0; i < n; i++) cout<<v[i]<<" "; cout<<endl;
#define disp0r(v, n) for(int i = n-1; i >= 0; i--) cout<<v[i]<<" "; cout<<endl;
#define disp1(v, n) for(int i = 1; i <= n; i++) cout<<v[i]<<" "; cout<<endl;
#define disp1r(v, n) for(int i = n; i >= 1; i--) cout<<v[i]<<" "; cout<<endl;
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define sz(v) (int)v.size()
#define len(v) (int)v.length()

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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1<<11;

vll num;
ll dp[20][INF][2];
vll freq(10, 0);
vll bad(10);
// bitmask -
// i'th bit is set to 1 -> if freq[i] == bad[i]
// i'th bit is set to 0 -> if freq[i] != bad[i]


ll rec(ll pos, ll mask_val, ll ok) {
	debug(freq);
	string binVal = bitset<10>(mask_val).to_string();
	debug(mp(mask_val, binVal));
	if(pos == sz(num)) {
		return (mask_val == 0);
	}
	if(dp[pos][mask_val][ok] != -1)
		return dp[pos][mask_val][ok];
	ll ans = 0, mx_digit;
	if(ok) {
		mx_digit = 9;
	} else {
		mx_digit = num[pos];
	}
	f0(i, mx_digit + 1) {
		freq[i]++;
		ll temp_val = mask_val;
		ll temp_ok = ok;

		debug(i);
		debug(mp(freq[i], bad[i]));
		if(freq[i] == bad[i]) {
			// set the i'th bit to 1
			temp_val |= (1 << i);
		} else if(freq[i] != bad[i]) {
			// set the i'th bit to 0
			temp_val &= !(1 << i);
		}
		debug(temp_val);

		if(!temp_ok) {
			if(i == mx_digit)
				temp_ok = false;
			else
				temp_ok = true;
		}
		ans += rec(pos + 1, temp_val, temp_ok);
		freq[i]--;
	}
	return dp[pos][mask_val][ok] = ans;
}

ll solve1(ll x) {
	num.clear();
	while(x > 0) {
		num.pb(x % 10);
		x /= 10;
	}
	reverse(all(num));
	f0(i, 10) freq[i] = 0;
	memset(dp, -1, sizeof(dp));
	return rec(0, 0, 0);
}

void solve() {
	ll l, r;
	cin >> l >> r;
	f0(i, 10) cin >> bad[i];
	cout<<solve1(r) - solve1(l - 1) << endl;
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
		// cout << "Case #" << t  << ": ";
		solve();
	}
}
