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
    int n, k;
    cin>>n>>k;
    string s;   cin>>s;
    string t = "RGBRGBRGB";

    vi ans;
    int diff1, diff2, diff3, prev_diff1, prev_diff2, prev_diff3;
    diff1 = diff2 = diff3 = 0;

    for(int i=0; i<k; i++){
        if(s[i] != t[i%3])  diff1 ++;
        if(s[i] != t[1 + i%3])  diff2 ++;
        if(s[i] != t[2 + i%3])  diff3 ++;
    }
    debug(mp(diff1, mp(diff2, diff3)));
    ans.pb(diff1);
    ans.pb(diff2);
    ans.pb(diff3);

    char ch1_start = 'R';
    char ch2_start = 'G';
    char ch3_start = 'B';

    char ch1_end = t[k%3];
    char ch2_end = t[k%3 + 1];
    char ch3_end = t[2 + k%3];

    debug(ch1_end);
    debug(ch2_end);
    debug(ch3_end);

    for(int j=k; j<n; j++){
        int i = j-k+1;
        debug(i);
        prev_diff1 = diff1;
        prev_diff2 = diff2;
        prev_diff3 = diff3;
        debug(s[i]!=ch3_start);
        debug(s[j]!=ch3_end);
        diff1 = prev_diff3 - (s[i-1]!=ch3_start) + (s[j]!=ch3_end);
        diff2 = prev_diff1 - (s[i-1]!=ch1_start) + (s[j]!=ch1_end);
        diff3 = prev_diff2 - (s[i-1]!=ch2_start) + (s[j]!=ch2_end);
        debug(mp(diff1, mp(diff2, diff3)));
        ans.pb(diff1);  ans.pb(diff2);  ans.pb(diff3);
    }

    cout<<*min_element(all(ans))<<endl;
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