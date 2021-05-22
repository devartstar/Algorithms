#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int visited[100001]={0};
int low[100001], in[100001];
int timer = 0;

void dfs(int node, int parent = -1){
	visited[node]=1;
	in[node]=low[node]=timer++;

	for(int child : v[node]){
		if(child == parent)	continue;
		if(visited[child]){
		 	low[node]=min(low[node],in[child]);
		}else{
			dfs(child,node);
			if(low[child]>low[node]){
				// then node----child is a bridge
				cout<<node<<" , "<<child<<" is a bridge"<<endl;
			}
			low[node]=min(low[node],low[child]);
		}
	}
}

int main(){
	int n,m,a,b;
	cin>>n>>m;
	for(int i=0;i<m;i++){
	 	cin>>a>>b;
	 	v[a].push_back(b);
	 	v[b].push_back(a);
	}

	dfs(1,-1);
}