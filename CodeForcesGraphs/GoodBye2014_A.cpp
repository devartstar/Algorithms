<<<<<<< HEAD
/*
  	https://codeforces.com/contest/500/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
 	int a,b;
	cin>>a>>b;
	vector<int> v(a+1);
	for(int i=1;i<a;i++){
		cin>>v[i];
	}
	vector<int> visited;
	int i = 1; 
	while(i<a){
		visited.push_back(i);
		i=i+v[i];
	}     
	if(i==a){
		visited.push_back(i);
	}	         

	bool ans = false;
        for(int k : visited)         
	if(k==b){
	 	cout<<"Yes"<<endl;
		ans=true;
	}

	if(!ans){
	 	cout<<"No"<<endl;
	}


=======
/*
  	https://codeforces.com/contest/500/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
 	int a,b;
	cin>>a>>b;
	vector<int> v(a+1);
	for(int i=1;i<a;i++){
		cin>>v[i];
	}
	vector<int> visited;
	int i = 1; 
	while(i<a){
		visited.push_back(i);
		i=i+v[i];
	}     
	if(i==a){
		visited.push_back(i);
	}	         

	bool ans = false;
        for(int k : visited)         
	if(k==b){
	 	cout<<"Yes"<<endl;
		ans=true;
	}

	if(!ans){
	 	cout<<"No"<<endl;
	}


>>>>>>> f8b8a940c77db8a197b14ac8be0388e03d567e8c
}