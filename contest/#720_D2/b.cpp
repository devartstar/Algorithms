// ACCEPTED SOLUTION
// Only works when we do not have to minimize the numebr of the moves
/*
Logic -
	for a given input - consider
	{a1,a2,a3,a4,a5,a6} - min = a2, min_pos=2
	the final array
	{a2+1,a2,a2+1,a2+2,a2+3,a2+4}
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
 	long long n;
 	cin>>n;
 	vector<int> v(n);
 	long long min=1e9+1,min_pos;
 	for(long long i=0;i<n;i++){
 	 	cin>>v[i];
 	 	if(v[i]<min){
 	 	 	min=v[i];
 	 	 	min_pos=i;
 	 	}
 	}
    cout<<n-1<<endl;
	for(long long i=0;i<n;i++){
        if(i==min_pos)
            continue;
        cout<<min_pos+1<<" "<<i+1<<" "<<min<<" "<<min+abs(min_pos-i)<<"\n";
        //v[i]=min+abs(min_pos-i);

    }
	/*
    for(auto i : v){
     	cout<<i<<" ";
    }
    cout<<endl;
     */
}

int main(){
 	int t;
	cin>>t;
	while(t--){
	 	solve();
	}
}
              
