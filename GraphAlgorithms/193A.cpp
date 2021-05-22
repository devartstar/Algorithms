/*	
      Codeforces Round #122 (Div. 1) A
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int visited[100001]={-1};
int in[100001]={-1};
int low[100001]={-1};
int timer;
int cnt=0;
 
void dfs(int node,int parent){
	visited[node]=1;
	low[node]=in[node]=timer;
	timer++;
	int children = 0;
	for(int child : v[node]){
	 	if(child == parent)	continue;
	 	if(visited[child]){
	 		low[node]=min(low[node],in[child]);
	 	}else{
	 		dfs(child,node);
	 	 	low[node]=min(low[node],low[child]);
	 	 	if(low[child]>=in[node] && parent!=-1){
	 	 		cnt++;
			}
			children++;
	 	}
	}
	if(parent==-1 && children>1){
		cnt++;
	}	
}

void findCutPoints(int number_nodes){
 	timer=0;
 	for(int i=1;i<=number_nodes;i++){
 		if(!visited[i]){
 		 	dfs(i,-1);
 		}
 	}	
}

int main(){
 	int n,m; 
  	cin>>n>>m;
 	char arr[n][m];
 	for(int i=0;i<n;i++){  
		for(int j=0;j<m;j++){
			cin>>arr[i][j];	
		}
 	}

 	// given i,j of a 2d Array it corresponds to the node --- n*i + j;
 	for(int i=0;i<n;i++){
 		for(int j=0;j<m;j++){
 			if(arr[i][j]=='#'){
 				if(i+1 < n && arr[i+1][j]=='#')	
 					v[n*i+j].push_back(n*(i+1)+j);
 				if(i-1 >= 0 && arr[i-1][j]=='#')
 					v[n*i+j].push_back(n*(i-1)+j);
 				if(j+1 < m && arr[i][j+1]=='#')
 					v[n*i+j].push_back(n*i+j+1);
 				if(j-1 >= 0 && arr[i][j-1]=='#')
 					v[n*i+j].push_back(n*i+j-1);
 			}
 		}
 	}

 	findCutPoints(n);

 	cout<<cnt<<endl;
}
