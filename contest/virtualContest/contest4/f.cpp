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

int ncr[200001][101];

void calc(){
    memset(ncr,0,sizeof(ncr));
    f0(i,200001)
        ncr[i][0]=1;
    for (int i = 1; i <= 200001; i++) {
        for (int j = min(i, 100); j > 0; j--)
            ncr[i][j] = (ncr[i-1][j]%MOD + ncr[i-1][j - 1]%MOD) %MOD;
    }
}




void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    vll v(n);
    fll0(i,n) cin>>v[i];
    sort(all(v));
    calc();
    ll sum=0;
    fll0(i,n){
        auto it = upper_bound(all(v), v[i]+k);
        ll ind;
        if(it == v.end())    ind = n-1;
        else                 ind = (it-v.begin())-1;
        ll val = ind -i;
        ll val1 = val<m-1 ? ncr[val][m-1] : 0;
        sum=(sum + val1)%MOD;
    }
    cout<<sum%MOD<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}







// ll comb(ll n,ll r)
// {
    
//     // The array C is going to store last row of
//     // pascal triangle at the end. And last entry
//     // of last row is nCr
//     ll C[r+1];
//     memset(C, 0, sizeof(C));
 
//     C[0] = 1; // Top row of Pascal Triangle
 
//     // One by constructs remaining rows of Pascal
//     // Triangle from top to bottom
//     for (ll i = 1; i <= n; i++)
//     {
//         // Fill entries of current row using previous
//         // row values
//         for (ll j = min(i, r); j > 0; j--)
 
//             // nCj = (n-1)Cj + (n-1)C(j-1);
//             C[j] = (C[j] + C[j-1])%MOD;
//     }
//     return C[r];
// }
 


// ll divide(ll a, ll b){
//     return a*(ll)pow(b,MOD-2)%MOD;
// }

// ll comb(ll n, ll r){
//     if(n<r) return 0;
//     ll a=1,b=1;
//     if(n-r<r)   r=n-r;
//     if(r!=0){
//         while(r){
//             a=a*n;
//             b=b*r;
//             ll g =__gcd(a,b);
//             a=divide(a,g);
//             b=divide(b,g);
//             n--;
//             r--;
//         }
//     }else{
//         a=1;
//     }
//     return a;
// }
