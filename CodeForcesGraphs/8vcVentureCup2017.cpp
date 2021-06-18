<<<<<<< HEAD
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



=======
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



>>>>>>> f8b8a940c77db8a197b14ac8be0388e03d567e8c
