/*
  	Given m relations between numbers from 1 to n 
  	Find if they are feasible realtions or not
  	5 5
  	1 =  2
  	3 =  1
  	4 != 2
  	5 =  4
  	3 != 5
  	Output : Feasible
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int visited[10001];
int cc[100001];
int curr_cc;

void dfs(int node){
 	visited[node]=1;
 	cc[node]=curr_cc;

 	for(int child : v[node]){
 	 	if(!visited[child]){
 	 	 	dfs(child);
 	 	}
 	}
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,a,b;
		string op;
		cin>>n>>m;
		vector<pair<int,int>> unequal;
		for(int i=0;i<n;i++){
			v[i].clear();
		 	visited[i]=0;
			cc[i]=0;		 	             	
		}
		for(int i=0;i<m;i++){
			cin>>a>>op>>b;		
			if(op == "="){
			 	v[a].push_back(b);
			 	v[b].push_back(a);
			}else{
			 	unequal.push_back({a,b});
            }         
		}
		curr_cc=0;
		for(int i=0;i<=n;i++){
			if(!visited[i]){
				curr_cc++;
				dfs(i);
			}
		}

		bool ans =true;
		for(auto it = unequal.begin(); it!=unequal.end(); it++){
		 	if(cc[it->first] == cc[it->second]){
				ans=false;				
		 	}
		}
		if(ans){
		 	cout<<"Feasible"<<endl;
		}else{
		 	cout<<"Infeasible"<<endl;
		}
	}   
}
