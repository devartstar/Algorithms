/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 09.06.2021 			|
	|	Time   - 19:02:17				|	
	|									|
	-------------------------------------
	
	Link - https://www.geeksforgeeks.org/find-maximum-length-snake-sequence/
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

int n,m;
int arr[101][101];
int dp[101][101];

vector<pair<int,int>> v;

// trace back from n,m to 0 to obtain solution to the dp.
void findPath(int x, int y){
	v.pb({x,y});
	while(dp[x][y]!=0){
		if(x>0 && dp[x][y] == dp[x-1][y] + 1){
			v.insert(v.begin(),{x-1,y});
			x--;
		}
		else if(y>0 && dp[x][y] == dp[x][y-1]+1){
			v.insert(v.begin(),{x,y-1});
			y--;
		}
	}
}

void solve() {
	cin>>n>>m;
	
	f0(i,n)
		f0(j,m)
			cin>>arr[i][j];
	/*
		DP Approach -
			-> dp[row position][col position] - Max length of the snake upto this row and col position
		 	-> Base Case all dp[i][j]=1;
		 	-> recursion dp[i][j] = max(dp[i][j], dp[i-1][j] + 1)	// for down movement
		 				 dp[i][j] = max(dp[i][j], dp[i][j-1] + 1)	// gor right movement
	*/
	
	f0(i,n)
		f0(j,m)
			dp[i][j]=0;
	
	int max_length = 0;
	int max_row = 0;
	int max_col = 0;
	
	f0(i,n){
		f0(j,m){
			if(i==0 && j==0)	continue;
			if(i>0 && abs(arr[i-1][j] - arr[i][j])==1){
				dp[i][j]=max(dp[i-1][j]+1,dp[i][j]);
				if(max_length<dp[i][j]){
					max_length=dp[i][j];
					max_row = i;
					max_col = j;
				}
			}
			if(j>0 && abs(arr[i][j-1]-arr[i][j])==1){
				dp[i][j]=max(dp[i][j], dp[i][j-1]+1);
				if(max_length<dp[i][j]){
					max_length=dp[i][j];
					max_row=i;
					max_col=j;
				}
			}
		}
	}

	findPath(max_row,max_col);
	cout<<"Size of the Snake : "<<max_length<<endl;
	f0(i,max_length){
		cout<<i+1<<" "<<v[i].first<<","<<v[i].second<<"\n";
	}	
	
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