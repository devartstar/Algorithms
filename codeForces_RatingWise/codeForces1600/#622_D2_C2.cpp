/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-10-19 16:01:05 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/problemset/problem/1313/C2
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
#define f0(i, n) for (int i = 0; i < n; i++)            // 0 based indexing
#define f1(i, n) for (int i = 1; i <= n; i++)           // 1 based indexing
#define f(i, a, b) for (int i = a; i <= b; i++)         // 1 based indexing
#define fll0(i, n) for (long long i = 0; i < n; i++)    // 0 based indexing
#define fll1(i, n) for (long long i = 1; i <= n; i++)   // 1 based indexing
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
    ll n;
    cin>>n;
    ll m[n+2];
    ll ans[n+2];
    m[0] = m[n+1] = 0;
    ans[0] = ans[n+1] = 0;
    ll a[n+1];
    vector<pll> v;
    for(ll i=1;i<=n;i++)
    {
        cin>>m[i];
        v.pb({m[i],i});
    }
    sort(v.begin(),v.end());
    
    set<ll> s;
    s.insert(0ll);
        for(ll i=0;i<n;i++)
        {
        auto pos = s.lower_bound(v[i].ss);
        pos--;
        //trace(v[i].ss,*pos);
        ans[v[i].ss] = ans[*pos] + m[v[i].ss]*(v[i].ss - *pos);
        s.insert(v[i].ss);
        }
    
    v.clear();
    reverse(m+1,m+n+1);
    for(ll i=1;i<=n;i++)
    {
        v.pb({m[i],i});
    }
    sort(v.begin(),v.end());
    
    set<ll> s1;
    s1.insert(0ll);
    ll ans1[n+2]={0};
    for(ll i=0;i<n;i++)
    {
    auto pos = s1.lower_bound(v[i].ss);
    pos--;
    //trace(v[i].ss,*pos);
    ans1[v[i].ss] = ans1[*pos] + m[v[i].ss]*(v[i].ss - *pos);
    s1.insert(v[i].ss);
    }
    reverse(ans1+1,ans1+n+1);
    reverse(m+1,m+n+1);
    ll pos=1,maxi = -MOD;
    for(ll i=1;i<=n;i++)
    {
        if(ans[i]+ans1[i]-m[i]>maxi)
        {
        maxi = ans[i]+ans1[i]-m[i];
        pos = i;
        }
    }
    a[pos] = m[pos];
    for(ll i=pos+1;i<=n;i++)
    {
        a[i] = min(m[i],a[i-1]);
    }
    for(ll i=pos-1;i>=1;i--)
    {
        a[i] = min(m[i],a[i+1]);
    }
    for(ll i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
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