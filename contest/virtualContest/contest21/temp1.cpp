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


vi v[MAX_N];
map<pii, int> wt;
const int maxN = 10;
vi level(MAX_N);
pii lca[MAX_N][maxN+1];

void dfs(int node, int lev, int parent){
    level[node] = lev;
    lca[node][0] = mp(parent, wt[{node,parent}]);
    for(int child : v[node]){
        if(child==parent)   continue;
        dfs(child, level[node]+1, node);
    }
}

void sparseTable(int n){
    dfs(1,0,-1);
    f1(j,maxN){
        f1(i,n){
            if(lca[i][j-1].ff!=-1){
                // lca[i][j] stores the {2^j th parent of i, distance bw i and 2^j th parent of i}
                lca[i][j].ff = lca[lca[i][j-1].ff][j-1].ff;
                lca[i][j].ss = lca[i][j-1].ss + lca[lca[i][j-1].ff][j-1].ss;

                // to find the minimum edge length (over all edges) in path <i to its 2^j th parent>
                // lca[i][j].ss = min(lca[i][j-1].ss , lca[lca[i][j-1].ff][j-1].ss);
            
            }
        }
    }
}

int get_dist(int a, int b){
    int sum = 0; // sum stores the value to be answered
    if(level[a]>level[b])   swap(a,b);
    int diff = level[b]-level[a];
    while(diff>0){
        int temp = log2(diff);
        sum += lca[b][temp].ss;
        b = lca[b][temp].ff;
        diff -= (1<<temp);
    }
    if(a==b)
        return sum;
    for(int i=maxN; i>=0; i--){
        if(lca[a][i].ff!=-1 && lca[a][i].ff!=lca[b][i].ff){
            sum += (lca[a][i].ss + lca[b][i].ss);
            a=lca[a][i].ff;
            b=lca[b][i].ff;
        }
    }
    // since lca => parent of a/b || lca[a][0]/lca[b][0]
    sum += lca[a][0].ss + lca[b][0].ss;
    return sum;
}
/*
void solve() {
    int n,a,b,w,q;
    cin>>n;
    f0(i,n-1){
        cin>>a>>b>>w;
        v[a].pb(b); v[b].pb(a);
        wt[{a,b}] = wt[{b,a}] = w;
    }

    f1(i,n){
        f0(j,maxN+1){
            lca[i][j] = mp(-1,-1);
        }
    }

    sparseTable(n);
    f1(i,n){
        f0(j,maxN){
            cout<<lca[i][j].ff<<","<<lca[i][j].ss<<"  ||  ";
        }
        cout<<endl;
    }
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        int dist = get_dist(a,b);
        cout<<dist<<endl;
    }
}
*/

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