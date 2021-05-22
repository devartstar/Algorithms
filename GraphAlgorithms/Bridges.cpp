#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int visited[100001]={0};
int in[100001]={0};
int low[100001]={0};
int timer = 0;

bool isBridge(int child, int node){
 	 	 	// node - child is a front edge
 	 	 	/*
 	 	 		low[parent] > low[child] then only they are valid parent child
 	 	 		else if not then it insits child is connected to another parent
 	 	 		so parent - child not a bridge
 	 		*/

	return low[node]<low[child];	
}

void dfs(int node,int parent){
 	visited[node]=1;
 	in[node]=low[node]=timer++;

 	for(int child : v[node]){
		if(child==parent)
			continue;
		if(visited[child]==1){
			// node - child is back edge
			// Back Edges can never be a bridge
			low[node]=min(in[child],low[node]);
 	 	}else{
 	 	 	dfs(child,node);
 	 	 	if(isBridge(child,node)){
 			  cout<<"("<<node<<","<<child<<") is a bridge"<<"\n";
 	 	 	}
 	 	 	low[node]=min(low[child],low[node]);
			
 	 	}
 	}
}

int main(){
	int n,m,a,b;
	cin>>n>>m;
	for(int i=0;i<m;i++){
	 	cin>>a>>b;
	 	// creating an undirected graph
	 	v[a].push_back(b);
	 	v[b].push_back(a);
	}

	dfs(1,-1);	// nodes are {1,2,3,4,5.....n}
}