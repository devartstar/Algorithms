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

void solve() {
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	int len1=s1.length(), len2=s2.length(), len3=s3.length();
	int dp[len1+1][len2+1][len3+1];
	memset(dp,0,sizeof(dp));
	f1(i,len1){
		f1(j,len2){
			f1(k,len3){
				if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])	dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-1] + 1);
				else	dp[i][j][k] = max(max(dp[i][j][k], dp[i-1][j][k]), max(dp[i][j-1][k], dp[i][j][k-1]));
			}
		}
	}
	cout<<dp[len1][len2][len3]<<"\n";
	int x=len1,y=len2,z=len3;
	string ans="";
	while(x!=0 && y!=0 && z!=0){
		if(dp[x][y][z]==dp[x-1][y][z])	x--;
		else if(dp[x][y][z]==dp[x][y-1][z])	y--;
		else if(dp[x][y][z]==dp[x][y][z-1])	z--;
		else{
			x--;y--;z--;
			ans=s1[x]+ans;
		}
	}
	cout<<ans<<"\n";
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