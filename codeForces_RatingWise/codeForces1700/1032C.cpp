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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ar array
#define ll long long
#define ull unsigned long long
#define lld long double
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<long long, long long>>
#define vb vector<bool>
#define all(v) v.begin(),v.end()
#define f0(i, n) for (int i = 0; i < n; i++) // 0 based indexing
#define f0r(i, n) for (int i = n-1; i >= 0; i--)
#define f1(i, n) for (int i = 1; i <= n; i++) // 1 based indexing
#define f1r(i, n) for (int i = n; i >= 1; i--)
#define f(i, a, b) for (int i = a; i <= b; i++) // 1 based indexing
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define fll0(i, n) for (long long i = 0; i < n; i++) // 0 based indexing
#define fll1(i, n) for (long long i = 1; i <= n; i++) // 1 based indexing
#define fll(i, a, b) for (long long i = a; i <= b; i++) // 1 based indexing
#define disp(v) for(auto x : v) cout<<x<<" "; cout<<endl;
#define disp0(v, n) for(int i = 0; i < n; i++) cout<<v[i]<<" "; cout<<endl;
#define disp0r(v, n) for(int i = n-1; i >= 0; i--) cout<<v[i]<<" "; cout<<endl;
#define disp1(v, n) for(int i = 1; i <= n; i++) cout<<v[i]<<" "; cout<<endl;
#define disp1r(v, n) for(int i = n; i >= 1; i--) cout<<v[i]<<" "; cout<<endl;
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define sz(v) (int)v.size()
#define len(v) (int)v.length()

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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    f1(i, n) cin >> v[i];
    vector<vector<int>> dp(n + 1, vector<int>(6, -1));
    vector<vector<int>> prev(n + 1, vector<int>(6, 0));
    f0(curr_finger, 6) dp[1][curr_finger] = 1;
    for (int i = 2; i <= n; i++) {
        for (int curr_finger = 1; curr_finger <= 5; curr_finger++){
            if(v[i] > v[i-1]) {
                // curr_finger > prev_finger
                for (int prev_finger = 1; prev_finger < curr_finger; prev_finger++) {
                    if(dp[i-1][prev_finger] != -1) {
                        dp[i][curr_finger] = 1;
                        prev[i][curr_finger] = prev_finger;
                        break;
                    }
                }
            }
            if(v[i] < v[i-1]) {
                // curr_finger < prev_finger
                for (int prev_finger = curr_finger + 1; prev_finger <= 5; prev_finger++) {
                    if(dp[i-1][prev_finger] != -1) {
                        dp[i][curr_finger] = 1;
                        prev[i][curr_finger] = prev_finger;
                        break;
                    }
                }
            }
            if(v[i] == v[i-1]) {
                // curr_finger != prev_finger
                for (int prev_finger = 1; prev_finger <= 5; prev_finger++) {
                    if(prev_finger == curr_finger) continue;
                    if(dp[i-1][prev_finger] != -1) {
                        dp[i][curr_finger] = 1;
                        prev[i][curr_finger] = prev_finger;
                        break;
                    }
                }
            }
        }
    }
    int temp = -1;
    vector<int> ans;
    for (int finger = 1; finger <= 5; finger++) {
        if(dp[n][finger] != -1) {
            temp = finger;
            break;
        }
    }
    if(temp == -1) {
        cout << temp << endl;
        return;
    }
    for (int i = n; i >= 1; i--) {
        ans.pb(temp);
        temp = prev[i][temp];
    }
    reverse(all(ans));
    for(int x : ans) {
        cout << x << " ";
    }
    cout << endl;
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
