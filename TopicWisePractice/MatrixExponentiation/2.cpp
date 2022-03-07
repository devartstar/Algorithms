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
#define fill(m,v) memset(m,v,sizeof(m));
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n,m;
int i,j,k,l;
int g[303][303];
int a[303][303], r[303][303], t[303][303];
int inf;

void mul(int a[303][303], int b[303][303]){
	fill(t,195);
	int i,j,k;
	for(i=0;i<n;++i)
	for(j=0;j<n;++j){
		for(k=0;k<n;++k) t[i][j] = max(t[i][j], a[i][k]+b[k][j]);
	}
	memcpy(a,t,sizeof(t));
}

void pow(int b){
	memcpy(a,g,sizeof(g));
	fill(r,195);
	for(int i=0;i<n;++i) r[i][i] = 0;
	while(b){
		if(b&1) mul(r,a);
		mul(a,a);
		b>>=1;
	}
}

void solve() {
    cin>>n>>m;
	
	inf = 1e9;
	for(i=0;i<n;++i)
	for(j=0;j<n;++j) if(i!=j) g[i][j] = -inf;
	
	for(k=0;k<m;++k){
		cin>>i>>j;
		--i; --j;
		cin>>g[i][j]>>g[j][i];
	}
	
	
	int kl, kr, k;
	kl = 2; kr = n+10;
	
	int ans = 0;
	while(kl<kr){
		k = (kl+kr)>>1;
		
		pow(k);
		
		
		for(i=0;i<n;++i) if(r[i][i]>0) break;
		
		if(i==n) kl=k+1; else{
			ans = k;
			kr = k;
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
    //cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}