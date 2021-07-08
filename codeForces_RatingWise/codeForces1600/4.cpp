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
    ll n;
    cin>>n;
    vll v(2*n);
    vll v1(2*n);
    fll0(i,n){
        cin>>v[i];
        v[n+i]=v[i];
        if(i==0)    v1[i]=v[i];
        else        v1[i]=v1[i-1]+v[i];
    }
    fll0(i,n){
        v1[n+i]=v1[i];
    }

    // f0(i,n) cout<<v1[i]<<" ";
    // cout<<endl;

    ll s,f;
    cin>>s>>f;

    if(f<s){
        f=n+f;   
    }
    ll dif = f-s;
    ll mx = v1[dif-1];
    ll pos=0;
    ll start;
    for(start=1;start<n;start++){
        ll end = start+dif-1;
        //cout<<start<<" - "<<endl;
        ll val;
        if(end>=n){
            val = v1[end]+v1[n-1]-v1[start-1];
        }
        else    val = v1[end]-v1[start-1];
        //cout<<val<<endl;
        if(val>mx){
            //cout<<"lol "<<start<<endl;
            mx=val;
            pos=start;
        }
    }
    pos++;
    //cout<<pos<<endl;
    ll ans;
    if(s>=pos){
        ans = s-pos+1;
    }else{
        ans=n-pos+1+s;
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    ll tc = 1;
    //cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}