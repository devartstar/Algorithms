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

int n;
vi arr;

int mysoln(){
	int dp[n][n];
	memset(dp,0,sizeof(dp));
	f0(i,n)
		dp[i][i]=1;
	for(int i=n-2;i>=0;i--){
		for(int j=i+1; j<n; j++){
			if(arr[j]%arr[i]==0){
				dp[i][n-1] = 1 + dp[j][n-1];
				break;
			}else
				dp[i][j]=1;
		}
	}
	int ans=-1;
	f0(i,n){
		ans=max(ans,dp[i][n-1]);
	}
	
	return ans;
}

// can also be done in Space Complexity of O(N)

void solve() {
	cin>>n;
	arr.resize(n);
	f0(i,n)
		cin>>arr[i];
	sort(arr.begin(),arr.end());
	int ans = mysoln();
	cout<<ans<<endl;
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