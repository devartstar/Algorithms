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
const int maxN = 10;
vi level(MAX_N);
int lca[MAX_N][maxN+1];

void dfs(int node, int lev, int parent){
	level[node] = lev;
	lca[node][0] = parent;
	for(int child : v[node]){
		if(child==parent)   continue;
		dfs(child, level[node]+1, node);
	}
}

void sparseTable(int n){
	dfs(1,0,-1);
	f1(j,maxN){
		f1(i,n){
			if(lca[i][j-1]!=-1){
				lca[i][j] = lca[lca[i][j-1]][j-1];
			}
		}
	}
}

int get_lca(int a, int b){
	if(level[a]>level[b])   swap(a,b);
	int diff = level[b]-level[a];
	while(diff>0){
		int temp = log2(diff);
		b = lca[b][temp];
		diff -= (1<<temp);
	}
	if(a==b)
		return a;
	for(int i=maxN; i>=0; i--){
		if(lca[a][i]!=-1 && lca[a][i]!=lca[b][i]){
			a=lca[a][i];
			b=lca[b][i];
		}
	}
	return lca[a][0];
}

void solve() {
    int n,a,b,q;
    cin>>n;
    f0(i,n-1){
        int a,b;    cin>>a>>b;
        v[a].pb(b); v[b].pb(a);
    }

    f1(i,n){
        f0(j,maxN){
            lca[i][j] = -1;
        }
    }

    sparseTable(n);

    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        int node = get_lca(a,b);
        cout<<node<<endl;
		// to get the distance between Node A and Node B
		// level[A] + level[B] - level[get_lca(A,B)]
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