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
    int n,a=0;
    cin>>n;
    vi mn;
    vi mx;
    vi mn1;
    vi mx1;
    vi pos;
    f0(i,n){
        int l;
        cin>>l;
        int m1 = INF;
        int m2 = -1*INF;
        int pos1,pos2;
        f0(i,l){
            int x;
            cin>>x;
            if(x<m1){
                m1=x;
                pos1=i;
            }
            if(x>m2){
                m2=x;
                pos2=i;
            }
        }
        debug(m1);
        debug(m2);
        if(m1<m2){
            a++;
        }
        mn1.pb(m1);
        mx1.pb(m2);
        if(m1<m2 && pos1<pos2){
            pos.pb(i);
        }else{
            mn.pb(m1);
            mx.pb(m2);
        }
    }
    sort(all(mn));
    sort(all(mx));
    sort(all(mn1));
    sort(all(mx1));
    debug(mn);
    debug(mx);
    debug(pos);
    debug(a);
    ll ans=0;
    for(int i=0;i<(int)mx.size();i++){
        int a = mx[i];
        auto it = lower_bound(all(mn1),a);
        int c = it - mn1.begin();
        // int c1;
        // if(*it==mx[c]){
        //     c1=(int)mx.size()-c-1;
        // }else{
        //     c1=(int)mx.size()-c;
        // }
        debug(c);
        ans+=c;
    }
    debug(ans);
    int ans1 = (int)pos.size()*(n-1)*2+(int)pos.size();
    debug(ans1);
    cout<<ans-a+ans1<<endl;
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