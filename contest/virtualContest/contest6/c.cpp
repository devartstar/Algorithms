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

ll dp[5001][5001];

void solve() {
    ll n;
    cin>>n;
    vll v(n+1);
    f1(i,n) cin>>v[i];
    
    f0(i,n+1){
        f0(j,n+1){
            dp[i][j] = 300*5001;
        }
    }
    dp[0][0]=0;

    
    f(i,1,n){
        f(j,0,n){
            dp[i][j] = dp[i-1][j+1];
            if(v[i]>100 && j>0){
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+v[i]);
            }else{
                dp[i][j] = min(dp[i][j], dp[i-1][j]+v[i]);
            }
        }
    }

    cout<<dp[n][0]<<endl;
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












/*
ll dis=0;
    int x,y,p,q;
    while(!a.empty()){
        x=a[0];
        if((int)a.size()>1)
            y=a[(int)a.size()-1];
        else
            y=0;
        
        if((int)b.size()==0){
            break;
        }
        if((int)b.size()==1){
            p=b[0];
            q=0;
        }else{
            p=b[0];
            q=b[1];
        }

        if(p+q>=y){
            // take 'y' for free;
            dis+=(p+q);
            if((int)b.size()>1){
                b.erase(b.begin());
                b.erase(b.begin());
            }else{
                b.erase(b.begin());
            }
            
            if((int)a.size()>1){
                a.pop_back();
                a.erase(a.begin());
            }else{
                a.erase(a.begin());
            }

        }else{
            dis+=y;
            if((int)a.size()>1){
                a.pop_back();
                a.erase(a.begin());
            }else{
                a.erase(a.begin());
            }
        }

    }
    
    */