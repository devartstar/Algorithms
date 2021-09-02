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

vector<int> v[200005];
vector<int> v1[200005];
vi mn(200005);

void solve() {
    int n,m;
    cin>>n>>m;
    f1(i,n) mn[i] = INF;
    f0(i,m){
        int x,y;
        cin>>x>>y;
        if(y<mn[x]) mn[x]=y;
        if(x<mn[y]) mn[y]=x;
        v[x].pb(y);
        v[y].pb(x);
    }
    f1(i,n){
        debug(v[i]);
        debug(mn[i]);
    }
    int q;
    cin>>q;
    while(q--){
        debug(q);
        int k;
        cin>>k;
        if(k==3){
            debug("lol3");
            int ans = 0;
            vi mn1(n+1);
            f1(i,n){
                v1[i] = v[i];
                mn1[i] = mn[i];
            }
            f1(i,n){
                debug(v1[i]);
                debug(mn1[i]);
            }
            for(int i=1; i<=n; i++){
                if((int)v[i].size()>0){
                    int temp = mn1[i];
                    debug(i);
                    debug(mn1[i]);
                    if(temp>i){
                        ans ++;
                        for(int j =i+1; j<=n; j++){
                            if(i==mn1[j]){
                                auto ele = upper_bound(all(v[j]),i);
                                if( ele-v[j].begin() == (int)v[j].size()){
                                    mn1[j] = -1;
                                }else{
                                     mn1[j] = *ele;
                                }
                            }
                        }
                    }
                }
            }
            //  f1(i,n){
            //     debug(v1[i]);
            // }
            cout<<ans<<endl;
        }
        if(k==1){
            debug("lol1");
            int a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
            if(a<mn[b]) mn[b] = a;
            if(b<mn[a]) mn[a] = b;
        }
        if(k==2){
            debug("lol2");
            int a,b;
            cin>>a>>b;
            v[a].erase(find(all(v[a]),b));
            v[b].erase(find(all(v[b]),a));
            if(a==mn[b]){
                auto ele = upper_bound(all(v[b]),a);
                if( ele-v[b].begin() == (int)v[b].size()){
                    mn[b] = -1;
                }else{
                    mn[b] = *ele;
                }
            }
            if(b==mn[a]){
                auto ele = upper_bound(all(v[a]),b);
                if( ele-v[a].begin() == (int)v[a].size()){
                    mn[a] = -1;
                }else{
                    mn[a] = *ele;
                }
            }
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