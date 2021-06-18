/*
	Link : https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1
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


int solve() {
	int n;
	cin>>n;
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	/*
	// !!! When order of elements taken matters
	for(int i=1;i<=n;i++){
		int a = (i-3>=0? dp[i-3] : 0 );
		int b = (i-5>=0? dp[i-5] : 0 );
		int c = (i-10>=0? dp[i-10] : 0 );
		dp[i] += (a+b+c);
	}
	*/
	
	// !!! When order of elements taken does not matter

		for(int i=3;i<=n;i++){
			dp[i]+=dp[i-3];
		}
		for(int i=5;i<=n;i++){
			dp[i]+=dp[i-5];
		}
		for(int i=10;i<=n;i++){
			dp[i]+=dp[i-10];
		}
	
	return dp[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
	cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        cout<<solve()<<endl;
    }
}