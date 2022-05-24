/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - ___________________ 	|	
	|    	                            |
	-------------------------------------

	Link - LIS (not same)
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


// O(n * log(n)) <-- time complexity 
vll LIS(vi arr) {
	vi sols;
	for(auto v : arr) {
		if (sols.empty() || v > sols.back()) {
			sols.pb(v);
		}else{
			auto it = lower_bound(all(sols), v);
			*it = v;
		}
	}
	debug(sols);
	int val = sols.back();
	vll ans;
	ans.pb(val);
	ll ind = (int)arr.size() - 1;
	while(ind >= 0) {
		if(arr[ind] > ans.back()) {
			ans.erase(ans.begin() + ans.size() - 1);
			ans.pb(arr[ind]);
		}else if(arr[ind] < ans.back()){
			ans.pb(arr[ind]);
		}
		ind--;
		debug(ans);
	}	
	reverse(all(ans));
	return ans;

	// print the seq
}

void solve() {
	int n;	cin>>n;
	vi v(n);
	f0(i,n)	cin>>v[i];

	// O(n^2) <- Time complexity
	vi dp(n, 0); 
	dp[0] = 1;
	f1(i,n-1){
		f0(j,i) {
			if(v[j] < v[i])	dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << "Method 1 : " << dp[n - 1] << endl;
	vll ans = LIS(v);
	cout << "Method 2 : " << ans.size() << endl;
	for(auto it : ans)
		cout << it << " ";
	cout << endl;
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