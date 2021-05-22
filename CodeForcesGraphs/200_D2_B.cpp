/*         ACCEPTED
  	https://codeforces.com/problemset/problem/344/B
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define f0(i, n) for (int i = 0; i < n; i++) // 0 based indexing
#define f1(i, n) for (int i = 1; i <= n; i++) // 1 based indexing
#define f(i, a, b) for (int i = a; i <= b; i++) // 1 based indexing
#define pb push_back
#define fi first
#define se second


const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int x,y,z;
int a,b,c;

bool case1(){	//for x
	int l1 = (x+y-z)/2;
	int l2 = (x+z-y)/2;
	if((x+z-y)%2==0 && (x+y-z)%2==0 && l1>0 && l2>0 && y-l1>=0){
		a=l1;	// between x and y
		c=l2;	// between x and z
		b=y-l1;	// between y and z
		return true;	
	}
	return false;
}

bool case2(){ 	// for y
	int l1 = (y+x-z)/2;
	int l2 = (y+z-x)/2;
	if((y+z-x)%2==0 && (x+y-z)%2==0 && l1>0 && l2>0 && x-l1>=0){
		a=l1;	// between x and y
		c=x-l1;	// between x and z
		b=l2;	// between y and z
		return true;	
	}
	return false;
}

bool case3(){   // for z
	int l1 = (z+y-x)/2;
	int l2 = (z+x-y)/2;
	if((x+z-y)%2==0 && (z+y-x)%2==0 && l1>0 && l2>0 && y-l1>=0){
		a=y-l1;	// between x and y
		c=l2;	// between x and z
		b=l1;	// between y and z
		return true;	
	}
	return false;
}


void solve() {
 	cin>>x>>y>>z;
 	
 	if(case1()){
 		//print ans
 		cout<<a<<" "<<b<<" "<<c<<endl;
 		return;
 	}
 	if(case2()){
 		//pritn ans
 		cout<<a<<" "<<b<<" "<<c<<endl;
 		return;
 	}
 	if(case3()){
 		//print ans
 		cout<<a<<" "<<b<<" "<<c<<endl;
 		return;
 	}

 	cout<<"Impossible"<<endl;
 	return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}