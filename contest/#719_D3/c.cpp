#include <bits/stdc++.h>
using namespace std;

void solve(){
 	int n;
 	cin>>n;
 	if(n==2){
 	 	cout<<"-1"<<endl;
 	 	return;
 	}
 	if(n==1){
 		cout<<"1"<<endl;
 		return;
 	}	
 	int c=1;
 	int arr[n][n];
 	for(int k=0;k<=2*(n-1);k++){
 		for(int y=0; y<n; y++){
 			int x = k-y;
 			if(x<0 || x>=n){
  				continue;
 			}else{
 				arr[y][x]=c;
 				c++;
 			}	
 		}
 	}

 	swap(arr[0][0],arr[n-1][n-1]);

 	for(int i=0;i<n;i++){
 	 	for(int j=0;j<n;j++){
 	 	 	cout<<arr[i][j]<<" ";
 	 	}
 	 	cout<<endl;
 	}

}

int main(){
	int t;
	cin>>t;
	while(t--){
	 	solve();
	}
}	