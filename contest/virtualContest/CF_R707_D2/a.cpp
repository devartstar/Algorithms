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
    int n;
    cin>>n;
    vpii t(n);
    vi tdiff(n);
    f0(i,n){
        cin>>t[i].first>>t[i].second;
        tdiff[i]=t[i].second-t[i].first;
    } 
    vi dist(n);
    f0(i,n)
        if(i==0)    dist[i]=t[i].first;
        else        dist[i]=t[i].first-t[i-1].second;
    
    vi td(n);
    f0(i,n) cin>>td[i];
    /* printing
    f0(i,n) cout<<t[i].first<<" "<<t[i].second<<" | ";
    cout<<"\n";
    f0(i,n) cout<<td[i]<<" ";
    cout<<"\n";
    f0(i,n) cout<<dist[i]<<" ";
    cout<<"\n";
    f0(i,n) cout<<tdiff[i]<<" ";
    cout<<"\n";
    -end- */
    t[0].first = dist[0] + td[0];
    t[0].second = max(t[0].second, t[0].first + (int)ceil(tdiff[0]*1.0/2));
    f(i,1,n-1){
        t[i].first = t[i-1].second + dist[i] + td[i];
        t[i].second = max(t[i].second, t[i].first + (int)ceil(tdiff[i]*1.0/2));
    }
    /*  finally 
     f0(i,n) cout<<t[i].first<<" "<<t[i].second<<" | ";
    cout<<"\n";
    -end- */
    cout<<t[n-1].first<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}