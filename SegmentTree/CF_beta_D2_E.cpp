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

vi first_iter(MAX_N);
 
vi v(MAX_N);
vi segtree[4*MAX_N];
vpii segtree[4*MAX_N];

void buildMergeTree(int si, int segstart, int segend){
    if(segstart == segend){
        segtree[si].pb(v[segstart]);
        return;
    }
    int mid = segstart + (segend - segstart)/2;
    buildMergeTree(2*si, segstart, mid);
    buildMergeTree(2*si + 1, mid+1, segend);
    
    int i=0, j=0;
    while(i < segtree[2*si].size() && j < segtree[2*si+1].size()){
        if(segtree[2*si][i] <= segtree[2*si+1][j]){
            segtree[si].pb(segtree[2*si][i]);
            i++;
        }else{
            segtree[si].pb(segtree[2*si+1][j]);
            j++;
        }
    }
    while(i < segtree[2*si].size()){
        segtree[si].pb(segtree[2*si][i]);
        i++;
    }
    while(j < segtree[2*si+1].size()){
        segtree[si].pb(segtree[2*si+1][j]);
        j++;
    }
}

void buildMergeTree1(int si, int segstart, int segend){
    if(segstart == segend){
        segtree[si].pb(v[segstart]);
        return;
    }
    int mid = segstart + (segend - segstart)/2;
    buildMergeTree(2*si, segstart, mid);
    buildMergeTree(2*si + 1, mid+1, segend);
    
    int i=0, j=0;
    while(i < segtree[2*si].size() && j < segtree[2*si+1].size()){
        if(segtree[2*si][i] <= segtree[2*si+1][j]){
            segtree[si].pb(segtree[2*si][i]);
            i++;
        }else{
            segtree[si].pb(segtree[2*si+1][j]);
            j++;
        }
    }
    while(i < segtree[2*si].size()){
        segtree[si].pb(segtree[2*si][i]);
        i++;
    }
    while(j < segtree[2*si+1].size()){
        segtree[si].pb(segtree[2*si+1][j]);
        j++;
    }
}

int query(int si, int segstart, int segend, int querystart, int queryend, int val){
    // COMPLETELY OUTSIDE
    if(querystart > segend || queryend < segstart){   
        return 0;
    }
    
    // COMPLETELY INSIDE
    if(segstart >= querystart && segend<=queryend){     
        return (lower_bound(all(segtree[si]), val) - segtree[si].begin());
    }
    
    int mid = segstart + (segend - segstart)/2;
    
    int left = query(2*si, segstart, mid, querystart, queryend, val);
    int right = query(2*si+1, mid+1, segend, querystart, queryend, val);
    
    return (left + right);
}

void solve() {
    int n;
    cin>>n;
    f1(i,n){
        cin>>v[i];
    }
    buildMergeTree(1,1,n);
    f1(i,n){
        first_iter[i] = query(1,1,n,i+1,n,v[i]);
    }
    debug(first_iter);

    buildMergeTree1(1,1,n);
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