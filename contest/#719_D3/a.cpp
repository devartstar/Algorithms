#include <bits/stdc++.h>
using namespace std;

bool solve(){

	 	int n;string s;
	 	cin>>n>>s;
	 	string s1="";
		s1+=s[0];	 	             	
	 	for(int i=1;i<(int)s.length();i++){
	 	 	if(s[i]!=s[i-1]){
	 	 	 	if(s1.find(s[i])!=string::npos){
	 	 	 	 	return false;
	 	 	 	}
	 	 	}
	 	 	s1+=s[i];
	 	}
	 	return true;	
}

int main(){
	int t;
	cin>>t;                    
	while(t--){     
		if(solve()){
		 	cout<<"YES"<<endl;
		}else{
            cout<<"NO"<<endl;
        }
	}
}	
