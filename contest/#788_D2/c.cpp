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

ll pow(ll x, ll y, ll m){
    ll ans = 1;
    ll r = 1;
    while(r<=y){
        if(r&y){
            ans = (1LL*ans*x)%m;
        }
        x = (1LL*x*x)%m;
        r = r<<1;
    }
    return ans;
}

void solve() {
	ll n;
	cin >> n;
	vll a(n+1), b(n+1), c(n+1);
	vector<bool> ok(n+5, false), done(n+5, false);
	map<ll, ll> ma, mb;
	f1(i,n) {
		cin >> a[i];
		ma[a[i]] = i;
	}
	f1(i,n) {
		cin >> b[i];
		mb[b[i]] = i;
	}
	f1(i,n) {
		cin >> c[i];
		if(c[i] > 0)
			ok[i] = true;
	}


	ll i = 1, ans = 0;
	vll temp;
	while(i < n) {
		if(done[i] == true)	{
			i++;
			continue;
		}
		done[i] = true;
		if(a[i] == b[i]) {
			i++;
			continue;
		}	

		temp.clear();
		bool row = true;
		// int xx = b[i], curr = a[i], next = b[mb[curr]];
		ll xx = b[i];
		ll curr = a[i];
		temp.pb(i);

		while(curr != xx) {
			debug(curr);
			ll col;
			if(row == true) {
				col = mb[curr];
				curr = a[col];
			}else {
				col = ma[curr];
				curr = b[col];
			}
			debug(col);
			temp.pb(col);
			done[col] = true;
		}

		debug(temp);
		bool okk = true;
		for(ll x : temp) {
			if(ok[x]) {
				okk = false;
				break;
			}
		}
		if(okk)
			ans++;
		i++;
	}
	cout << pow(2, ans, MOD) << endl;
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