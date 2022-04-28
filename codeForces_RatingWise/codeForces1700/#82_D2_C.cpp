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

struct str {
	int a, b, c, d;
	lld temp;
};

bool cmp(str x, str y) {
	return x.temp > y.temp;
}

void solve() {
	ll n, m, c, d;
	cin >> n >> m >> c >> d;
	
	vector<str> v(m);
	f0(i, m) cin >> v[i].a >> v[i].b >> v[i].c >> v[i].d, v[i].temp = double(v[i].d * 1.0 / v[i].c);
	
	sort(all(v), cmp);

	bool done = false;
	ll ans = 0, left = n, i = 0;
	while(left > 0) {
		if(!done && (lld)(d*1.0 / c) > v[i].temp) {
			ans += ((left / c) * d);
			left = left % c;
			done = true;
			continue;
		}
		i++;
		if(left / v[i].c < v[i].a / v[i].b) {
			ans += (left / v[i].c) * v[i].d;
			left = left % v[i].c;
		}else{
			ans += (v[i].a / v[i].b) * v[i].d;
			left = left - (v[i].a / v[i].b) * v[i].c;
		}
		i++;
		if(i >= m)
			break;
	}
	if(!done) {
		ans += ((left / c) * d);
		done = true;
	}
	cout << ans << endl;
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