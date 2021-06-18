// ACCEPTED CODE

#include <bits/stdc++.h>
using namespace std;

int main(){
	long long t;
	cin>>t;
	while(t--){
		long long a,b;
		cin>>a>>b;
		//k1=1 k2=i k3=b-i
		if(b==1){
			cout<<"NO"<<endl;
		}
		else if(b==2){
			cout<<"YES"<<endl;
		    cout<<a<<" "<<2*a*b - a<<" "<<a*b*2<<"\n";
		}
		if(b>2){
			cout<<"YES"<<endl;
			cout<<a<<" "<<a*b-a<<" "<<a*b<<"\n";
			/*
			bool ans = false;
			for(int i=1;i<b;i++){
				if(i!=b-i){
					cout<<"YES"<<"\n";
					cout<<a*i<<" "<<a*(b-i)<<" "<<a*b<<"\n";
					ans=true;
					break; 
				}
	 		}
	 		*/
		}
		/*			
	 	if(!ans){
	 		cout<<"NO"<<endl;
	 	}
	 	*/
	}
}