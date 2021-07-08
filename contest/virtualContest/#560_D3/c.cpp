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
    int k;
    cin>>k;
    string s;
    cin>>s;
    s=" "+s;
    int j=1;
    while(j<(int)s.length()){
        //cout<<j<<" ";
        if(j%2==0){
            //cout<<"lol "<<s[j]<<" "<<s[j-1]<<"\n";
            if(s[j]==s[j-1]){
                s.erase(j,1);
                //cout<<j<<" "<<s<<"\n";
                continue;
            }
        }
        j++;
    }
    s.erase(0,1);
    if((int)s.length()%2==1){
        s.erase((int)s.length()-1,1);
    }
    cout<<k-(int)s.length()<<"\n";
    cout<<s<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}