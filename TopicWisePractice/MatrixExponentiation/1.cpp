/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - ___________________ 	|	
    |    	                            |
    -------------------------------------

    Link - https://www.spoj.com/problems/FIBOSUM/
    Learning Resource - https://zobayer.blogspot.com/2010/11/matrix-exponentiation.html
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

struct Mat {
  ll n, m;
  vector<vector<ll>> a;
  Mat() { }
  Mat(ll _n, ll _m) {n = _n; m = _m; a.assign(n, vector<ll>(m, 0)); }
  Mat(vector< vector<ll> > v) { n = v.size(); m = n ? v[0].size() : 0; a = v; }
  inline void make_unit() {
    assert(n == m);
    for (ll i = 0; i < n; i++)  {
      for (ll j = 0; j < n; j++) a[i][j] = i == j;
    }
  }
  inline void display() {
    for (ll i = 0; i < n; i++)  {
      for (ll j = 0; j < m; j++) 
        cout<<a[i][j]<<" ";
      cout<<endl;  
    }
  }
  inline Mat operator + (const Mat &b) {
    assert(n == b.n && m == b.m);
    Mat ans = Mat(n, m);
    for(ll i = 0; i < n; i++) {
      for(ll j = 0; j < m; j++) {
        ans.a[i][j] = (a[i][j] + b.a[i][j]) % MOD;
      }
    }
    return ans;
  } 
  inline Mat operator - (const Mat &b) {
    assert(n == b.n && m == b.m);
    Mat ans = Mat(n, m);
    for(ll i = 0; i < n; i++) {
      for(ll j = 0; j < m; j++) {
        ans.a[i][j] = (a[i][j] - b.a[i][j] + MOD) % MOD;
      }
    }
    return ans;
  }
  inline Mat operator * (const Mat &b) {
    assert(m == b.n);
    Mat ans = Mat(n, b.m);
    for(ll i = 0; i < n; i++) {
      for(ll j = 0; j < b.m; j++) {
        for(ll k = 0; k < m; k++) {
          ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] % MOD) % MOD;
        }
      }
    }
    return ans;
  }
  inline Mat pow(long long k) {
    assert(n == m);
    Mat ans(n, n), t = a; ans.make_unit();
    while (k) {
      if (k & 1) ans = ans * t;
      t = t * t;
      k >>= 1;
    }
    return ans;
  }
  inline Mat& operator += (const Mat& b) { return *this = (*this) + b; }
  inline Mat& operator -= (const Mat& b) { return *this = (*this) - b; }
  inline Mat& operator *= (const Mat& b) { return *this = (*this) * b; }
  inline bool operator == (const Mat& b) { return a == b.a; }
  inline bool operator != (const Mat& b) { return a != b.a; }
};


Mat matexpo(Mat x, ll y){
    Mat ans(3,3), temp(3,3);
    ans.make_unit();
    temp = x;
    ll r = 1;
    while(r <= y){
        if(r&y){
            ans = ans * temp;
        }
        temp = temp * temp;
        r = r << 1;
    }
    return ans;
}

void solve() {
    ll n, m;    cin>>n>>m;
    Mat A(3,3);
    Mat B(3,1);
    A.a[0][0] = 0;A.a[0][1] = 1;A.a[0][2] = 0;A.a[1][0] = 1;A.a[1][1] = 1;A.a[1][2] = 0;A.a[2][0] = 0;A.a[2][1] = 1;A.a[2][2] = 1;
    B.a[0][0] = 0;B.a[1][0] = 1;B.a[2][0] = 0;

    Mat val1(3,3), val2(3,3);
    val1 = matexpo(A,n-1);
    val2 = matexpo(A,m);

    Mat ans1(3,1), ans2(3,1);
    ans1 = val1 * B;
    ans2 = val2 * B;

    cout<<(ans2.a[2][0] - ans1.a[2][0])<<endl;
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
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}