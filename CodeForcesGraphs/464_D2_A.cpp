<<<<<<< HEAD
/*       **** ACCEPTED *****
  	ith plane loves fi
  	make a graph with directed edge between i--->fi
  	if a cycle of edge 3 exists --- yes or no
*/


#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a;
	cin>>n;
	vector<int> love;
	bool ans=false;	
	love.push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a;
		love.push_back(a);			 	
	}
	for(int i=1;i<=n;i++){
		// following is love triangle between --- i--->x--->y
	 	int x = love[i];
	 	int y = love[x];
	 	int z = love[y];
	 	if(i!=x && i!=y && x!=y && i==z){
	 		cout<<"YES"<<endl;
	 		ans=true;
	 		break;
	   }
	}
	if(!ans){
	 	cout<<"NO"<<endl;
	}
}

                   
=======
/*       **** ACCEPTED *****
  	ith plane loves fi
  	make a graph with directed edge between i--->fi
  	if a cycle of edge 3 exists --- yes or no
*/


#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a;
	cin>>n;
	vector<int> love;
	bool ans=false;	
	love.push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a;
		love.push_back(a);			 	
	}
	for(int i=1;i<=n;i++){
		// following is love triangle between --- i--->x--->y
	 	int x = love[i];
	 	int y = love[x];
	 	int z = love[y];
	 	if(i!=x && i!=y && x!=y && i==z){
	 		cout<<"YES"<<endl;
	 		ans=true;
	 		break;
	   }
	}
	if(!ans){
	 	cout<<"NO"<<endl;
	}
}

                   
>>>>>>> f8b8a940c77db8a197b14ac8be0388e03d567e8c
