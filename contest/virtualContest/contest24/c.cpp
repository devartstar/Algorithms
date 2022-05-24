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

vector<pll> v(7);

pair<pll, pll> coincide(pll a, pll b, pll c, pll d) {
	// a, b corresponds to first rectangle
	// c, d corresponds to second rectangle
	ll left = max(a.ff, c.ff);
	ll right = min(b.ff, d.ff);
	ll top = min(b.ss, d.ss);
	ll bottom = max(a.ss, c.ss);

	if(left >= right || bottom >= top)
		return mp(mp(0, 0), mp(0, 0));
	else
		return mp(mp(left, bottom), mp(right, top));
}

ll calcArea(pair<pll, pll> x) {
	return (1ll * abs(x.ff.ff - x.ss.ff) * abs(x.ff.ss - x.ss.ss));
}

void solve() {
	f1(i, 6) cin >> v[i].ff >> v[i].ss;
	pair<pll,pll> wa = coincide(v[1], v[2], v[3], v[4]);
	pair<pll,pll> wb = coincide(v[1], v[2], v[5], v[6]);
	pair<pll,pll> ab = coincide(wa.ff, wa.ss, wb.ff, wb.ss);


	// cout<<(calcArea(mp(v[1], v[2])))<<endl;
	// cout<<(calcArea(wa))<<endl;
	// cout<<(calcArea(wb))<<endl;
	// cout<<(calcArea(ab))<<endl;
	if (calcArea(mp(v[1], v[2])) > calcArea(wa) + calcArea(wb) - calcArea(ab))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// #ifndef ONLINE_JUDGE
	//   freopen("input.txt","r",stdin);
	//   freopen("output.txt","w",stdout);
	//   freopen("error.txt", "w", stderr);
	// #endif
	int tc = 1;
	//cin >> tc;
	f1(t,tc) {
		// cout << "Case #" << t  << ": ";
		solve();
	}
}