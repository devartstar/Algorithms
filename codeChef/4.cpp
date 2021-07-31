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


void solve() {
    int n;
    cin>>n;
    vi a(n), b(n);
    f0(i,n) cin>>a[i];
    f0(i,n) cin>>b[i];
    vi c(n);
    ll min = n+1;
    f0(i,n){
        c[i] = (a[0]+b[i])%n;
        if(c[i]<min){
            min = c[i];
        }
    }
    vi pos;
    f0(i,n){
        if(c[i]==min)   pos.pb(i);
    }
    vi res[(int)pos.size()];
    for(int i =0; i<(int)pos.size();i++){
        int start = pos[i];
        int k = 0;
        while(k<n){
            int pp = (start + k)%n;
            res[i].pb((a[k]+b[pp])%n);
            k++;
        }
    }
    f0(i,(int)pos.size()){
        debug(res[i]);
    }
    if((int)pos.size()==1){
        f0(i,n) cout<<res[0][i]<<" ";
        cout<<endl;
        return;
    }
    int dd;
    f0(i,n){
        bool ok = false;
        int mn = res[0][i];
        dd = 0;
        f0(j,(int)pos.size()){
            if(res[j][i]<mn){
                mn = res[j][i];
                ok = true;
                dd = j;
            }
            if(res[i][j]>mn){
                res[i].clear();
                res[i].insert(res[i].end(),n, n+1);
            }
        }
        if(ok == true){
            break;
        }
    }
    f0(i,n) cout<<res[dd][i]<<" ";
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
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}