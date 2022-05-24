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


void solve() {
	int n, k;	cin>>n>>k;
	string s;	cin>>s;

	vector<char> ch(26);
	f0(i, 26) ch[i] = ('a' + i);
	debug(ch);

	ll sum = k, prev;
	ll temp = s[0] - 'a';
	debug(temp);
	if(sum - temp < 0) {
		for (int i = 0; i <= sum; i++) {
			ch[s[0] - 'a' - i] = ch[s[0] - 'a' - sum];
		};
		sum = 0;
	}else{
		for (int i = 0; i <= temp; i++) {
			ch[s[0] - 'a' - i] = ch[s[0] - 'a' - temp];
		};
		sum -= temp;
	}
	prev = 0;
	debug(ch);
	if(sum == 0) {
		//convert string
		f0(i, n) {
			s[i] = ch[s[i] - 'a'];
		}
		cout << s << endl;
		return;
	}
	debug(sum);

	f0(i,n)	{
		if(s[i] <= s[prev]) continue;
		ll temp = s[i] - s[prev];
		char cc = s[i];
		debug(cc);
		debug(temp);
		if(sum - temp < 0) {
			debug(cc - sum - 'a');
			for (int i = 0; i <= sum; i++) {
				ch[cc - 'a' - i] = ch[cc - 'a' - sum];
			};
			sum = 0;
			break;
		}else{
			debug(cc - temp - 'a');
			for (int i = 0; i <= temp; i++) {
				ch[cc - 'a' - i] = ch[cc - 'a' - temp];
			};
			sum -= temp;
		}
		debug(ch);
		prev = i;
	}
	
	//convert string
	f0(i, n) {
		s[i] = ch[s[i] - 'a'];
	}
	cout << s << endl;
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