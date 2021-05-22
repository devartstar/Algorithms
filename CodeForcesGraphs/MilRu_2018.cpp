/*
  	https://codeforces.com/problemset/problem/1055/A
*/
#include <bits/stdc++.h>
using namespace std;

int n,s;
vector<int> f;
vector<int> r;
vector<int> v[100001];
int visited[100001]={0};

//Directed Graph

void makeGraph(){
	for(int i=0;i<n;i++){
		if(f[i]==1)
			for(int j=i+1;j<n;j++){
				if(f[j]==1)
					v[i].push_back(j);
			}
	}
	for(int i=n-1;i>=0;i--){
		if(r[i]==1)
			for(int j=i-1;j>=0;j--){
				if(r[j]==1)
					v[i].push_back(j);
			}
	}
}

void dfs(int node){
	visited[node]=1;
	for(int child : v[node]){
		if(!visited[child]){
			dfs(child);
		}
	}
}

int main(){
	int a;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		cin>>a;
		f.push_back(a);
	}
	for(int i=0;i<n;i++){
		cin>>a;
		r.push_back(a);
	}
	
	makeGraph();
	dfs(0);

	if(visited[s-1]){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}	
}