/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 15.06.2021 			|
	|	Time   - 06:57:13				|	
	|									|
	-------------------------------------
	
	Link - https://www.geeksforgeeks.org/maximum-product-increasing-subsequence/
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


void solve() {
	int n;
	cin>>n;
	vi v(n);
	f0(i,n)	cin>>v[i];
	int dp[n];
	int parent[n];
	f0(i,n){
		dp[i]=v[i];
		parent[i]=-1;
	}
	for(int i=1;i<n;i++){
		for(int j=0; j<i;j++){
			if(v[i]>v[j]){
				dp[i]=max(dp[i],dp[j]*v[i]);
				if(dp[i]==dp[j]*v[i])	parent[i]=j;
			}
		}
	}
	int ind = max_element(dp,dp+n) - dp;
	cout<<dp[ind]<<"\n";
	vi result;
	while(ind!=-1){
		result.insert(result.begin(), v[ind]);
		ind=parent[ind];
	}
	f0(i,(int)result.size())	cout<<result[i]<<" ";
	cout<<"\n";
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