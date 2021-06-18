/*
	Link : https://leetcode.com/problems/burst-balloons/
	Idea :-
		dp[L][R] = best score we can achieve from the interval from L to R
		a[] = { 2 | 3 | 7 | 5 | 10 }
		think backwards - Instead of thinking which ballon to pop first
									 think which ballon to pop last
		a[L-1]*a[i]*a[R+1] + dp[L][i-1] + dp[i][R+1]
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

int maxCoins(vector<int>& a){
	if(a.empty())
		return 0;
	int n = (int)a.size();
	vector<vector<int>> dp(n, vector<int>(n));
	for(int l=n-1;l>=0;l--){
		for(int r = l;r<n;r++){
			for(int i=l;i<=r;i++)
				dp[l][r]=max(
							dp[l][r],
							a[i]*(l?a[l-1]:1)*(r==n-1?1:a[r+1]) + (l<=i-1?dp[l][i-1]:0) + (r>=i+1?dp[i+1][r]:0)
							);	 
		}
	}
	return dp[0][n-1];
}


void solve() {
	int n;
	cin>>n;
	vector<int> nums(n);
	f0(i,n)
		cin>>nums[i];
	cout<<maxCoins(nums)<<endl;		
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