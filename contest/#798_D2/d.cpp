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

struct ST {
	vll segtree, v;
	void init (ll n) {
		ll size = 1;
		while(size < n) {
			size *= 2;
		}
		size++;
		v.assign(size, 0);
		segtree.assign(2 * size, 0);
	}
	void buildTree(ll si, ll ss, ll se) {
		if(ss == se) {
			segtree[si] = v[ss];
			return;
		}
		ll mid = ss + (se - ss) / 2;
		buildTree(2 * si, ss, mid);
		buildTree(2 * si + 1, mid + 1, se);
		segtree[si] = segtree[2 * si] + segtree[2 * si + 1];
	}
	ll query(ll si, ll ss, ll se, ll qs, ll qe) {
		// COMPLETELY OUTSIDE
		if(ss > qe || se < qs) {
			return 0;
		}
		// COMPLETELY INSIDE
		if(ss >= qs && se <= qe) {
			return segtree[si];
		}

		ll mid = ss + (se - ss) / 2;
		ll left = query(2 * si, ss, mid, qs, qe);
		ll right = query(2 * si + 1, mid + 1, se, qs, qe);
		return (left + right);
	}
	void update(ll si, ll ss, ll se, ll qi) {
		if(ss == se) {
			segtree[si] = v[ss];
			return;
		}
		ll mid = ss + (se - ss) / 2;
		if(qi <= mid) {
			update(2 * si, ss, mid, qi);
		} else {
			update(2 * si + 1, mid + 1, se, qi);
		}
		segtree[si] = segtree[2 * si] + segtree[2 * si + 1];
	}
};


void solve() {
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	n++;
	s1 = " " + s1;
	s2 = " " + s2;
	set<int> apos, bpos, cpos;
	ST aa, bb, cc;
	aa.init(n);
	bb.init(n);
	cc.init(n);
	f1(i, n-1) {
		if(s1[i] == 'a') {
			apos.insert(i);
			aa.v[i] = 1;
		}
		if(s1[i] == 'b') {
			bpos.insert(i);
			bb.v[i] = 1;
		}
		if(s1[i] == 'c') {
			cpos.insert(i);
			cc.v[i] = 1;
		}
	}
	aa.buildTree(1, 1, n);
	bb.buildTree(1, 1, n);
	cc.buildTree(1, 1, n);

	bool ans = true;
	f0(i, n) {
		if(s2[i] == 'b') {
			if(bpos.empty()) {
				ans = false;
				break;
			} else {
				int pos = *bpos.begin();
				if(pos < n) {
					int suma = aa.query(1, 1, n, pos, n);
					if(suma > 0) {
						ans = false;
						break;
					}
				}
				if(pos > n) {
					int sumc = cc.query(1, 1, n, n, pos);
					if(sumc > 0) {
						ans = false;
						break;
					}
				}
				bb.v[pos] = 0;
				bb.update(1, 1, n, pos);
				bpos.erase(bpos.begin());
			}
		}
		if(s2[i] == 'a') {
			if(apos.empty()) {
				ans = false;
				break;
			} else {
				int pos = *apos.begin();
				if(pos < n) {
					int suma = aa.query(1, 1, n, pos, n);
					if(suma > 0) {
						ans = false;
						break;
					}
				}
				if(pos > n) {
					int sumc = cc.query(1, 1, n, n, pos);
					if(sumc > 0) {
						ans = false;
						break;
					}
				}
				aa.v[pos] = 0;
				aa.update(1, 1, n, pos);
				apos.erase(apos.begin());
			}
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
	cin >> tc;
	f1(t,tc) {
		// cout << "Case #" << t  << ": ";
		solve();
	}
}
