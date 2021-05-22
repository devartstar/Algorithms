/*
  	for cyclic graph there cant be any topological sort
  	following code works for Acyclic, Directed Graph
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int visited[100001];
int in[100001]={0};
vector<int> ans;
int n;

void khan(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			q.push(i);
		}
	}                          
	while(!q.empty()){
		int node = q.front();
		ans.push_back(node);
		q.pop();

		for(int child : v[node]){
		 	in[child]--;
		 	if(in[child]==0){
		 	 	q.push(child);
		 	}
	 	}
	}
}

int main(){
 	int m,a,b;
 	cin>>n>>m;
 	for(int i=0;i<m;i++){
		cin>>a>>b;
		v[a].push_back(b);		// a direcred edge from a to b, a ----> b
		in[b]++;
 	}

 	khan();

 	for(auto i : ans){
 		cout<<i<<" ";
 	}
 	cout<<endl;
}