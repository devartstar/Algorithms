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
    vector<pll> v(n);
    vector<pll> v1; 
    vll result(n+1);

    fll0(i,n){
        cin>>v[i].first;
        v[i].second=i+1;
        result[i]=0;
        if(v[i].first!=0)
            v1.pb(make_pair(v[i].second-v[i].first+1, v[i].second));
    }
    

    int len = (int)v1.size();
    if(len==0){
        fll0(i,n) cout<<result[i]<<" ";
        cout<<"\n";
        return;
    }else{
        sort(all(v1));
    }
    stack<pll> s;
    s.push(v1[0]);
    fll1(i,len-1){
        pll k = s.top();
        if(v1[i].first<=k.second && v1[i].second>k.second){
            s.pop();
            s.push(make_pair(k.first,v1[i].second));
        }else{
            s.push(v1[i]);
        }
    }
    while(!s.empty()){
        pii k = s.top();
        s.pop();
        if(k.first<=0)  k.first=0;
        if(k.second>n)  k.second=n;
        f(i,k.first,k.second)   result[i]=1;
    }
    f1(i,n) cout<<result[i]<<" ";
    cout<<"\n";
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