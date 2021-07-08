/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-06-24 18:41:19 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/contest/675/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
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
#define fi first
#define se second

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


void solve() {
    ll n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    ll l1,l2,l3;
    l1=n+(c+d)-(a+b);
    l2=n+c-b;
    l3=n+d-a;

    ll m1,m2,m3;
    m1=1+(c+d)-(a+b);
    m2=1+c-b;
    m3=1+d-a;
    // cout<<l1<<" "<<l2<<" "<<l3<<" "<<m1<<" "<<m2<<" "<<m3<<endl;
    ll x1 = min(l1,min(l2,l3));
    ll x2 = max(m1,max(m2,m3));
    int k=0;
    for(int i=x2;i<=x1;i++){
        if(i>=1 && i<=n) k++;
    }
    // cout<<x1<<" "<<x2<<endl;
    cout<<max(k*n,0ll)<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    //cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}