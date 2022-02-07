/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-10-15 22:57:24 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/problemset/problem/1215/C
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
    int n;
    cin>>n;
    string s1, s2;
    cin>>s1>>s2;
    vi ab;
    vi ba;
    f0(i,n){
        if(s1[i]=='a' && s2[i]=='b')    ab.pb(i);
        if(s1[i]=='b' && s2[i]=='a')    ba.pb(i);
    }
    int ablen = (int)ab.size();
    int balen = (int)ba.size();
    if(ablen%2 != balen%2){
        cout<<"-1"<<endl;
        return;
    }
    if(ablen == 0 & balen == 0){
        cout<<"0"<<endl;
        return;
    }
    if(ablen%2==0 && balen%2==0){
        cout<<(ablen + balen)/2<<endl;
        for(int i=0; i<ablen; i+=2){
            cout<<ab[i]+1<<" "<<ab[i+1]+1<<endl;
        }
        for(int i=0; i<balen; i+=2){
            cout<<ba[i]+1<<" "<<ba[i+1]+1<<endl;
        }
    }
    if(ablen%2==1 && balen%2==1){
        cout<<(ablen + balen)/2 + 1<<endl;
        if(ablen > 0){
            ablen--;
            balen++;
            ba.push_back(ab.back());
            cout<<ab.back()+1<<" "<<ab.back()+1<<endl;
        }else{
            balen--;
            ablen++;
            ab.push_back(ba.back());
            cout<<ba.back()+1<<" "<<ba.back()+1<<endl;
        }
        for(int i=0; i<ablen; i+=2){
            cout<<ab[i]+1<<" "<<ab[i+1]+1<<endl;
        }
        for(int i=0; i<balen; i+=2){
            cout<<ba[i]+1<<" "<<ba[i+1]+1<<endl;
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
    //cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}