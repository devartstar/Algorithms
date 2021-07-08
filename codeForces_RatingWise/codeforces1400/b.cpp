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

void solve(){
    int n,m;
    cin>>n>>m;
    vi v(n);
    f0(i,n){
        cin>>v[i];
    }

    int ele = v[n-1];
    vi res;
    vi query[n+1];

    f0(i,m){
        int a,b;
        cin>>a>>b;
        if(b==ele)  res.pb(a);
        query[a].pb(b);
    }

    f0(i,n+1){
        debug(query[i]);
    }

    int end = n-1;
    int c=0;
    for(int i=n-2;i>=0;i--){
        if(find(all(res),v[i])!=res.end()){
            debug(v[i]);
            bool isPresent = true;
            for(int j = i+1; j<=n-1 ;j++){
                if(find(all(query[v[i]]),v[j])==query[v[i]].end()){
                    isPresent=false;
                    break;
                }
            }
            if(isPresent==false){
                break;
            }else{
                c++;
                v[i]=ele;
            }
        }
    }
    cout<<c<<endl;
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

/*
void solve() {
    int n,m;
    cin>>n>>m;
    vpii v(n+1);
    f1(i,n){
        cin>>v[i].ss;
        v[i].ff = i+1;
    } 
    vi query[n+1];
    f0(i,m){
        int a,b;
        cin>>a>>b;
        query[b].pb(a);
        query[a].pb(b);
    }
    // v[n] -> elememnt to be considered
    // v[n-1] -> element always be its next neighbour
    // start dfs from 
}
*/