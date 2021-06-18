/*
	Ques : Random Mood
			Mood flips with probability (p) at every minute
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

int **multiply(int a[][2], int b[][2]){
	int **product;
	int product[2][2] = {{0,0},{0,0}};
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				product[i][j] += a[i][k]*b[k][j];
	return product;				
}

int **expo_power(int a[][2], int n){
	int result =  {{1,0},{0,1}};
	whiel(n>0){
		if(n&1) 	
			result  = multiply(result,a);
		n/=2;
		a = multiply(a,a);
	}
	return result;	
}


void solve() {
	int n;
	cin>>n;
	int a[2][2] = {{19,7},{6,20}};
	int** result = expo_power(a,n);
	cout<<result[0][0]<<endl;
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