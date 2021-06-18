/*
	17 - 8 - 4 - 2 - 1 - 0
	21 - 10 - 5 - 2 - 1 - 0

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


ll powerRecursive(int a, int b){
	if(b==0)
		return 1;
	int temp = powerRecursive(a,b/2);
	int result = (temp*temp) % INF;
	if(b&1)
		result*=a;
	return result;				
}

ll powerIterative(int a, int b){
	int result = 1;
	while(b>0){
		if(b&1)	result*=a;
		// basically if last bit of b is  1 then result = result + pow(a,position of b) 
		a = (a*a) % INF;
		b/=2;	// b/=2 removes the last bit of b
	}
	return result;
}

void solve() {
	ll x,y;
	cin>>x>>y;
	/*
	//	!!! Recursive Binary Exponentiation
	ll res1 = powerRecursive(x,y);
	cout<<res1<<endl;
	*/
	
	//  !!!	Iterative Binary Exponentiation
	ll res2 = powerIterative(x,y);
	cout<<res2<<endl;
	
	
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