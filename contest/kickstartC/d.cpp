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
#define pll pair<long, long>
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
#define sz(v) (int)v.size();
#define len(v) (int)v.length();

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


vll fact(410);
vll invfact(410);

ll pow(ll x,ll y,ll m){
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

ll modInv(ll n, ll m){
    return pow(n, m-2, m);
}

void compute() {
    fact[0] = 1;
    for(int i=1; i<405; i++){
		fact[i] = (1LL * i * fact[i - 1]) % MOD;
	}

	invfact[404] = modInv(fact[404], MOD);
	for(int i=403; i>=0; i--){
		invfact[i] = ((1LL * (i + 1) * invfact[i + 1]) % MOD);
	}
    debug(fact);
    debug(invfact);
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = " " + s;
	int dp[n+1][n+1][n+1];
	f0(i, n+1) f0(j, n+1) f0(k, n+1) dp[i][j][k] = 0;
	for (int i = n; i > 0; i--) {
		for (int j = i; j <= n; j++) {
			dp[i][j][0] = 1;
			dp[i][j][1] = j - i + 1;
			if (i == j)
				continue;
			if(i == j - 1) {
				dp[i][j][2] = s[i] == s[j];
				continue;
			}
			for (int k = 2; k <= n; k++){
				dp[i][j][k] = ((dp[i][j - 1][k] % MOD) + (dp[i + 1][j][k] % MOD) + (MOD - dp[i + 1][j - 1][k]) % MOD) % MOD;
				dp[i][j][k] = ((dp[i][j][k] % MOD) + (((s[i] == s[j]) * dp[i + 1][j - 1][k - 2]) % MOD)) % MOD;
			}
		}
	}
	ll ans = 0;
	f0(i, n) {
		ll temp = dp[1][n][i];
		temp = ((temp % MOD) * (fact[i] % MOD)) % MOD;
		temp = ((temp % MOD) * (fact[n-i] % MOD)) % MOD;
		temp = ((temp % MOD) * (invfact[n] % MOD)) % MOD;
		ans = ((ans % MOD) + (temp % MOD)) % MOD;
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
	compute();
	cin >> tc;
	f1(t,tc) {
		cout << "Case #" << t  << ": ";
		solve();
	}
}
