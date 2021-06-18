/*
	Link : https://practice.geeksforgeeks.org/problems/number-of-coins/0
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

int n,m;
vi coins;

int minCoinRecursive(int n1, int m1){
	if(n1==0)
		return 0;
	int result = MAX_N;
	for(int i=0;i<m1;i++){
		if(n1-coins[i]>=0)
			result = min(result,1+minCoinRecursive(n1-coins[i],m1));
	}
	return result;
}

int minCoinDP(){
	int dp[n+1];
	f0(i,n+1)
		dp[i]=MAX_N;

	dp[0]=0;
	
	for(int i=1; i<=n; i++){
		for(int j=0;j<m;j++){
			if(i>=coins[j])
				dp[i]=min(dp[i],1+dp[i-coins[j]]);
		}
	}
	return dp[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        cin>>n>>m;
        coins.resize(m);
        f0(i,m)
        	cin>>coins[i];
        int c;
        cin>>c;
        switch(c){
        	case 1:
        		cout<<minCoinDP()<<endl;
        		break;
        	case 2:
        		cout<<minCoinRecursive(n,m)<<endl;
        		break;	 
        }
    }
}