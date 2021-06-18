/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 10.06.2021 			|
	|	Time   - 14:30:33				|	
	|									|
	-------------------------------------
	
	Link - https://atcoder.jp/contests/dp/tasks/dp_f
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

string s1,s2;
int dp[10001][10001];
	
string findLCS(){
	string res;
	int n = s1.length();
	int m = s2.length();
    int l = dp[n][m];
    res.resize(l);
    int i=n,j=m,ind=l-1;
    while(i>0&&j>0)
    {
        if(s1[i-1]==s2[j-1]) {res[ind]=s1[i-1];ind--;i--;j--;}
        else
        {
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
	return res;
}

void solve() {
	cin>>s1>>s2;
	int l1=s1.length(), l2=s2.length();
	
	f0(i,l1+1)
		dp[i][0]=0;
	f0(i,l2+1)
		dp[0][i]=0;
	
	f1(i,l1)
		f1(j,l2)
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
	/*
	f0(i,l1+1){
		f0(j,l2+1)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
	*/
	// to trace back the string
	cout<<findLCS()<<"\n";
	//cout<<dp[l1][l2]<<"\n";
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