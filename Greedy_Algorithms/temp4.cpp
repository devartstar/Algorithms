/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-10-14 09:46:55 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/problemset/problem/1196/D1
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
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;

    // R -> 0   G -> 1 B -> 2
    vector<int> diffRGB(n);
    vector<int> prefixsumRGB(n);
    int temp = 0;
    char ch;
    f0(i,n){
        if(i%3 == 0)    ch = 'R';
        if(i%3 == 1)    ch = 'G';
        if(i%3 == 2)    ch = 'B';
        if(s[i] != ch)  diffRGB[i] = 1;
        else            diffRGB[i] = 0;
        if(i==0)    prefixsumRGB[i] = diffRGB[i];
        else        prefixsumRGB[i] = prefixsumRGB[i-1] + diffRGB[i];
    }

    // R -> 1   G -> 2  B -> 0
    vector<int> diffBRG(n);
    vector<int> prefixsumBRG(n);
    temp = 0;
    f0(i,n){
        if(i%3 == 0)    ch = 'B';
        if(i%3 == 1)    ch = 'R';
        if(i%3 == 2)    ch = 'G';
        if(s[i] != ch)  diffBRG[i] = 1;
        else            diffBRG[i] = 0;
        if(i==0)    prefixsumBRG[i] = diffBRG[i];
        else        prefixsumBRG[i] = prefixsumBRG[i-1] + diffBRG[i];
    }

    // R -> 2   G -> 0  B -> 1
    vector<int> diffGBR(n);
    vector<int> prefixsumGBR(n);
    temp = 0;
    f0(i,n){
        if(i%3 == 0)    ch = 'G';
        if(i%3 == 1)    ch = 'B';
        if(i%3 == 2)    ch = 'R';
        if(s[i] != ch)  diffGBR[i] = 1;
        else            diffGBR[i] = 0;
        if(i==0)    prefixsumGBR[i] = diffGBR[i];
        else        prefixsumGBR[i] = prefixsumGBR[i-1] + diffGBR[i];
    }

    debug(diffRGB);
    debug(prefixsumRGB);

    debug(diffBRG);
    debug(prefixsumBRG);

    debug(diffGBR);
    debug(prefixsumGBR);

    //1 2 3
    // now find the min sum ok subset of length k
    // prefix sum
    int mnRBG = INF;
    f0(i,n-k+1){
        mnRBG = min(mnRBG, prefixsumRGB[i+k-1] - (i-1 >=0 ? prefixsumRGB[i-1] : 0));
    }
    int mnBRG = INF;
    f0(i,n-k+1){
        mnBRG = min(mnBRG, prefixsumBRG[i+k-1] - (i-1 >= 0 ? prefixsumBRG[i-1] : 0));
    }

    int mnGBR = INF;
    f0(i,n-k+1){
        mnGBR = min(mnGBR, prefixsumGBR[i+k-1] - (i-1 >= 0? prefixsumGBR[i-1] : 0));
    }

    cout<<min(mnRBG, min(mnBRG, mnGBR))<<endl;
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