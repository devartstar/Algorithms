/*			!!! ACCEPTED
  	https://codeforces.com/contest/707/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
 	int n,m,k;
 	cin>>n>>m>>k;
 	int u[m+1],v[m+1],l[m+1];
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>l[i];
	}
	int ok[n+1];
	//cout<<"lol"<<endl;
	memset(ok,0,sizeof(ok));
	//cout<<"lol1"<<endl;
	for(int i=1;i<=k;i++){
	 	int a;
	 	cin>>a;
	 	ok[a]=1;
	}
	//cout<<"lol2"<<endl;

	int ans=1e9+1;
	for(int i=1;i<=m;i++){
	 	if(ok[v[i]]!=ok[u[i]])
	 		ans=min(ans,l[i]);
	}
	if(ans==1e9+1)
	cout<<-1<<endl;
	else
	cout<<ans<<endl;
}