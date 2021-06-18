#include <bits/stdc++.h>
using namespace std;

void solve(){
 	long long n;
 	cin>>n;
 	long long arr[n];
 	long long count[2*n+1]={0};
 	for(int i=0;i<n;i++){
 		int x;
 		cin>>x;
 		arr[i]=x-i+n;
 		count[arr[i]]++;
 	}
 	long long ans=0;
	for(int i=0;i<=2*n;i++){
	 	ans = ans + (count[i]*(count[i]-1))/2;
	}

	cout<<ans<<endl;
}                                            

int main(){
	long long t;
	cin>>t;
	while(t--){
		solve();
	}	
}