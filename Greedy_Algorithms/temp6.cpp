/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-10-14 16:09:25 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/problemset/problem/1195/D1
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
const ll MOD = 998244353;
const ll INF = 1e9;

ll clacLength(ll n){
    ll c=0;
    while(n>0){
        c++;
        n/=10;
    }
    return c;
}

ll power(ll x, ll y, ll m){
    ll ans = 1;
    ll r = 1;
    while(r<=y){
        if(r&y){
            ans = (1LL*ans*x)%m;
        }
        x = (1LL*x*x)%m;
        r = r<<1;
    }
    return ans%m;
}

void solve() {
    ll n;
    cin>>n;
    vll v(n);
    fll0(i,n) cin>>v[i];
    ll len = clacLength(v[0]);
    ll arr[n][len];
    fll0(i,n){
        ll num = v[i];
        ll k = len-1;
        while(num > 0){
            arr[i][k] = num%10;
            k--;
            num/=10;
        }
    }

    vll sum(len, 0);
    fll0(j,len){
        fll0(i, n){
            sum[j] += arr[i][j];
        }
    }
    debug(sum);

    ll temp = 2*len - 1;
    ll ans = 0;
    fll0(i,len){
        ll r = ((sum[i]%MOD)*(n%MOD))%MOD;
        ans = (ans + ((r%MOD)*(ll)power(10, temp, MOD))%MOD)%MOD;
        temp--;
        r = ((sum[i]%MOD)*(n%MOD))%MOD;
        ans = (ans + ((r%MOD)*(ll)power(10, temp, MOD))%MOD)%MOD;
        temp --;
    }
    cout<<ans%MOD<<endl;
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