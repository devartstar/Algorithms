/*		SOCIAL NETWORKING GRAPH
	
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int visited[100001];
int dist[100001];
int level[100001];

void bfs(int src){
	visited[src]=1;  
	dist[src] = 0;
	queue<int> q;
	q.push(src);

	while(!q.empty()){
	 	int parent = q.front();
	 	q.pop();

	 	for(int child : v[parent]){
	 	 	if(!visited[child]){
	 	 		dist[child] = dist[parent] + 1;
	 	 		visited[child] = 1;
	 	 		q.push(child); 	
	 	 		level[dist[child]]++;
	 	 	}
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

 	int t;
 	cin>>t;
 	while(t--){
 	 	int src,d;
 	 	cin>>src>>d;
 	 	for(int i=0;i<=n;i++){
 	 	 	level[i]=0;
 	 	 	visited[i]=0;    
   	 	}

 		bfs(src);

 		cout<<level[d]<<endl;
               
    }

}
