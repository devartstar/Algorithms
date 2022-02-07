/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-10-05 23:50:26 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/problemset/problem/1579/C
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

int n,m,k;
char arr[100][100];
char arr1[100][100];

bool checkValidTick(int i, int j){
    for(int z=1; z<=k; z++){
        if(i-z<0 || j+z>=m || j-z<0){
            return false;
        }else{
            if(arr[i-z][j+z] != '*' || arr[i-z][j-z] != '*'){
                return false;
            }
        }
    }
    
    for(int z=0; z<=k; z++){
        arr1[i-z][j+z] = '*';
        arr1[i-z][j-z] = '*';
    }
    return true;
}

bool check(){
    f0(i,n){
        f0(j,m){
            if(arr[i][j] != arr1[i][j])
                return false;
        }
    }
    return true;
}

void solve() {
    cin>>n>>m>>k;
    f0(i,n){
        cin>>arr[i];
        f0(j,m){
            arr1[i][j] = '.';
        }
    }

    f0(i,n){
        f0(j,m){
            bool ok = false;
            if(arr[i][j] == '*'){
                ok = checkValidTick(i, j);
            }
            if(ok){
                int z = k+1;
                while(1){
                    if(i-z<0 || j+z>=m || j-z<0){
                        break;
                    }
                    if(arr[i-z][j-z] == '*' && arr[i-z][j+z] == '*'){
                        arr1[i-z][j+z] = '*';
                        arr1[i-z][j-z] = '*';
                    }else{
                        break;
                    }
                    z++;
                }
            }
        }
    }
    if(check()){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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