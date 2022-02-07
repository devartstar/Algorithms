/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-10-08 17:00:38 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/problemset/problem/1439/A1
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

vi arr[MAX_N];
int k=0;
vpii ans[MAX_N];

void two0two1(int x, int y){    // req 2 steps
    // (i j) (i+1 j) (i j+1) (i+1 j+1)
    int c1,c0;  c1 = c0 =0;
    f0(i,2){
        f0(j,2){
            if(arr[x+i][y+j] == 0 && c0 < 2){
                ans[k].pb(mp(x+i, y+j));
                arr[x+i][y+j] = 1;
                c0++;
                continue;
            }
            if(arr[x+i][y+j] == 1 && c1 < 1){
                ans[k].pb(mp(x+i, y+j));
                arr[x+i][y+j] = 0;
                c1++;
                continue;
            }
        }
    }
    k++;
    c1 = c0  = 0;
    f0(i,2){
        f0(j,2){
            if(arr[x+i][y+j] == 1 && c1 < 3){
                ans[k].pb(mp(x+i, y+j));
                arr[x+i][y+j] = 0;
                continue;
            }
        }
    }
    k++;
}

void three0one1(int x, int y){
    int c1,c0;
    c1 = c0  = 0;
    f0(i,2){
        f0(j,2){
            if(arr[x+i][y+j] == 1 && c1 < 1){
                ans[k].pb(mp(x+i, y+j));
                arr[x+i][y+j] = 0;
                c1++;
                continue;
            }
            if(arr[x+i][y+j] == 0 && c0 < 2){
                ans[k].pb(mp(x+i, y+j));
                arr[x+i][y+j] = 1;
                c0++;
                continue;
            }
        }
    }
    k++;
    two0two1(x,y);
}

void one0three1(int x, int y){
    int c1,c0;  c1 = c0 =0;
    f0(i,2){
        f0(j,2){
            if(arr[x+i][y+j] == 1 && c1 < 3){
                ans[k].pb(mp(x+i, y+j));
                arr[x+i][y+j] = 0;
                c1++;
                continue;
            }
        }
    }
    k++;
}

void check(int x, int y){
    int c=0;
    f0(i,2){
        f0(j,2){
            if(arr[x+i][y+j]==1)    c++;
        }
    }
    if(c==0)    return;
    else if(c==1)    three0one1(x,y);
    else if(c==2)    two0two1(x,y);
    else if(c==3)    one0three1(x,y);
    else if(c==4){
        ans[k].pb(mp(x,y));
        ans[k].pb(mp(x+1,y));
        ans[k].pb(mp(x,y+1));
        k++;
        arr[x][y] = arr[x+1][y] = arr[x][y+1] = 0;
        three0one1(x,y);
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    k=0;
    f0(i, 3*n*m+1){
        ans[i].clear();
        arr[i].clear();
    }
    f0(i,n){
        string s;   cin>>s;
        f0(j,m){
            arr[i].pb(s[j]-'0');
        }
    }
    for(int i=0; i<=(n-3); i++){
        for(int j=0; j<m-1; j+=2){
            if(j==m-1)  j--;
            int c = 0;
            if(arr[i][j] == 1)  ans[k].pb({i,j}), c++, arr[i][j] = 0;
            if(arr[i][j+1] == 1)  ans[k].pb({i,j}), c++, arr[i][j+1] = 0;
            if(c==0)    continue;
            if(c==1){
                ans[k].pb({i+1,j}); arr[i+1][j] = !arr[i+1][j];
                ans[k].pb({i+1,j+1});   arr[i+1][j+1] = !arr[i+1][j+1];
                k++;
                continue;
            }
            if(c==2){
                ans[k].pb({i+1,j}); arr[i+1][j] = !arr[i+1][j];
                k++;
                continue;
            }
        }
    }
    for(int j=0; j<m-1; j+=2){
        if(j==m-1)  j--;
        check(n-2, j);
    }
    f0(i,n){
        debug(arr[i]);
    }
    cout<<k<<endl;
    f0(i,k){
        f0(j,3)
            cout<<ans[i][j].ff+1<<" "<<ans[i][j].ss+1<<" ";
        cout<<endl;
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
        debug(t);
        solve();
    }
}