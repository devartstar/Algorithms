/*
	https://codeforces.com/problemset/problem/1437/C
	**** DP HARD **** TRY AGAIN LATER ****
	*** SOLVE NEXT - https://codeforces.com/contest/1525/problem/D ***
	n - number of dishes in an oven
	ti - cooking time of i'th dish
	at a time T - take out no more than 1 dish
	** T - not necessarily starting from 1 and might not be continous **
	unplesant time = |T-ti|
	Minimize unplesant time.
*/

#include <bits/stdc++.h>
using namespace std;

int n; 
int dp[200][405];
vector<int> v;

int calcTime(int idx, int t){
 	if(idx>=n){
 		return 0;
 	}
 	if(dp[idx][t]!=-1){
 	 	return dp[idx][t];
 	}
 	int mn=INT_MAX;
 	for(int i=t;i<=max(t,v[idx]);i++){
 	 	mn=min(mn,abs(v[idx]-i)+calcTime(idx+1, i+1));
 	}

 	return dp[idx][t]=mn;
}

void solve(){
	 int a;
 	 cin>>n;
 	 v.clear();
 	 memset(dp,-1,sizeof(dp)); 
 	 for(int i=0;i<n;i++){
 	  	cin>>a;
 	  	v.push_back(a);
 	 }
 	 sort(v.begin(),v.end());
 	 int ans = calcTime(0,1);
 	 cout<<ans<<endl;
 	
}

int main(){
 	int t;
 	cin>>t;
 	while(t--){
 	 	solve();
 	}
}
