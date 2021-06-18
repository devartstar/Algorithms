/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - ___curd___ 			|
	|	Time   - __curt__				|	
	|									|
	-------------------------------------
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

// Method 1 -> O(N^2)
void solve(vector<int> v, int n) {
	int dp[n]={1};
	int parent[n]={-1};

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(v[j]<v[i]){
				dp[i]=max(dp[i],dp[j]+1);
				if(dp[i]==dp[j]+1){
					parent[i]=j;
				}
			}
		}
	}
	
	int ind = max_element(dp,dp+n)-dp;
	cout<<dp[ind]<<"\n";
	vi res;
	while(parent[ind]!=-1){
		res.insert(res.begin(),v[ind]);
		ind = parent[ind];
	}
	res.insert(res.begin(),v[ind]);
	f0(i,(int)res.size())	cout<<res[i]<<" ";
	cout<<"\n";
}


// Method 2 -> O(N^2)
void solve1(vector<int> v, int n){
	vi v1=v;
	sort(all(v1));
	// find lcs of v1 and v
	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(v[i-1]==v1[j-1])
				dp[i][j]=max(dp[i][j], dp[i-1][j-1]+1);
			else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout<<dp[n][n]<<"\n";
	
	int x=n,y=n;
	vi res;
	while(x!=0 && y!=0){
		if(dp[x][y]==dp[x-1][y])	x--;
		else if(dp[x][y]==dp[x][y-1])	y--;
		else{
			x--;y--;
			res.insert(res.begin(),v[x]);
		}
	}
	f0(i,(int)res.size())
		cout<<res[i]<<" ";
	cout<<"\n";
}	

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        int n;
		cin>>n;
		vi v(n);
		f0(i,n)	cin>>v[i];

        solve(v,n);
        solve1(v,n);
    }
}