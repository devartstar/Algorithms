/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 09.06.2021 			|
	|	Time   - 15:58:40				|	
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
	int n,st1,st2,end1,end2;
	cout<<"Enter Number of stations"<<endl;
	cin>>n;
	vpii station(n);
	cout<<"Enter time cost for stations in line 1"<<endl;
	f0(i,n)	cin>>station[i].first;
	cout<<"Enter time cost for stations in line 2 "<<endl;
	f0(i,n)	cin>>station[i].second;
	vpii switch_line(n-1);
	cout<<"Enter line switch time for 1st line "<<endl;
	f0(i,n-1)	cin>>switch_line[i].first;
	cout<<"Enter line switch time for 2nd line"<<endl;
	f0(i,n-1)	cin>>switch_line[i].second;
	cout<<"enter initial start time for line 1 and line 2 "<<endl;
	cin>>st1>>st2;
	cout<<"enter finall end time for line 1 and line 2 "<<endl;
	cin>>end1>>end2;
	vpii dp(n);
	dp[0].first = station[0].first + st1;
	dp[0].second = station[0].second + st2;
	f(i,1,n-1){
		dp[i].first = min(dp[i-1].first, dp[i-1].second + switch_line[i-1].second) + station[i].first;
		dp[i].second = min(dp[i-1].second, dp[i-1].first + switch_line[i-1].first) + station[i].second;
	}
	dp[n-1].first+=end1;
	dp[n-1].second+=end2;
	cout<<"Total time - "<<min(dp[n-1].first,dp[n-1].second)<<endl;
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