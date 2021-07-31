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

ll n;
vector<pll> v(10001);

bool check(){
    vector<pll> v1;
    pll a1, a2, x, y;
    a1 = v[1];
    a2 = v[2];
    x=a1, y=a2;
    fll(i,3,n){
        if((a2.ss-a1.ss)*(v[i].ff-a1.ff) != (v[i].ss-a1.ss)*(a2.ff-a1.ff)){
            v1.pb(v[i]);
        }
    }
    debug(v1);
    if((ll)v1.size()==0){
        debug("lol fasle 1");
        return false;
    }
    if((ll)v1.size()==1){
        debug("lol true 1");
        return true;
    }

    a1 = v1[0];
    a2 = v1[1];
    debug(x);
    debug(y);
    debug(a1);
    debug(a2);
    if((y.ss-x.ss)*(a2.ff-a1.ff) != (a2.ss-a1.ss)*(y.ff-x.ff)){
        debug("lol false lol");
        return false;
    }
    f(i,2,(ll)v1.size()-1){
        if((a2.ss-a1.ss)*(v1[i].ff-a1.ff) != (v1[i].ss-a1.ss)*(a2.ff-a1.ff)){
            // debug("lol false 2");
            return false;
        }
    }
    debug("lol true 2");
    return true;
}

void solve() {
    cin>>n;
    ll x;
    fll1(i,n) cin>>x, v[i] = mp(i,x);
    // debug(v);
    if(n==3){
        ll k = v[1].ff * (v[2].ss - v[3].ss) + v[2].ff * (v[3].ss - v[1].ss) + v[3].ff * (v[1].ss - v[2].ss);
        // debug(k);
        if(k==0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
        return;
    }


    ll ans1 = false, ans2 = false;

    for(ll i=2;i<=n;i++){
        debug(i);
        swap(v[2],v[i]);
        if(check()){
            ans1 = true;
            break;
        }else{
            swap(v[2],v[i]);
        }
    }
    if(ans1){
        cout<<"YES"<<endl;
        return;
    }

    swap(v[1],v[2]);
    
    for(ll i=2;i<=n;i++){
        debug("next");
        debug(i);
        swap(v[2],v[i]);
        if(check()){
            ans2 = true;
            break;
        }else{
            swap(v[2],v[i]);
        }
    }
    if(ans2){
        cout<<"YES"<<endl;
        return;
    }else{
        cout<<"NO"<<endl;
        return;
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