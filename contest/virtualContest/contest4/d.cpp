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
    vll v(n);
    vll v1(n);
    ll sum=0;
    ll max=-1;
    fll0(i,n){
        cin>>v[i];
        if(v[i]>max){
            max=v[i];
        }
        sum+=v[i];
    }
    vll cf(n);
    cf[0]=v[0];
    fll1(i,n-1){
        cf[i]=cf[i-1]+v[i];
    }

    for(ll i=0;i<n;i++){
        if(sum % (n-i) != 0)
            continue;
        ll val = sum/(n-i);
        if(max>val){
            continue;
        }
        ll temp=0;
        bool is = true;
        for(ll j=0;j<n;j++){
            if(temp+v[j]<=val){
                temp+=v[j];
            }else{
                if(temp == val){
                    temp=v[j];
                }else{
                    is = false;
                    break;
                }
            }
        }
        if(temp == val && is){
            cout<<i<<endl;
            return;
        }
    }
    
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




/*

int i=n;
    while(i>=1){
        // now there are i digits -> each value = n/i;
        if(sum%i!=0){
            i--;
            continue;
        }
        int val = sum/i;
        if(v1[n-1]>val){
            i--;
        }else{
            break;
        }
    }


    

    
    if(i==1){
        cout<<n-i<<endl;
        return;
    }


    */