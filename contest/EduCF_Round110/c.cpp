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
vector<string> v;
vector<int> cq;

bool checkIfvalidQM(int i, int j){
	cout<<i<<","<<j<<" -- "<<cq[i]<<endl;
	// all s = v[i]
	if(v[i][j+1]=='?')
		return true;
	if(cq[i]%2==0){
		if(j+1<n){
			if(v[i][j-cq[i]]!=v[i][j+1])
				return true;
			else
				return false;
		}
		else
			return true;
	}
	if(cq[i]%2==1){
		if(j+1<n){
			if(v[i][j-cq[i]]==v[i][j+1])
				return true;
			else
				return false;
		}
		else
			return true;
	}
	return false;
}

void solve() {
	string s;
	cin>>s;
	n = (int)s.length();
	v.resize(n);
	cq.resize(n);
	for(int i=0;i<n;i++){
		v[i]=s;
		cq[i]=0;
	}
	int dp[n][n];
	memset(dp,0,sizeof(dp));
	
	for(int i=0;i<n;i++)
		dp[i][i]=1;
	for(int col=2;col<=n;col++){
		for(int i=0;i<n-col+1;i++){
			int j = i + col-1;
			
			bool res=false;
			if(v[i][j]=='?'){
				cq[i]++;
			}
			if(v[i][j-1]=='?' && v[i][j]!='?'){
				res=checkIfvalidQM(i,j-1);
				cout<<i<<","<<j<<" "<<res<<endl;
				cq[i]=0;
			}
			
				
			if((v[i][j]!=v[i][j-1] && (v[i][j]=='1' || v[i][j]=='0') && (v[i][j-1]=='1' || v[i][j-1]=='0')) || res || v[i][j]=='?'){
				dp[i][j]+=(dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]+1);
			}else{
				dp[i][j]+=(dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]);
			}
		}

	}
			
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout<<dp[i][j]<<" ";
				}
				cout<<endl;
			}
	
	cout<<dp[0][n-1]<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
	cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}