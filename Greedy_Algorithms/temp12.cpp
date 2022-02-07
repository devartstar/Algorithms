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


void solve() {
    ll n, l;
    cin>>n>>l;
    vll v(n+2);
    v[0] = 0;
    fll1(i,n) cin>>v[i];
    v[n+1] = l;
    vll speeda(n+2);
    vll speedb(n+2);
    fll0(i,n+2){
        speeda[i] = i;
        speedb[n+1-i] = i;
    }
    vector<double> ta(n+2);
    vector<double> tb(n+2);
    ta[0] = tb[n+1] = 0.0;
    fll1(i,n+1){
        ta[i] = ((v[i] - v[i-1])*1.0)/speeda[i];
        ta[i] += ta[i-1];
    }
    for(ll i=n; i>=0; i--){
        tb[i] = ((v[i+1] - v[i])*1.0)/speedb[i];
        tb[i] += tb[i+1];
    }
    
    for(int i=0; i<=n; i++){
        double temp = (speeda[i+1]*speedb[i]*1.0)/(speeda[i+1] + speedb[i]);
        // debug(temp);
        double pos = tb[i+1] - ta[i] + (v[i]*1.0)/speeda[i+1] + (v[i+1]*1.0)/speedb[i];
        // debug(pos);
        pos = (pos*1.0)*temp;
        // debug(v[i]);
        // debug(v[i+1]);
        // debug(pos);
        if(pos - v[i] >= 0.0000001 && pos - v[i+1] <= 0.000000001){
            double calctime = ta[i] +((pos - v[i])*1.0)/speeda[i+1];
            // debug(calctime);
            printf("%0.8f\n", calctime);
            break;
        }
    }

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