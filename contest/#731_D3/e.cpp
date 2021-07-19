/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-07-12 05:34:39 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/problemset/problem/1547/E
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
#define vpll vector<pair<int,int>>
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
    ll n,k;
    cin>>n>>k; 
    vpll temp(k);
    fll0(i,k) cin>>temp[i].ff,    temp[i].ff--;
    fll0(i,k) cin>>temp[i].ss;

    sort(all(temp));
    vpll ltemp(k);
    vpll rtemp(k);
    
    ltemp[k-1] = temp[k-1];
    for(ll i = k-2;i>=0;i--){
        ltemp[i].ss = min(temp[i].ss, abs(temp[i].ff-temp[i+1].ff)+ltemp[i+1].ss);
        ltemp[i].ff = temp[i].ff;
    }

    rtemp[0] = temp[0];
    for(ll i = 1;i<=k-1;i++){
        rtemp[i].ss = min(temp[i].ss, abs(temp[i].ff-temp[i-1].ff)+rtemp[i-1].ss);
        rtemp[i].ff = temp[i].ff;
    }

    debug(ltemp);
    debug(rtemp);

    vll ans(n);
    ll left  = 0;
    fll0(i,n){
        if(i==temp[left].ff){
            ans[i] = min(ltemp[left].ss, rtemp[left].ss);
            left++;
            continue;
        }
        if(i<temp[0].ff){
            ans[i] = ltemp[0].ss + abs(temp[0].ff - i);
            continue;
        }
        if(i>temp[k-1].ff){
            ans[i] = rtemp[k-1].ss + abs(temp[k-1].ff-i);
            continue;
        }
        if(left>0 && left<k){
            ans[i] = min(ltemp[left].ss+abs(temp[left].ff-i), rtemp[left-1].ss+abs(temp[left-1].ff-i));
            continue;
        }
    }
 

    for(ll x : ans)    cout<<x<<" ";
    cout<<endl;    
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



/*

   f0(i,n){
        int ind = upper_bound(all(pos), i) - pos.begin();
        int lpos = ind - 1;
        int rpos = ind;
        debug(i);   debug(lpos);    debug(rpos);
        if(lpos==i){
            ans[i] = min(ltemp[i],rtemp[i]);
            continue;
        }
        if(i<pos[0]){
            ans[i] = ltemp[0] + abs(pos[0] - i);
            continue;
        }
        if(i>pos[k-1]){
            ans[i] = rtemp[k-1] + abs(pos[k-1]-i);
            continue;
        }
        if(i>pos[0] && i<pos[k-1]){
            ans[i] = min(ltemp[rpos]+abs(rpos-i), rtemp[lpos]+abs(lpos-i));
            continue;
        }
    }
*/