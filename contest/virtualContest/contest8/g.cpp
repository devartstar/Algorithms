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

bool iSPalindrome(string s){
    int left = 0, right = (int)s.length()-1;
    while (left<=right) 
    {
        if(s[left]==s[right]){
            left++;
            right--;
        }else{
            return false;
        }
    }
    return true;
}

void solve() {
    string s;
    cin>>s;
    int n = (int)s.length();
    int ans=-1;
    string s1;
    string res;
    f0(i,n){
        s1 = s.substr(0,i+1);
        if(iSPalindrome(s1)){
            //cout<<"lol 1 "<<s1<<endl;
            if(i+1>ans){
                res=s1;
                ans=i+1;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        s1=s.substr(i);
        if(iSPalindrome(s1)){
            //cout<<"lol 2 "<<s1<<endl;
            if((int)s1.length()>ans){
                ans=(int)s1.length();
                res=s1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            s1 = s.substr(0,i+1)+s.substr(j);
            if(iSPalindrome(s1)){
                //cout<<"lol 3 "<<s1<<endl;
                if((int)s1.length()>ans){
                    res=s1;
                    ans=(int)s1.length();
                }
            }
        }
    }
    cout<<res<<endl;
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