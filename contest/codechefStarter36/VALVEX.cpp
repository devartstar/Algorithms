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

ll n;	
vll odd, even;

// true 	-> starts with odd
// false 	-> starts with even
pll calc(bool alice, bool bob) {
	ll aliceval, bobval;
	aliceval = bobval = 0;
	ll oddpos, evenpos;
	oddpos = evenpos = 0;
	bool alicechance = true, bobchance = true;
	while(alicechance || bobchance) {
		if(alice) {
			if(oddpos < odd.size()) {
				aliceval += odd[oddpos]; 
				oddpos++;
				alicechance = true;
			}else{
				alicechance = false;
			}
		}else{
			if(evenpos < even.size()) {
				aliceval += even[evenpos];
				evenpos++;
				alicechance = true;
			}else{
				alicechance = false;
			}
		}

		if(bob) {
			if(oddpos < odd.size()) {
				bobval += odd[oddpos]; 
				oddpos++;
				bobchance = true;
			}else{
				bobchance = false;
			}
		}else{
			if(evenpos < even.size()) {
				bobval += even[evenpos];
				evenpos++;
				bobchance = true;
			}else{
				bobchance = false;
			}
		}

		if(alicechance) alice = !alice;
		if(bobchance) bob = !bob;

		debug(mp(aliceval, bobval));
	}
	return mp(aliceval, bobval);
}

void solve() {
	odd.clear();
	even.clear();
	cin>>n;
	vll v(n);
	f0(i,n)	{
		cin>>v[i];
		if(v[i] & 1)	odd.pb(v[i]);
		else even.pb(v[i]);
	}
	sort(all(even), greater<int>());
	sort(all(odd), greater<int>());
	pll val1 = calc(true, true);
	pll val2 = calc(true, false);
	pll val3 = calc(false, true);
	pll val4 = calc(false, false);

	ll finans1, finans2;
	if(val1.ss > val2.ss) {
		finans1 = val1.ff;
	}else if(val1.ss < val2.ss) {
		finans1 = val2.ff;
	}else {
		finans1 = max(val1.ff, val2.ff);
	}

	if(val3.ss > val4.ss) {
		finans2 = val3.ff;
	}else if(val3.ss < val4.ss) {
		finans2 = val4.ff;
	}else {
		finans2 = max(val3.ff, val4.ff);
	}

	cout << max(finans1, finans2) << endl;

	// debug(val1);
	// debug(val2);
	// debug(val3);
	// debug(val4);
	// ll ans = -INF, temp = -INF;
	// if(val1.ff >= val1.ss) {
	// 	if(val1.ss > temp) {
	// 		temp = val1.ss;
	// 		ans = val1.ff;
	// 	}else if(val1.ss == temp) {
	// 		ans = max(ans, val1.ff*1ll);
	// 	}
	// }
	// if(val2.ff >= val2.ss) {
	// 	if(val2.ss > temp) {
	// 		temp = val2.ss;
	// 		ans = val2.ff;
	// 	}else if(val2.ss == temp) {
	// 		ans = max(ans, val2.ff*1ll);
	// 	}
	// }
	// if(val3.ff >= val3.ss) {
	// 	if(val3.ss > temp) {
	// 		temp = val3.ss;
	// 		ans = val3.ff;
	// 	}else if(val3.ss == temp) {
	// 		ans = max(ans, val3.ff*1ll);
	// 	}
	// }
	// if(val4.ff >= val4.ss) {
	// 	if(val4.ss > temp) {
	// 		temp = val4.ss;
	// 		ans = val4.ff;
	// 	}else if(val4.ss == temp) {
	// 		ans = max(ans, val4.ff*1ll);
	// 	}
	// }
	// cout << ans << endl;
	// cout << max(
	// 			max(val1, val2),
	// 			max(val3, val4))
	// 	 << endl;
	// cout << max(calc(true, false), calc(false, true)) << endl;
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