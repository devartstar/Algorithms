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

vi s;

bool subsetSumRecursice(int n, int sum) {
	if(sum==0)
		return true;
	if(n==0)
		return false;
	return subsetSumRecursice(n-1,sum) || (sum-s[n-1]>=0?subsetSumRecursice(n-1,sum-s[n-1]):false);
	
}

bool DP[10001][10001];

// O(sum*n) space complexity
bool subsetSumDP(int n, int sum){
	f0(i,sum+1){
		DP[0][i]=false;	
	}
	f0(j,n+1){
		DP[j][0]=true;
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=sum; j++){
			DP[i][j] = DP[i-1][j] || (s[i-1]>j?false:DP[i-1][j-s[i-1]]);		
		}
	}
	/*
	f0(i,n+1){
		f0(j,sum+1)
			cout<<DP[i][j]<<" ";
		cout<<endl;
	}
	cout<<n<<","<<sum<<" -- "<<DP[n][sum]<<endl;	
	*/
	return DP[n][sum];
}

// constant space complexity
bool subsetSumDP_OederN_Space(int n,int sum){
	bool dp[2][sum+1];
	memset(dp,false,sizeof(dp));
	dp[0][0]=true;
	dp[1][0]=true;
	
	f0(i,n+1)
		f1(j,sum){
			if(i==0)
				dp[i%2][j]=false;
			/*
			else if(s[i-1]<=j)
				dp[i%2][j]=dp[(i+1)%2][j-s[i-1]] || dp[(i+1)%2][j];
			else
				dp[i%2][j] = dp[(i+1)%2][j];
			*/
			dp[i%2][j] = dp[(i+1)%2][j] || (j-s[(i+1)%2]<0?false:dp[(i+1)%2][j-s[(i+1)%2]]);
		}
	return dp[n%2][sum];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        int n,sum;
        cin>>n>>sum;
        s.resize(n);
        f0(i,n){
        	cin>>s[i];
        }
        int c;
        bool ans=false;
        cin>>c;
        switch(c){
        	case 1:
        		ans = subsetSumRecursice(n,sum);
        		break;
        	case 2:
        		ans = subsetSumDP(n,sum);
        		break;
        	case 3:
        		ans = subsetSumDP_OederN_Space(n,sum);
        		break;
        }
        
		if(ans){
			cout<<"Found a subset for following sum"<<endl;
		}else{
			cout<<"Did not found a subset for following sum"<<endl;
		}
    }
}