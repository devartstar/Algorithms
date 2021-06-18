/*
	Link : https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1
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


int solve() {
	int n,m;
	cin>>n>>m;
	int gold[n][m];
	f0(i,n)
		f0(j,m)
			cin>>gold[i][j];
	int goldTable[n][m];
	memset(goldTable,0,sizeof(goldTable));
	for(int i=m-1;i>=0;i--){
		for(int j=0;j<n;j++){
			int right = (i==m-1)?0:goldTable[j][i+1];
			int right_top = (j==0 || i==m-1)?0:goldTable[j-1][i+1];
			int right_down = (j==n-1 || i==m-1)?0:goldTable[j+1][i+1];
			goldTable[j][i] = gold[j][i] + max(right,max(right_top,right_down));
		}
	}
	int ans = -1;
	f0(i,n){
		ans = max(ans,goldTable[i][0]);
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        cout<<solve()<<endl;
    }
}