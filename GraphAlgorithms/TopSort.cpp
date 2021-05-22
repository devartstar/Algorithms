/*
	displaying the lexicographical top sort.
  	https://www.spoj.com/problems/TOPOSORT/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int visited[100001]={0};
int in[100001]={0};
vector<int> res;
int n,m;

bool khan(){
 	priority_queue<int, vector<int>, greater<int> > pq;
 	for(int i=1;i<=n;i++){
 	 	if(in[i]==0){
 	 	 	pq.push(i);
 	 	}
 	}
    while(!pq.empty()){
 		int node = pq.top();
	 	res.push_back(node);
 		pq.pop();
	 	for(int child : v[node]){
 		 	in[child]--;
	 	 	if(in[child]==0){
 	 	 		pq.push(child);
 	 		}
 		}
    }           
    return (int)res.size() == n ;
}

int main(){
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;		// job x to be done before y (x--->y)
		v[x].push_back(y);
		in[y]++; 	
	}

	if(!khan()){
		cout<<"Sandro Fails"<<endl;
	}else{
		for(int i : res){
		 	cout<<i<<" ";
	 	}
	 	cout<<endl;
	}
	
}