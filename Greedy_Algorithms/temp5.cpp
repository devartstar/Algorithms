/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-10-14 12:57:23 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/problemset/problem/1196/C
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
const ll INF = 1e5;
int NO = 1e9;



pii Intersection(pii a, pii b){
    // do interval intersection of x Cordinates
    pii ans;

    if(b.ff > a.ss || b.ss < a.ff){
        ans = mp(NO, NO);
    }else{
        if(b.ff >= a.ff && b.ss <= a.ss){
            ans = mp(b.ff, b.ss);
        }
        if(a.ff >= b.ff && a.ss <= b.ss){
            ans = mp(a.ff, a.ss);
        }
        if(b.ff >= a.ff && b.ff <= a.ss && b.ss >= a.ss){
            ans = mp(b.ff, a.ss);
        }
        if(b.ff <= a.ff && b.ss >= a.ff & b.ss <= a.ss){
            ans = mp(a.ff, b.ss);
        }
    }

    return ans;
}

void solve() {
    int n;
    cin>>n;
    int v[n][6];

    pii xRange = mp(-1*INF, INF);
    pii yRange = mp (-1*INF, INF);

    f0(i,n){
        f0(j,6) cin>>v[i][j];
    }

    // doing intersection at every popint
    pii temp;
    f0(i,n){
        if(v[i][2]==1 && v[i][4]==0){
            temp =  mp(-1*INF, v[i][0]);
            xRange = Intersection(temp, xRange);
        }else if(v[i][2]==0 && v[i][4]==1){
            temp =  mp(v[i][0], INF);
            xRange = Intersection(temp, xRange);
        }else if(v[i][2]==0 && v[i][4]==0){
            debug("lolx");
            temp = mp(v[i][0], v[i][0]);
            xRange = Intersection(temp, xRange);
        }

        if(v[i][3]==1 && v[i][5]==0){
            temp =  mp(v[i][1], INF);
            yRange = Intersection(temp, yRange);            
        }else if(v[i][3]==0 && v[i][5]==1){
            temp =  mp(-1*INF, v[i][1]);
            yRange = Intersection(temp, yRange);            
        }else if(v[i][3]==0 && v[i][5]==0){
            debug("loly");
            temp = mp(v[i][1], v[i][1]);
            yRange = Intersection(temp, yRange);            
        }



        debug(xRange);
        debug(yRange);
        if(xRange == mp(NO, NO) || yRange == mp(NO, NO)){
            cout<<"0"<<endl;
            return;
        }
    }
    if(xRange == mp(NO,NO) || yRange == mp(NO, NO)){
        cout<<"0"<<endl;
    }else{
        cout<<"1 "<<(xRange.ff + xRange.ss)/2<<" "<<(yRange.ff + yRange.ss)/2<<endl;
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
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}