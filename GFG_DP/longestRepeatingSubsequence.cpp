/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 14.06.2021 			|
	|	Time   - 11:18:24				|	
	|									|
	-------------------------------------
	
	Link - https://www.geeksforgeeks.org/longest-repeated-subsequence/
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


void solve(string s) {
	int len = s.length();
	int dp[len+1][len+1];

	memset(dp,0,sizeof(dp));
			
	f1(i,len){
		f1(j,len){
			if(s[i-1]==s[j-1] && i!=j)
				dp[i][j]=max(dp[i][j], dp[i-1][j-1]+1);
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	
	cout<<"Length of the longest repeated subsequence "<< dp[len][len]<<"\n";
	
	// Now revert back the string
	int x=len, y=len;
	string ans="";
	while(x!=0 && y!=0){
		if(dp[x][y]==dp[x-1][y])	x--;
		else if (dp[x][y]==dp[x][y-1])	y--;
		else if(dp[x][y]==dp[x-1][y-1]+1){
			ans = s[x-1]+ans;
			x--;y--;
		}
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
        string s;
        cin>>s;
        solve(s);
    }
}