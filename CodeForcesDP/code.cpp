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

struct str{
    int ca=0, cb=0, cc=0;
};

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    vi posa;
    f0(i,n){
        if(s[i]=='a')   posa.pb(i);
    }

    vector<str> freq(n+1);
    if(s[0]=='a')   freq[0].ca = 1, freq[0].cb = 0, freq[0].cc = 0;
    if(s[0]=='b')   freq[0].ca = 0, freq[0].cb = 1, freq[0].cc = 0;
    if(s[0]=='c')   freq[0].ca = 0, freq[0].cb = 0, freq[0].cc = 1;

    for(int i=1; i<(int)s.length(); i++){
        if(s[i] == 'a'){
            freq[i].ca = freq[i-1].ca + 1;
            freq[i].cb = freq[i-1].cb;
            freq[i].cc = freq[i-1].cc;
        }
        if(s[i] == 'b'){
            freq[i].ca = freq[i-1].ca;
            freq[i].cb = freq[i-1].cb + 1;
            freq[i].cc = freq[i-1].cc;
        }
        if(s[i] == 'c'){
            freq[i].ca = freq[i-1].ca;
            freq[i].cb = freq[i-1].cb;
            freq[i].cc = freq[i-1].cc + 1;
        }
    }
    // for(int len=2; len<=100; len++){
    //     for(int j=0; j<n-(len-1); j++){
    //         int counta = freq[j+len-1].ca - (j-1>=0?freq[j-1].ca:0);
    //         int countb = freq[j+len-1].cb - (j-1>=0?freq[j-1].cb:0);
    //         int countc = freq[j+len-1].cc - (j-1>=0?freq[j-1].cc:0);
    //         if(counta > max(countb, countc)){
    //             cout<<len<<endl;
    //             return;
    //         }
    //     }
    // }
    debug(posa);

    for(int i=0; i<(int)posa.size(); i++){
        for(int j=i+1; j<(int)posa.size(); j++){
            int counta = freq[posa[j]].ca - (posa[i]-1>=0?freq[posa[i]-1].ca:0);
            int countb = freq[posa[j]].cb - (posa[i]-1>=0?freq[posa[i]-1].cb:0);
            int countc = freq[posa[j]].cc - (posa[i]-1>=0?freq[posa[i]-1].cc:0);
            debug(mp(i,j));
            debug(mp(counta, mp(countb, countc)));
            if(counta > max(countb,countc)){
                cout<<posa[j]-posa[i]+1<<endl;
                return;
            }
        }
    }

    cout<<-1<<endl;
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