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
    string s;
    cin>>s;
    int n = (int)s.length();
    s=" "+s;
    ll sum=0;
    vector<bool> used(n+1);
    
    f0(i,n+1)
        used[i]=false;
    
    for(int i=2;i<=n;i++){
        bool temp = false;
        if(s[i]==s[i-1] && !used[i-1]){
            temp=true;
        }
        if(n>2 && s[i]==s[i-2] && !used[i-2]){
            temp=true;
        }
        used[i]=temp;;
    }
    // f0(i,n+1)
    //     cout<<used[i]<<endl;
    f1(i,n+1)
        if(used[i])
            sum++;
    cout<<sum<<endl;
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