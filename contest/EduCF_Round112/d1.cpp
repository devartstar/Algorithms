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
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;

    vector<string> v(6);
    f0(i,6) v[i]= "";
    int k = n/3;
    while(k--)  v[0] = v[0] + "abc";
    if(n%3==2)      v[0] = v[0] + "ab";
    else if(n%3==1) v[0] = v[0] + "a";
    
    k = n/3;
    while(k--)  v[1] = v[1] + "acb";
    if(n%3==2)      v[1] = v[1] + "ac";
    else if(n%3==1) v[1] = v[1] + "a";

    k = n/3;
    while(k--)  v[2] = v[2] + "bac";
    if(n%3==2)      v[2] = v[2] + "ba";
    else if(n%3==1) v[2] = v[2] + "b";
    
    k = n/3;
    while(k--)  v[3] = v[3] + "bca";
    if(n%3==2)      v[3] = v[3] + "bc";
    else if(n%3==1) v[3] = v[3] + "b";
    
    k = n/3;
    while(k--)  v[4] = v[4] + "cab";
    if(n%3==2)      v[4] = v[4] + "ca";
    else if(n%3==1) v[4] = v[4] + "c";
    
    k = n/3;
    while(k--)  v[5] = v[5] + "cba";
    if(n%3==2)      v[5] = v[5] + "cb";
    else if(n%3==1) v[5] = v[5] + "c";
    
    f0(i,6){
        debug(v[i]);
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        int mn = INF;
        f0(i,6){
            int c = 0;
            f(j,l,r){
                if(s[j] != v[i][j])   c++;
            }
            mn = min(mn, c);
        }
        cout<<mn<<endl;;
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
    //cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}