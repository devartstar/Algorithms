/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - ___________________ 	|	
    |    	                            |
    -------------------------------------

    Link - https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff48/00000000003f47fb
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

int s, a1, b1, a2, b2, c;
int allowed[10][10];

// check if the neighbouring cell is in the bounds
inline bool check(int x, int y){
    if(x>=1 && y>=1 && x<=s && y<=2*x-1 && allowed[x][y]==0)
        return 1;
    else
        return 0;
}

int getBest(int r1, int p1, int r2, int p2){
    vpii move1, move2;
    if(check(r1, p1-1))
        move1.pb({r1,p1-1});
    if(check(r1, p1+1))
        move1.pb({r1,p1+1});
    if(p1&1){
        // can go down
        if(check(r1+1, p1+1))
            move1.pb({r1+1,p1+1});
    }else{
        // can go up
        if(check(r1-1, p1-1))
            move1.pb({r1-1,p1-1});
    }

    if(check(r2, p2-1))
        move2.pb({r2,p2-1});
    if(check(r2, p2+1))
        move2.pb({r2,p2+1});
    if(p2&1){
        // can go down
        if(check(r2+1, p2+1))
            move2.pb({r2+1,p2+1});
    }else{
        // can go up
        if(check(r2-1, p2-1))
            move2.pb({r2-1,p2-1});
    }

    if(move1.empty() && move2.empty()){
        return 0;
    }else if(!move1.empty()){
        int best = -1000;
        for(auto &x : move1){
            allowed[x.ff][x.ss] = 1;
            best = max(best, 1-getBest(r2,p2,x.ff,x.ss));
            allowed[x.ff][x.ss] = 0;
        }
        return best;
    }else{
        return -getBest(r2,p2,r1,p1);
    }
}

void solve(int t) {
    cin>>s>>a1>>b1>>a2>>b2>>c;
    memset(allowed, 0, sizeof(allowed));
    allowed[a1][b1] = allowed[a2][b2] = 1;
    // allowed 0 is empty
    // allowed 1 si not empty

    for(int i=0; i<c; i++){
        int x,y;
        cin>>x>>y;
        allowed[x][y] = 1;
    }
    cout<<"Case #"<<t<<": "<<getBest(a1,b1,a2,b2)<<endl;

}

int main() {
    int tc = 1;
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve(t);
    }
}