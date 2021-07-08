/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-06-23 21:49:51 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/problemset/problem/1443/B
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
    int n,a,b,i1,i2;
    string s;
    cin>>a>>b>>s;
    if(s.find("1")!=string::npos){
        i1 = s.find("1");
        i2 = s.rfind("1");
    }else{
        cout<<0<<endl;
        return;
    }
    string s1 = s.substr(i1,i2-i1+1);
    n = (int)s1.length();
    int dp[n][2];
    dp[0][0]=INF;
    dp[0][1]=a;
    for(int i=1;i<n;i++){
        if(s1[i]=='0'){
            if(s1[i-1]=='0'){
                dp[i][1]=dp[i-1][1]+b;
                dp[i][0]=dp[i-1][0];
            }
            if(s1[i-1]=='1'){
                dp[i][0]=dp[i-1][1];
                dp[i][1]=dp[i-1][1]+b;
            }
        }
        if(s1[i]=='1'){
            dp[i][1]=min(dp[i-1][1],dp[i-1][0]+a);
            dp[i][0]=INF;
        }
    }
    cout<<dp[n-1][1]<<endl;
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