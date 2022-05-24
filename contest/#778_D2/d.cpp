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

ll n;
vll graph[MAX_N];
vpll val;
map<pii, pii> m;
vll occ;
vi visited(MAX_N, 0);
//	DFS IMPLEMENTATION IN ADJACENCY LIST
void dfs(ll node) {
	visited[node]=1;
	occ.pb(node);
	for(ll child : graph[node]){
		if(!visited[child]){
			// node -> child
			pii temp1 = m[mp(node, child)];
			pii temp2 = m[mp(child, node)];
			if(temp1 != mp(0,0)) {
				// child = y / x *node
				val[child].ff = val[node].ff * temp1.ss;
				val[child].ss = val[node].ss * temp1.ff;
			}
			else if(temp2 != mp(0,0)) {
				// child = x / y *node
				val[child].ff = val[node].ff * temp2.ff;
				val[child].ss = val[node].ss * temp2.ss;
			} else {
				val[child] = val[node];
			}
			dfs(child);
		}
	}
}


void solve() {
	ll n;
	cin >> n;
	f1(i,n) {
		graph[i].clear();
	}
	val.assign(n + 1, mp(1, 1));
	m.clear();
	visited.assign(n + 1, 0);
	f1(i,n-1) {
		ll a, b, x, y;
		cin >> a >> b >> x >> y;
		graph[a].pb(b);
		graph[b].pb(a);
		m[mp(a, b)] = mp(x, y);
	}
	debug(m);
	f1(i, n) {
		cout << i << " : ";
		disp(graph[i]);
	}
	ll ans = 0;
	f1(i,n) {
		occ.clear();
		if(!visited[i]) {
			debug(i);
			dfs(i);
			disp1(visited, n);
			f1(i, n) cout << i << " : " << val[i].ff << " " << val[i].ss << endl;
			if((int)occ.size() > 0) {
				ll lcm;
				f0(i, (int)occ.size()) {
					ll temp = __gcd(val[occ[i]].ff, val[occ[i]].ss);
					val[occ[i]].ff /= temp;
					val[occ[i]].ss /= temp;
					if (i == 0) {
						lcm = val[occ[0]].ss;
						continue;
					}
					lcm = (lcm * val[occ[i]].ss) / __gcd(lcm, val[occ[i]].ss);
				}
				f0(i, (int)occ.size()) {					
					ans += (val[occ[i]].ff * (lcm / val[occ[i]].ss));
				}
			}
		}
	}
	// f1(i,n) {
	// 	cout << i << " : " << val[i].ff << " " << val[i].ss << endl;
	// }
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
