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
    ll n, k;
    cin>>n>>k;
    vll v(n);
    vll pos;
    f0(i,n){
        cin>>v[i];
        if(v[i]>0){
            pos.pb(i);
        }
    }

    vll size0;
    for(int i=0; i<(ll)pos.size()-1;i++){
        ll temp = abs(pos[i+1]-pos[i]) - 1;
        if(temp>0){
            size0.pb(temp);
        }
    }
    if(pos.size()>0){
        int temp = pos[0] + (n-1) - pos[(ll)pos.size()-1];
        if(temp>0){
            size0.pb(temp);
        }
    }

    ll ans = 0, left, right;
    for(int i=0; i<(int)pos.size(); i++){
        if(pos[i] == 0){
            left = n-1;
            right = 1;
        }
        else if(pos[i]==(n-1)){
            left = n-2;
            right = 0;
        }else{
            left = pos[i] - 1;
            right = pos[i] + 1;
        }

        int cnt = 0;
        if(v[left]>0)   cnt++;
        if(v[right]>0)   cnt++;

        if(cnt==2){
            ans = ans + v[pos[i]] + k*2;
        }
        if(cnt==1){
            ans = ans + v[pos[i]] + 1 + (k-1)*2;
        }
        if(cnt==0){
            ans = ans + v[pos[i]] + (k-1)*2;
        }
    }

    int a;
    for(int i=0; i<(int)size0.size(); i++){
        if(size0[i] % 2 == 1){
            a = (size0[i]+1)/2;  
        }else{
            a = size0[i]/2;
        }

        if(k<=a){
            ans = ans + 2*(k-1)*(k) + 2;
        }else{
            ans = ans + 2*(a-1)*(a) + 2 + (k-a)*2*size0[i];
        }
    }

    cout<<ans<<endl;
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