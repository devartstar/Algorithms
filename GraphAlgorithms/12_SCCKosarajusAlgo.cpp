/*
  	KOSARAJU'S ALGORITHM
  	Algorithm for finding Strongly Connected Components
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
vector<int> rv[100001];
int visited[100001]={0};
vector<int> ord;
vector<int> scc;

void dfs(int node){
 	visited[node]=1;

 	for(int child : v[node]){
 	 	if(!visited[child])
 	 		dfs(child);
 	}

 	ord.push_back(node);
}

void dfs1(int node){
 	visited[node]=1;
 	for(int child : rv[node]){
 	 	if(!visited[child]){
 	 	 	dfs1(child);
 	 	}
 	}
 	scc.push_back(node);
}

int main(){
	int t;
	cin>>t;
	while(t--){
	  	int n,m,a,b;
 		cin>>n>>m;
 		for(int i=0;i<=n;i++){
 		 	v[i].clear();
 		 	rv[i].clear();
 		 	visited[i]=0;
 		}
 		ord.clear();
 		for(int i=0;i<m;i++){
 		 	cin>>a>>b;
 		 	v[a].push_back(b);
 		 	rv[b].push_back(a);
	 	}

	 	for(int i=1;i<=n;i++){
	 	 	if(!visited[i]){
	 	 	 	dfs(i);
	 	 	}
	 	}

	 	for(int i=1;i<=n;i++){
	 	 	visited[i]=0;
	 	}

	 	for(int i=1;i<=n;i++){
	 	 	 if(visited[ord[n-i]]==0){
	 	 	  	scc.clear();
	 	 	  	dfs1(ord[n-i]);
	 	 	  	for(int node : scc){
	 	 	  	 	cout<<node<<" ";
	 	 	  	}
	 	 	  	cout<<endl;
	 	 	 }
	 	}
	}
}


//  deg(0)