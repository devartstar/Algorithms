/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-08-07 19:56:00 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/gym/339535/problem/D
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


void solve() {
    int r, c;
    cin>>r>>c;
    char arr[r][c];
    bool ok = false, ok1 = false;
    string ans1 = string(c, 'A'); 
    string ans2 = string(r, 'A'); 
    vector<string> v(c,"");
    ll cnt = 0;
    f0(i,r){
        string s;
        cin>>s;
        if(s==ans1) ok1 = true;
        f0(j,c){
            arr[i][j] = s[j];
            v[j] += s[j];
            if(s[j]=='A'){
                cnt++;
            }
        }
    }
    for(string str : v){
        if(str == ans2) ok1 = true;
    }
    if(cnt==0){
        cout<<"MORTAL"<<endl;
        return;
    }
    string s1,s2,s3,s4;
    s1 = s2 = s3 = s4 = "";
    ok = false;
    f0(i,c){
        if(arr[0][i]=='A' || arr[r-1][i]=='A')  ok = true;
        s1 += arr[0][i];
        s2 += arr[r-1][i];
    }
    f0(i,r){
        if(arr[i][0]=='A' || arr[i][c-1]=='A')  ok = true;
        s3 += arr[i][0];
        s4 += arr[i][c-1];

    }
    if(cnt == r*c){
        cout<<0<<endl;
        return;
    }
    if(s1==ans1 || s2==ans1 || s3==ans2 || s4==ans2 ){
        cout<<1<<endl;
        return;
    }
    if(arr[0][0]=='A' || arr[0][c-1]=='A' || arr[r-1][0]=='A' || arr[r-1][c-1]=='A' || ok1){
        cout<<2<<endl;
        return;
    }
    if(ok){
        cout<<3<<endl;
        return;
    }
    cout<<4<<endl;
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