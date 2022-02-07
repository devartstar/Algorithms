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

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n,m;
    cin>>n>>m;
    vpii v(n);
    vpii s(m);
    f0(i,n){
        cin>>v[i].ff>>v[i].ss;
    }
    f0(i,m){
        cin>>s[i].ff>>s[i].ss;
    }
    vpii ans;
    for(pii x : v){
        for(pii y : s){
            if(x.ff <= y.ff && x.ss <= y.ss){
                ans.pb(mp(y.ff-x.ff, y.ss-x.ss));
            }
        }
    }
    if(ans.size() == 0){
        cout<<0<<endl;
        return;
    }
    sort(ans.rbegin(), ans.rend());
    debug(ans);
    int fin_ans = INF;
    int big = -1;
    for(pii x : ans){
        fin_ans = min(fin_ans, x.ff + 1 + big + 1);
        big = max(big, x.ss);
    }
    fin_ans = min(fin_ans, big+1);
    cout<<fin_ans<<endl;
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


/*


    vpii ans(n);

    auto comp = [](auto a, auto b){
        if(a.ff > b.ff) return true;
        else if(a.ff == b.ff){
            if(a.ss > b.ss) return true;
            else    return false;
        }else{
            return false;
        }
    };
    sort(all(s), comp);
    vpii temp = s;
    f0(i,m-1){
        if(temp[i].ss > temp[i+1].ss)   temp[i+1].ss = temp[i].ss;
    }
    debug(temp);
    // clac ans[i].ss
    sort(all(v));
    int k = m-1;
    f0(i,n){
        while(v[i].ff > temp[k].ff){
            if(k==0)    break;
            k--;
            if(k==0)    break;
        }
        if(k==0 && v[i].ff > temp[k].ff){
            ans[i].ss = 0;
            continue;
        }
        ans[i].ss = max(0, temp[k].ss + 1 - v[i].ss);
    }
    debug(ans);

    auto comp1 = [](auto a, auto b){
        return a.ss < b.ss;
    };
    sort(all(v), comp1);
    debug(v);
    int ind = 0;
    f0(i,n){
        while(v[i].ss > temp[ind].ss){
            if(ind >= m-1)  break;
            ind++;
            if(ind >= m-1)  break;
        }
        if(k==m-1 && v[i].ss > temp[ind].ss){
            ans[i].ff = 0;
            continue;
        }
        ans[i].ff = max(0, temp[ind].ff - v[i].ff);
    }
    debug(ans);
    */