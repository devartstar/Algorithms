/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-07-14 19:51:05 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/problemset/problem/1528/A
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

vector<ll> v[200001];
ll dp[2][200001];
map<ll, pll> m;

void dfs(int node, int parent = -1){
    dp[0][node]  = dp[1][node] = 0;
    for(int child : v[node]){
        if(child == parent) continue;
        dfs(child, node);
        dp[0][node] +=  max(
            abs(m[node].ff - m[child].ff) + dp[0][child],
            abs(m[node].ff - m[child].ss) + dp[1][child]
        );
        dp[1][node] += max(
            abs(m[node].ss - m[child].ff) + dp[0][child],
            abs(m[node].ss - m[child].ss) + dp[1][child]
        );
    }
}


void solve() {
    ll n;
    cin>>n;
    fll1(i,n){
        int l,r;
        cin>>l>>r;
        m[i] = mp(l,r);
    }
    fll1(i,n-1){
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1);
    // f0(i,n){
    //     cout<<dp[0][i]<<" ";
    // }
    // cout<<endl;
    // f0(i,n){
    //     cout<<dp[1][i]<<" ";
    // }
    debug(m);
    cout<<max(dp[0][1], dp[1][1])<<endl;
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
        fll0(i,200001){
            v[i].clear();
            dp[0][i] = 0;
            dp[1][i] = 0;
        }
        solve();
    }
}