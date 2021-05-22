/*
  	M ---> GIVEN
  	FIND COUNTER EXAMPLE N such that N.M+1 is not prime


*/

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
 	int i=2;
 	while(i*i<=n){
 		if(n%i==0)	return false;
 		i++;
 	}
 	return true;
}

int main(){
 	int n;
 	cin>>n;
 	for(int i=2;i<10000;i++){
 		if(isPrime(i))	continue;
 	 	if((i-1)%n==0){
 	 		cout<<(i-1)/n<<endl;
 	 		break;
 	 	}
 	}
}



