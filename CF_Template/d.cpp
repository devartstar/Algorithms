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
    ll maxcost=0, a=0,b=0,c=0;
};

void solve() {
    ll n, m;
    cin>>n>>m;
    vll weight1;
    vll weight2;
    vll weight3;
    f1(i,n){
        ll wt, cost;
        cin>>wt>>cost;
        if(wt==1)   weight1.pb(cost);
        if(wt==2)   weight2.pb(cost);
        if(wt==3)   weight3.pb(cost);
    }
    weight1.pb(INF);
    weight2.pb(INF);
    weight3.pb(INF);
    sort(all(weight1), greater<ll>());
    sort(all(weight2), greater<ll>());
    sort(all(weight3), greater<ll>());

    vector<str> dp(m+1);
    f1(curr_wt,m){
        if(curr_wt-1>=0){
            if(dp[curr_wt-1].a+1<(ll)weight1.size() && dp[curr_wt-1].maxcost + weight1[dp[curr_wt-1].a + 1] > dp[curr_wt].maxcost){
                dp[curr_wt].a = dp[curr_wt-1].a + 1;
                dp[curr_wt].b = dp[curr_wt-1].b;
                dp[curr_wt].c = dp[curr_wt-1].c;
                dp[curr_wt].maxcost = dp[curr_wt-1].maxcost + weight1[dp[curr_wt].a];
            }
        }
        if(curr_wt-2>=0){
            if(dp[curr_wt-2].b+1<(ll)weight2.size() && dp[curr_wt-2].maxcost + weight2[dp[curr_wt-2].b + 1] > dp[curr_wt].maxcost){
                dp[curr_wt].a = dp[curr_wt-2].a;
                dp[curr_wt].b = dp[curr_wt-2].b + 1;
                dp[curr_wt].c = dp[curr_wt-2].c;
                dp[curr_wt].maxcost = dp[curr_wt-2].maxcost + weight2[dp[curr_wt].b];
            }
        }
        if(curr_wt-3>=0){
            if(dp[curr_wt-3].c+1<(ll)weight3.size() && dp[curr_wt-3].maxcost + weight3[dp[curr_wt-3].c + 1] > dp[curr_wt].maxcost){
                dp[curr_wt].a = dp[curr_wt-3].a;
                dp[curr_wt].b = dp[curr_wt-3].b;
                dp[curr_wt].c = dp[curr_wt-3].c + 1;
                dp[curr_wt].maxcost = dp[curr_wt-3].maxcost + weight3[dp[curr_wt].c];
            }

        }
        f1(i,m){
            cout<<dp[i].maxcost<<" ";
        }
        cout<<endl;
    }
    ll ans = -INF;
    f1(i,m){
        ans = max(ans, dp[i].maxcost);
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
    //cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}