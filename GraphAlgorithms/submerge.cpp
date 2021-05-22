/*
	islands --- on submerging disconnects the rest
	Basically find the number of Articulation Points 
	https://www.spoj.com/problems/SUBMERGE/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int visited[100001];
int low[100001],in[100001];
int timer;
int n,m;
set<int> AP;

void dfs(int node, int parent = -1){
 	visited[node]=1;
 	in[node]=low[node]=timer++;
	int children = 0;
 	for(auto child : v[node]){
    	if(child==parent)	continue;
    	if(visited[child]){
    	 	low[node]=min(low[node], in[child]);
    	}else{
    	 	dfs(child,node);
    	 	if(parent!=-1 && low[child]>=in[node]){
    	 	 	// node is an articulation point
    	 	 	AP.insert(node);
    	 	}
    	 	low[node]=min(low[node],low[child]);
    	 	children++;
    	}
 	}
 	if(children>1 && parent==-1){
		// root is an articulation point
    	AP.insert(node);
   	}
}

void findArticulationPoints(){
 	for(int i=1;i<=n;i++){
 	 	if(!visited[i]){
 	 	 	dfs(i);
 	 	}
 	}
}

int main(){
 	int a,b;
 	while(1){
 		cin>>n>>m;
 		for(int i=0;i<=n;i++){
 		 	visited[i]=0;
 		 	in[i]=-1;
 		 	low[i]=-1;
 		 	v[i].clear();
 		}
 		AP.clear();
 		timer=0;
 		if(n==0 && m==0){
 			break;
 		}
 		for(int i=0;i<m;i++){
 		 	cin>>a>>b;
 		 	v[a].push_back(b);
 		 	v[b].push_back(a);
 		}

 		findArticulationPoints();
 		cout<<(int)AP.size()<<endl;
 	}
}