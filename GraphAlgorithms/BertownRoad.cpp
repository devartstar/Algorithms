/*              
Codeforces Beta Round #89 (Div. 2) Question E

  	Given n nodes and m edges
  	Intially the graph is birectional
  	conditions -
  	1.	Can we convert it to a directional graph which is strongly connected
  	2.	From every node we can reach the root
*/
/*
  	Hint - 
	The Graph must not contain any bridge.
  	Then YES else NO
	// for Forward edge --- diectional from parent to child
	// for Back Edge --- directional from child to parent

	CONSIDER PARENT NODE - i
	in v[i] = {a,b,c}
	then either of a,b,c there must be a node which connects to parent of i.

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int visited[100001]={0};
int in[100001]={0};
int low[100001]={0};
int timer=0;
bool bridge = false;
vector<pair<int,int>> dv;

void dfs(int node, int parent){
 	visited[node]=1;
	in[node]=low[node]=timer++;	

	for(int child : v[node]){
		if(child==parent) continue;
		if(visited[child]){
			// Back Edge
		 	low[node]=min(low[node],in[child]);
			if(in[node] > in[child]){	// one with higher in-time is the child
			 	dv.push_back({node,child});
			}

	  	}else{
	  	 	dfs(child,node);
	  	 	if(low[child]>in[node]){
	  	 	 	bridge = true;
	  	 	 	return;
	  	 	}                           
	  		//the following edge is Forward Edge
		  	dv.push_back({node,child});
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
	if(bridge){
	    cout<<"0"<<endl;
	}else{
	    for(pair<int,int> i : dv){
	     	cout<<i.first<<" "<<i.second<<"\n";
	    }
	}
}