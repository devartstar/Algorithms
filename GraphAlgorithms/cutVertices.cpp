#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int visited[100001]={0};
int low[100001], in[100001];
int timer = 0;
int n,m;

void dfs(int node,int parent = -1){
	visited[node]=1;
	in[node]=low[node]=timer++;
	int children=1;

	for(int child : v[node]){
		if(child == parent)	continue;
		if(visited[child]){
			low[node]=min(low[node],in[child]);	
		}
		else{
			dfs(child,node);
			low[node]=min(low[node],low[child]);
			if(parent!=-1 && low[child] >= in[node]){
				cout<<node<< "  is a cutVertex"<<endl;
			}
			children++;
		}

	}
	if(children>1 && parent==-1){
		cout<<node<< "  is a cutVertex"<<endl;
	}
	
}

void findCutVertices(){
	for(int i=1;i<=n;i++){
	 	if(!visited[i]){
	 	 	dfs(i);
	 	}
	}
}

int main(){ 
	int a,b;
 	cin>>n>>m;
	for(int i=0;i<m;i++){
	 	cin>>a>>b;
	 	v[a].push_back(b);
	 	v[b].push_back(a);
	}

	findCutVertices();
}
