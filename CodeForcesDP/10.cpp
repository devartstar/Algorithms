/*
	Link - https://codeforces.com/gym/302977/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define f0(i, n) for (int i = 0; i < n; i++) // 0 based indexing
#define f1(i, n) for (int i = 1; i <= n; i++) // 1 based indexing
#define f(i, a, b) for (int i = a; i <= b; i++) // 1 based indexing
#define pb push_back
#define fi first
#define se second


const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

//	STEP 1 - state -> what ans to hold in every array of the dp
// 	STEP 2 - recursion
//	STEP 3 - Base Case
void solve() {
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	bool typable[26]={0};
	f0(i,k){
		char ch;
		cin>>ch;
		typable[ch-'a']=1;
	}
	f0(i,n)
		s[i] = typable[s[i]-'a']? 1:0;

	ll dp[n+1];
	dp[0]=0;
	ll ans=0;
	f0(i,n){
		if(s[i]==0)
			dp[i+1]=0;
		else
			dp[i+1]=dp[i]+1;
			
		ans+=dp[i+1];
	}
	cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}