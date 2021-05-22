/*
	https://codeforces.com/problemset/problem/417/C  	
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int n,m;
int win[10001]={0};

void makeGraph(){

	for(int i=1;i<n;i++){
	 	for(int j=i+1;j<=n;j++){
	 	 	if(win[i]<m){
	 	 	 	v[j].push_back(i);
	 	 	 	win[i]++;
	 	 	}
	 	 	else{
	 	 		if(win[j]<m){
					v[i].push_back(j);
					win[j]++;
				}
			}
	 	}
	}

}

void displayGraph(){
 	for(int i=1;i<=n;i++){
 	 	for(int node : v[i]){
 	 	 	cout<<node<<" "<<i<<endl;
 	 	}
 	}
}

int main(){
	cin>>n>>m;
	long long N = n*(n-1)/2;
	if(m*n>N){
		cout<<-1<<endl;
	}else{
		makeGraph();
		/*
		for(int i=1;i<=n;i++){
		 	for(int j : v[i]){
		 		cout<<j<<" ";
		 	}
		 	cout<<endl;
		}
		*/
		cout<<N<<endl;
		displayGraph();
	}
}
