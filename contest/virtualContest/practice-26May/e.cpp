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
ll size1;

struct ST {
	vector<set<int>> segtree(100);
	vi v;
	void init (ll n) {
		ll size = 4 * n;
		size1 = size;
		v.assign(size, 0);
		segtree.resize(size);
	}
	set<int> combine(set<int> x, set<int> y) {
		set<int> ans;
		for(int kk : x)
			ans.insert(kk);
		for(int kk : y)
			ans.insert(kk);
	}
	void buildTree(ll si, ll ss, ll se) {
		if(ss == se) {
			segtree[si].insert(v[ss]);
			return;
		}
		ll mid = ss + (se - ss) / 2;
		buildTree(2 * si, ss, mid);
		buildTree(2 * si + 1, mid + 1, se);
		segtree[si] = combine(segtree[2 * si], segtree[2 * si + 1]);
	}
	set<int> query(ll si, ll ss, ll se, ll qs, ll qe) {
		// COMPLETELY OUTSIDE
		if(ss > qe || se < qs) {
			set<int> temp;
			return temp;
		}
		// COMPLETELY INSIDE
		if(ss >= qs && se <= qe) {
			return segtree[si];
		}

		ll mid = ss + (se - ss) / 2;
		set<int> left = query(2 * si, ss, mid, qs, qe);
		set<int> right = query(2 * si + 1, mid + 1, se, qs, qe);
		return combine(left, right);
	}
	void update(ll si, ll ss, ll se, ll qi) {
		if(ss == se) {
			segtree[si].clear();
			segtree[si].insert(v[ss]);
			return;
		}
		ll mid = ss + (se - ss) / 2;
		if(qi <= mid) {
			update(2 * si, ss, mid, qi);
		} else {
			update(2 * si + 1, mid + 1, se, qi);
		}
		segtree[si] = combine(segtree[2 * si], segtree[2 * si + 1]);
	}
};


void solve() {
	string s;
	cin >> s;
	int n = s.length();
	ST a;
	a.init(n);
	f1(i, n) {
		a.v[i] = s[i-1] - 'a';
	}
	// debug(a.v);
	a.buildTree(1, 1, n);
	f1(i, size1) {
		debug(mp(i, a.segtree[i]));
	}
	int q;
	cin >> q;
	while(q--) {
		int chc;
		cin >> chc;
		if(chc == 1) {
			int pos;
			cin >> pos;
			char ch;
			cin >> ch;
			s[pos - 1] = ch;
			a.v[pos] = ch - 'a';
			a.update(1, 1, n, pos);
			f1(i, size1) {
				debug(mp(i, a.segtree[i]));
			}
		}
		if(chc == 2) {
			int left, right;
			cin >> left >> right;
			set<int> ans = a.query(1, 1, n, left, right);
			int cnt = sz(ans);
			cout << cnt << endl;
		}
	}
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
