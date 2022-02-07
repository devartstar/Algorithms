/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - ___________________ 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/problemset/problem/1167/C
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

const int MAX_N = 5*(1e5 + 1);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vi parent(MAX_N, -1);
vi R(MAX_N, 1);

int find(int a){
    if(parent[a]<0) return a;
    int x = find(parent[a]);
    return parent[a] = x;
}

void combine(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b)    return;
    if(a>b){
        parent[b] = a;
        R[a] += R[b];
    }else{
        parent[a] = b;
        R[b] += R[a];
    }
}

// DSU Solution
void solve(){
    int n,m;
    cin>>n>>m;
    f0(i,m){
        debug(m);
        int k,a,b;
        cin>>k;
        if(k==0)    continue;
        cin>>a;
        for(int i=2;i<=k;i++){
            int b;
            cin>>b;
            int x = find(a);
            int y = find(b);
            combine(x,y);
            R.resize(n+1);
            parent.resize(n+1);
        }
    }
    debug(parent);
    debug(R);
    f1(i,n){
        cout<<R[find(i)]<<" ";
    }
    cout<<endl;
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
    debug("lol");
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}

/*
vi v[MAX_N];
vi visited(MAX_N);
vi order;

void dfs(int node){
    visited[node] = 1;
    order.pb(node);

    for(int child : v[node]){
        if(!visited[child]){
            dfs(child);
        }
    }
}

void solve() {
    int n, m;
    cin>>n>>m;
    f0(i,m){
        int k, a;
        cin>>k;
        if(k>0){
            cin>>a;
            for(int i=2;i<=k;i++){
                int b;  cin>>b;
                v[a].pb(b);
                v[b].pb(a);
            }   
        }
    }

    vi ans(n+1);
    f1(i,n){
        if(!visited[i]){
            order.clear();
            dfs(i);
            for(int x : order){
                ans[x] = (int)order.size();
            }
        }
    }

    f1(i,n) cout<<ans[i]<<" ";
    cout<<endl;
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
}*/