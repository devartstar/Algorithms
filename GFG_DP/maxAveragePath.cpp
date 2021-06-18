/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 16.06.2021 			|
	|	Time   - 00:21:24				|	
	|									|
	-------------------------------------
	
	Link - https://www.geeksforgeeks.org/path-maximum-average-value/
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
	int n,m;
	cin>>n>>m;
	double path[n][m];
	pair<double,int> dp[n][m];
	f0(i,n)
		f0(j,m)
			cin>>path[i][j], dp[i][j]=make_pair(path[i][j]*1.0, 1);
			
	f0(i,n)
		f0(j,m){
			double new_avg1,new_avg2;
			if(j!=0){
				new_avg1 = (dp[i][j-1].first*dp[i][j-1].second + dp[i][j].first)/(dp[i][j-1].second+1);
			}else new_avg1=0;
			if(i!=0){
				new_avg2 = (dp[i-1][j].first*dp[i-1][j].second + dp[i][j].first)/(dp[i-1][j].second+1);
			}else new_avg2=0;
			if(new_avg2>new_avg1){
				dp[i][j].first=new_avg2;
				dp[i][j].second=dp[i-1][j].second+1;
			}else{
				dp[i][j].first=new_avg1;
				dp[i][j].second = dp[i][j-1].second+1;
			}
		}
			
	f0(i,n){
		f0(j,m)
			cout<<dp[i][j].first<<","<<dp[i][j].second<<"  |  ";
		cout<<"\n";
	}
	 

	cout<<dp[n-1][m-1].first<<"\n";
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