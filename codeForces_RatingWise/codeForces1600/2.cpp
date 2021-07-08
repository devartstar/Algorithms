/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-06-21 16:26:36 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/contest/538/problem/C
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


//  O(N)
void solve() {
    int n,m;
    cin>>n>>m;
    vpii v(m);
    f0(i,m)
        cin>>v[i].first>>v[i].second;
    int mx=-1;
    bool ans=true;
    f0(i,m-1){
        int a = v[i].first;
        int b = v[i+1].first;
        int c = v[i].second;
        int d = v[i+1].second;
        if(c>=d-abs(b-a) && c<=d+abs(b-a) && d<=c+abs(b-a) && d>=c-abs(b-a)){
            int temp=-1,h1,h2;
            // or maybe run binary
            f(j,a,b){
                h1 = v[i].second + abs(j-a);
                h2 = v[i+1].second + abs(j-b);
                temp = max(temp,min(h1,h2));

            }
            mx=max(mx,temp);
        }else{
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    int ih1 = abs(v[0].first-1) + v[0].second;
    int ih2 = abs(n-v[m-1].first) + v[m-1].second;

    mx=max(mx,max(ih1,ih2));
    cout<<mx<<endl;
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