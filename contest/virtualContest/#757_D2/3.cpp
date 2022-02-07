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
#define vb vector<bool>
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
#define endl '\n'

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
vll v[55];
vector<pll> temp;

//	DFS IMPLEMENTATION IN 2D ARRAY
ll visited[55][55];
bool isValid(ll x,ll y){
    return (x>=0 && x<n && y>=0 && y<n && !visited[x][y] && v[x][y]==0 ); // Maybe some other conditions too
}

void dfs(ll x,ll y){
    visited[x][y]=1;
    temp.pb({x,y});
    if(isValid(x,y-1))	//top
        dfs(x,y-1);
    if(isValid(x+1,y))	//right
        dfs(x+1,y);
    if(isValid(x,y+1))	//down
        dfs(x,y+1);
    if(isValid(x-1,y))	//left
        dfs(x-1,y);
}

void solve(){
    cin>>n;
    pll x, y;
    cin>>x.ff>>x.ss; 
    cin>>y.ff>>y.ss; 
    f0(i,n){
        string s;
        cin>>s;
        f0(j,s.length())    v[i].pb(s[j]-'0');
    }
    dfs(x.ff-1,x.ss-1);
    vector<pll> v1 = temp;
    temp.clear();
    dfs(y.ff-1,y.ss-1);
    vector<pll> v2 = temp;

    // for(pll x : v1) cout<<x.ff<<","<<x.ss<<" ";
    // cout<<endl;
    // for(pll x : v2) cout<<x.ff<<","<<x.ss<<" ";
    // cout<<endl;

    ll ans = INF;
    for(pll k1 : v1){
        for(pll k2 : v2){
            ans = min(ans, ((k1.ff-k2.ff)*(k1.ff-k2.ff) + (k1.ss-k2.ss)*(k1.ss-k2.ss))*1ll);
        }
    }
    cout<<ans<<endl;
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
        solve();
    }
}