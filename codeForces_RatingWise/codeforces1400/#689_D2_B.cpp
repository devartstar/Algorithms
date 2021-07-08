/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-06-28 07:51:44 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/problemset/problem/1461/B
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

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


void solve() {
    int n,m;
    cin>>n>>m;
    vector<string> arr(n);
    pair<int,int> dp[n][m];
    f0(i,n){
        cin>>arr[i];
        f0(j,m){
            dp[i][j]=mp(0,0);
            // if(arr[i][j]=='*')
            //     dp[i][j]=mp(1,1);
            // else
            //     dp[i][j]=mp(0,0);
        }
    }
    /* ---- 
    f0(i,n){
        f0(j,m)
            cout<<dp[i][j].ff<<","<<dp[i][j].ss<<" | ";
        cout<<endl;
    }
     ---- */
    f0(i,n){
        f0(j,m){
            if(arr[i][j]!='*')
                continue;
            int temp;
            if(i>0){
                if(arr[i-1][j]=='*')
                    temp = dp[i-1][j].ss+2;
                else
                    temp=1;
            }else{
                temp=1;
            }
            int c=1;
            int left=j-1;
            int right=j+1;
            debug(i);
            debug(j);
            while(1){
                if(left<0 || right>=m)
                    break;
                if(arr[i][left]=='*' && arr[i][right]=='*'){
                    c+=2;
                    left--;
                    right++;
                }else{
                    break;
                }
            }
            debug(c);
            if(c%2==0)  c--;
            
            if(c>=temp){
                dp[i][j].ff = (i>0?dp[i-1][j].ff:0)+1;
                dp[i][j].ss = temp;
            }else{
                dp[i][j].ff =  (c+1)/2;
                dp[i][j].ss = c;
            }
        }
    }
    /* ---- 
    f0(i,n){
        f0(j,m)
            cout<<dp[i][j].ff<<","<<dp[i][j].ss<<" | ";
        cout<<endl;
    }
     ---- */
    ll sum=0;
    f0(i,n){
        f0(j,m){
            sum+=dp[i][j].ff;
        }
    }
    cout<<sum<<endl;
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