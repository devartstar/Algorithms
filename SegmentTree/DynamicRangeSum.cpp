#include <bits/stdc++.h>
using namespace std;

vector<long long> tree;

long long f(int node,int node_low, int node_high, int query_low, int query_high){
 	if(query_low<=node_low && query_high>=node_high){
            return tree[node];
    }
	if(node_high<query_low || node_low>query_high){
            return 0;
    }
    int last_in_left = (node_low + node_high) / 2;
    return f(2*node,node_low,last_in_left,query_low,query_high) + f(2*node+1,last_in_left+1,node_high,query_low,query_high);
}

void update(int node){     
	for(int i=(node)/2; i>=1;i/=2){
	 	tree[i]=tree[2*i]+tree[2*i+1];
	}
}

void solve(){	
	int n,q;
 	cin>>n>>q;
	vector<long long> arr(n);
 	
	for(int i=0;i<n;i++){
	 	cin>>arr[i];
 	}
 	while(__builtin_popcount(n)!=1){
 		arr.push_back(0);
 		n++;
 	}
	
	tree.resize(2*n);
 	//form the tree
	//fill the tree indices from n to 2n
 	for(int i=0;i<n;i++){
 		tree[n+i]=arr[i];
 	}
	cout<<endl;
 	//fill the tree indices from n to 1
 	for(int i=n-1;i>=1;i--){
		tree[i]=tree[2*i]+tree[2*i+1]; 	 	
 	}
	
 	int opt,a,b;
 	while(q--){
		cin>>opt>>a>>b;               
		if(opt==1){
		 	a--;
			tree[n+a]=b;
			update(n+a);
		}else{
		 	a--;
		 	b--;
		 	cout<<f(1,0,n-1,a,b)<<"\n";
		}
		
 	}
}

int main(){
 	solve();
}