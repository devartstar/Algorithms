/*
  	https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/jungle-run/
  	consider S - as root
  		     P - as nodes 
  		     E - its level is the ans
*/
#include <bits/stdc++.h>
using namespace std;

char v[10001][10001];
int visited[10001][10001];
int dist[10001][10001]; 
pair<int,int> start;
pair<int,int> finish;
int n;


bool isValid(int x,int y){
	if(x>=0 && x<n && y>=0 && y<n && v[x][y]!='T' && visited[x][y]==0){
	 	return true;
	}

	return false;
}

void dfs(int x,int y,int d){
	visited[x][y]=1;
	dist[x][y]=d;

	if(isValid(x-1,y)){	// top
		dfs(x-1,y,dist[x][y]+1);
	}
	if(isValid(x,y+1)){	// right
		dfs(x,y+1,dist[x][y]+1);
	}
	if(isValid(x+1,y)){	// down
		dfs(x+1,y,dist[x][y]+1);
	}
	if(isValid(x,y-1)){	// left
		dfs(x,y-1,dist[x][y]+1);
	}
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>v[i][j];    		
    		if(v[i][j]=='S'){
    		 	start.first=i;
    		 	start.second=j;
    		}
    		if(v[i][j]=='E'){
    		 	finish.first=i;
    		 	finish.second=j;
    		}
    		visited[i][j]=0;
    	}
    }


    dfs(start.first,start.second,0);

    cout<<dist[finish.first][finish.second]<<endl;
}

/*	// ACCEPTED
#include<bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int visited[100001]={0};
int dist[100001]={-1};
int start,finish;

void bfs(int node){
	queue<int> q;
 	visited[node]=1;
 	dist[node]=0;
 	q.push(node);
 	while(!q.empty()){
 		int parent = q.front();
 		q.pop();
 		for(int child : v[parent]){
 		 	if(!visited[child]){
 		 	 	q.push(child);
 		 	 	dist[child]=dist[parent]+1;
 		 	 	visited[child]=1;
 		 	}
 		}
 	}

}

int main(){
 	int n;
 	cin>>n;

 	char arr[n][n];
 	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		 	 cin>>arr[i][j];
		}
 	}
 	for(int i=0;i<n;i++){
 	 	for(int j=0;j<n;j++){
 	 		if(arr[i][j]=='P' || arr[i][j]=='S' || arr[i][j]=='E'){
 	 		 	if(i>0 && (arr[i-1][j]=='P' || arr[i-1][j]=='S' || arr[i-1][j]=='E') )	v[n*i+j].push_back(n*(i-1)+j);
 	 		 	if(i<n-1 && (arr[i+1][j]=='P' || arr[i+1][j]=='S' || arr[i+1][j]=='E') )	v[n*i+j].push_back(n*(i+1)+j);
 	 		 	if(j>0 && (arr[i][j-1]=='P' || arr[i][j-1]=='S' || arr[i][j-1]=='E') )	v[n*i+j].push_back(n*i+j-1); 
 	 		 	if(j<n-1 && (arr[i][j+1]=='P' || arr[i][j+1]=='S' || arr[i][j+1]=='E') )  v[n*i+j].push_back(n*i+j+1);
 	 		}
 	 	 	if(arr[i][j]=='S'){
 	 	 		start = n*i + j;
 	 		}

 	 		if(arr[i][j]=='E'){
 	 	 		finish = n*i + j;
 	 		}
 	 	}
 	}

 	bfs(start);
  	cout<<dist[finish]<<endl;
}
*/