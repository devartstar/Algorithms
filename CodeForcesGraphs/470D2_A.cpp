#include<bits/stdc++.h>
using namespace std;

char arr[501][501];
int r,c,cnt=0;

bool isValid(int x,int y){
 	if(x>=0 && x<r && y>=0 && y<c)	
 		return true;
 	else 
 		return false;
}

bool solve(){
 	for(int i=0;i<r;i++){
 	 	for(int j=0;j<c;j++){
 	 	 	if(arr[i][j]=='S'){
				if(isValid(i-1,j)){
					if(arr[i-1][j]=='W')	
						return false;
					if(arr[i-1][j]=='.'){
						arr[i-1][j]='D';						
						cnt++;
					}
 	 	 		}
 	 	 		if(isValid(i+1,j)){
					if(arr[i+1][j]=='W')	
						return false;
					if(arr[i+1][j]=='.'){
						arr[i+1][j]='D';
						cnt++;
					}
 	 	 		}
 	 	 		if(isValid(i,j-1)){
					if(arr[i][j-1]=='W')	
						return false;
					if(arr[i][j-1]=='.'){
						arr[i][j-1]='D';
						cnt++;
					}
 	 	 		}
 	 	 		if(isValid(i,j+1)){
					if(arr[i][j+1]=='W')	
						return false;
					if(arr[i][j+1]=='.'){
						arr[i][j+1]='D';
						cnt++;
				    }
 	 	 		}
 	 	 	}
 	 	}
 	}
 	return true;
}

int main(){
	string s;
	cin>>r>>c;
	for(int i=0;i<r;i++){
		cin>>s;
	 	for(int j=0;j<c;j++){
			arr[i][j]=s[j];	 	 	
	 	}
	}

	if(solve()){
		cout<<"Yes"<<endl;
		for(int i=0;i<r;i++){
		 	for(int j=0;j<c;j++){
				cout<<arr[i][j];	 	 	
	 		}
	 		cout<<endl;	
		} 	
	}else{
	 	cout<<"No"<<endl;
	}

}