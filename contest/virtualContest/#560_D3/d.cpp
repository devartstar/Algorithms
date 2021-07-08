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

int isPrime(ll n){
    if (n <= 3)
        return -1;
  
    if (n % 2 == 0)
        return 2;
    if(n%3==0)
        return 3;
  
    for (int i = 5; i * i <= n; i = i + 6){
        if (n % i == 0 )
            return i;
        if(n % (i + 2) == 0)
            return (i+2);
    }
  
    return -1;
}

void solve() {
    ll n;
    cin>>n;
    vll v(n);
    fll0(i,n) cin>>v[i];
    ll ans=1;
    fll0(i,n){
        ans=(ans*v[i])/__gcd(ans,v[i]);
    }

    fll0(i,n){
        if(v[i]==ans){
            int l = isPrime(ans);
            if(l==-1){
                ans=ans*ans;
                cout<<ans<<"\n";
                return;
            }
            else                
                ans=ans*l;
            break;
        }
    }


    bool isInc = false;
    fll0(i,n){
        if(ans%v[i]==0){
            if(find(all(v),ans/v[i])==v.end()){
                isInc = true;
                break;
            }
        }
        else{
            isInc = true;
            break;
        }
    }

    if(isInc){
        cout<<-1<<"\n";
        return;
    }   


    f(i,2,(ll)sqrt(ans)){
        if(ans%i==0){
            if(find(all(v),i)==v.end()){
                isInc=true;
            }
        }
    }

    if(isInc){
        cout<<-1<<"\n";
        return;
    }   

    cout<<ans<<"\n";
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



/*

    2
    4 2
    lcm = 4

    999966000289



    2
    3 9

    LCM = 9
*/