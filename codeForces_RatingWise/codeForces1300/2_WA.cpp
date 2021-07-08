/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-06-21 09:18:32 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/problemset/problem/1493/B
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

int ston(string s){
    int ans = 0;
    f0(i,(int)s.length())   ans=ans*10+(s[i]-'0');
    return ans;
}


void solve() {
    int x,y;
    cin>>x>>y;
    string h = 

    char rev[] = {'0','1','5','a','a','2','a','a','8','a'};

    string s;
    cin>>s;
    reverse(all(s));
    string hr = s.substr(0,2);
    string min = s.substr(2,2);

    //  IDEA -> find the min then the Hour

    if(rev[min[0]]!='a'){
        if(rev[min[1]]=='a'){
            if(min[1]=='0' || )
        }
    }


    reverse(all(hr));
    reverse(all(min));
    int hrval = ston(hr);
    int minval = ston(min);


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