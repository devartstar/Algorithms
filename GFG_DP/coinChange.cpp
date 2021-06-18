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

vi dp;
vi coins;
int n,m;

int recursiveApproach(int dlsize, int sum){	
	// it has overlapping subproblem property so memomoze to form dp
	if(sum==0)
		return 1;
	if(sum<0)
		return 0;
	if(dlsize <= 0 && sum>=1)
		return 0;
	return recursiveApproach(dlsize-1,sum) + recursiveApproach(dlsize,sum-coins[dlsize-1]);
}

int iterative2dDPappraoch(){
	int DP[n+1][m];
	memset(DP,0,sizeof(DP));
	f0(i,m)
		DP[0][i]=1;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			DP[i][j] = (j-1>=0?DP[i][j-1]:0) + (i-coins[j]>=0?DP[i-coins[j]][j]:0);
		}
	}
	return DP[n][m-1];
}

// below is the simplified version of the above function
int iterativeDPapproach() {
	sort(coins.begin(),coins.end());
	dp[0]=1;
	f0(i,m){
		int a = coins[i];
		for(int j=0;j<=n;j++){
			dp[j] += (j-a>=0)?dp[j-a]:0;	
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
		dp.resize(n+1);
		coins.resize(m);
		f0(i,m){
			cin>>coins[i];	
		}
		int c;
		ll ans;
		cin>>c;
		switch (c){
			case 1 :
				ans = iterativeDPapproach();
				break;
			case 2 : 
				ans = iterative2dDPappraoch();
				break;
			case 3 : 
				ans = recursiveApproach(m,n);	// m - denomination set size || n - sum to be obtained
				break;
		}
			 
        cout<<ans<<endl;
    }
}