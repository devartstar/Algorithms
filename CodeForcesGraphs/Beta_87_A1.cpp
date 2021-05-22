/*
	ACCEPTED
	https://codeforces.com/problemset/problem/115/A
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> v[20001];
int level[20001]={0};
int visited[20001]={0};

void dfs(int node,int t){
 	visited[node]=1;
 	level[node]=t;

 	for(int child : v[node]){
 		if(!visited[child])
 	 	dfs(child,level[node]+1);
 	}
}

int main(){
	
	int n,a;
	cin>>n;
	vector<int> vec;
	for(int i=1;i<=n;i++){
	 	cin>>a;
	 	vec.push_back(a);
	 	if(a!=-1)	v[a].push_back(i);
	}

	for(int i=1;i<=n;i++){    
	 	if(visited[i]==0 && vec[i-1]==-1){
	 	 	dfs(i,1);
	 	}
	}

	int ans=-1;
	for(int i=1;i<=n;i++){       
	 	ans=max(ans,level[i]);	
	}
	cout<<ans<<endl;

	/*
	for(int i=1;i<=n;i++){
	 	cout<<level[i]<<" ";
	}
	cout<<endl;
	*/
}