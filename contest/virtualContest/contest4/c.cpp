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
    int x;
    cin>>x;
    vi v(10);
    v[1]=9;
    f(i,2,9){
        v[i]=v[i-1]+(10-i);
    }
    // f(i,1,9){
    //     cout<<v[i]<<" ";
    // }
    cout<<endl;
    if(x<=9){
        cout<<x<<endl;
        return;
    }
    int ans;
    f(i,2,9){
        if(x>v[i-1] && x<=v[i]){
            
            // there are i digits
            //(x-v[i-1]) + (10-i) --- upto i=1 
            ans = x-v[i-1];
            x=x-ans;
            //cout<<i<<" "<<ans<<"\n";
            while(i>=1){
                i--;
                int val = 10-i;
                x=x-val;
                ans=ans*10 + val; 
                if(x==0)    break;
            }
        }
    }
    if(x==0)
        cout<<ans<<endl;
    else{
        cout<<-1<<endl;
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