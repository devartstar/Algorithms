/*
  			!!! ACCEPTED
  	https://codeforces.com/problemset/problem/862/B
*/


#include <bits/stdc++.h>
using namespace std;

vector<long long> v[1000001];
long long visited[1000001];
long long color[1000001];
long long n,m;

bool dfs(long long node, long long col){
 	visited[node]=1;
 	color[node]=col;

 	for(int child : v[node]){
 	 	if(!visited[child]){
 	 	 	if(dfs(child,col^1)==false)
 	 	 		return false;
 	 	}
 	 	if(color[child]==color[node]){
 	 		return false;
		}
 	}
 	return true;
}


int main(){
 	cin>>n;
	m=n-1;
	for(long long i=0;i<=n;i++){
	 	visited[i]=0;
	 	color[i]=-1;
	}
	for(long long i=1;i<=m;i++){	
	 	int a,b;
	 	cin>>a>>b;
	 	v[a].push_back(b);
	 	v[b].push_back(a);
	}
	bool ans=dfs(1,0);
	if(ans){
		long long c1=0,c2=0;
		for(long long i=1;i<=n;i++){
		 	if(color[i]==0)	c1++;
		 	if(color[i]==1)	c2++;
		}
		long long ans = c1*c2-m;
		cout<<ans<<endl;
	}else{
	 	cout<<"Given graph is not a bipartite"<<endl;
	}
}
