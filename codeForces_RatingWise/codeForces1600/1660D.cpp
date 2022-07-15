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
const ll INF = 1e9;


void solve() {
	ll n;
	cin >> n;
	vi v(n + 2, 0);
	vi pos = {0};
	vi cnt_neg(n + 2, 0);
	vi cnt_two(n + 2, 0);
	f1(i, n) {
		cin >> v[i];
		cnt_neg[i] = cnt_neg[i - 1];
		cnt_two[i] = cnt_two[i - 1];
		if (v[i] == 0)
			pos.pb(i);
		if(v[i] < 0)
			cnt_neg[i]++;
		if(v[i] == 2 || v[i] == -2)
			cnt_two[i]++;
	}
	cnt_two[n + 1] = cnt_two[n];
	cnt_neg[n + 1] = cnt_neg[n];
	debug(cnt_neg);
	debug(cnt_two);
	pos.pb(n + 1);
	ll mx = 0;
	pll ans = mp(0,0);
	bool ans1 = false;
	f0(i, sz(pos) - 1) {
		ll start = pos[i];
		ll end = pos[i + 1];
		ll val_two = cnt_two[end] - cnt_two[start];
		ll val_neg = cnt_neg[end] - cnt_neg[start];
		debug(mp(start, end));
		debug(mp(val_neg, val_two));
		if(val_neg & 1) {
			int temp_start = start, temp_two = val_two;
			while(v[temp_start] >= 0) {
				temp_start++;
				if(v[temp_start] == 2 || v[temp_start] == -2)
					temp_two--;
			}
			if(end - temp_start > 1)
				ans1 = true;
			if(temp_two > mx && temp_start < end - 1) {
				mx = temp_two;
				ans = mp(temp_start, end);
			}
			if(mx == 0) {
				ans = mp(temp_start, end);
			}
			int temp_end = end;
			temp_two = val_two;
			while(v[temp_end] >= 0) {
				temp_end--;
				if(v[temp_end] == 2 || v[temp_end] == -2)
					temp_two--;
			}
			if(temp_end - start > 1)
				ans1 = true;
			if(temp_two > mx && start < temp_end - 1) {
				mx = temp_two;
				ans = mp(start, temp_end);
			}
			if(mx == 0) {
				ans = mp(start, temp_end);
			}
		} else {
			if(val_two > mx) {
				mx = val_two;
				ans = mp(start, end);
			}
		}
	}
	debug(mx);
	debug(mp(ans.ff, ans.ss));
	cout << ans.ff << " " << min(n + 1 - ans.ss, n) << endl;
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
