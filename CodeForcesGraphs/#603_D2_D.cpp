/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-07-26 15:26:02 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/problemset/problem/1263/D
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

const int MAX_N = 200005;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vi graph[MAX_N];
vi visited(MAX_N);

void dfs(int node){
    visited[node] = 1;
    for(int child : graph[node]){
        if(!visited[child]){
            dfs(child);
        }
    }
}

void solve() {
    int n;
    cin>>n; 
    vi v[26];
    set<int> st;
    f1(i,n){
        string temp;
        cin>>temp;
        for(char ch : temp){
            st.insert(ch-'a');
            v[ch-'a'].pb(i);
        }
    }
    for(int i=0;i<26;i++){
        debug(v[i]);
    }
    f0(i,26){
        if((int)v[i].size()>0){
            int x = v[i][0];
            f1(j,(int)v[i].size()-1){
                graph[x].pb(v[i][j]);
                graph[v[i][j]].pb(x);
            }
        }
    }
    ll c=0;
    f1(i,n){
        debug(i);
        debug(graph[i]);
    }
    f1(i,n){
        if(!visited[i]){
            debug(i);
            c++;
            dfs(i);
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
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}



/*
char -> indices containing that character  in (10^6)
a -  1, 3, 6, 8
b -  2, 4, 6, 9
c -  1, 8
d -
e -
f -
. 
. 
. 
. 
. 
. 
x - 5, 7
y - 7, 10
z - 


1 - 3 - 6 - 8
        |
2 - 4 -- --9

5 -- 7 --10

*/