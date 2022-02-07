/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - ___________________ 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/contest/339/problem/D
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

const int MAX_N = 2e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


vll v(MAX_N);
vll segtree(4*MAX_N);
 
void buildTree(ll si, ll segstart, ll segend, ll lev, ll n){
    if(segstart == segend){
        segtree[si] = v[segstart];
        return;
    }
    ll mid = segstart + (segend - segstart)/2;
    buildTree(2*si, segstart, mid, lev+1, n);
    buildTree(2*si + 1, mid+1, segend, lev+1, n);
    
    if(n%2==0){
        if(lev%2==1){
           segtree[si] = segtree[2*si] | segtree[2*si+1]; 
        }else{
           segtree[si] = segtree[2*si] ^ segtree[2*si+1]; 
        }
    }else{
        if(lev%2==0){
           segtree[si] = segtree[2*si] | segtree[2*si+1]; 
        }else{
           segtree[si] = segtree[2*si] ^ segtree[2*si+1]; 
        }
    }
}

void update(ll si, ll segstart, ll segend, ll qi, ll val, ll lev, ll n){
    if(segstart == segend){
        segtree[si] = val;
        return;
    }
    
    ll mid = segstart + (segend - segstart)/2;
    
    if(qi <= mid){
        update(2*si, segstart, mid, qi, val, lev+1, n);
    }else{
        update(2*si+1, mid+1, segend, qi, val, lev+1, n);
    }
    
    if(n%2==0){
        if(lev%2==1){
           segtree[si] = segtree[2*si] | segtree[2*si+1]; 
        }else{
           segtree[si] = segtree[2*si] ^ segtree[2*si+1]; 
        }
    }else{
        if(lev%2==0){
           segtree[si] = segtree[2*si] | segtree[2*si+1]; 
        }else{
           segtree[si] = segtree[2*si] ^ segtree[2*si+1]; 
        }
    }
}

void solve() {

    ll n,r;
    cin>>n>>r;
    ll n1 = (ll)pow(2,n);
    f1(i,n1) cin>>v[i];

    buildTree(1,1,n1,0,n);
    segtree.resize(4*n1+1);
    
    while(r--){
        ll p,b;
        cin>>p>>b;
        update(1,1,n1,p,b,0,n);
        cout<<segtree[1]<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}