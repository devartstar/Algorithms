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

struct Matrix {
	int a[2][2] = {{0,0},{0,0}};
	Matrix operator *(const Matrix& other){
		Matrix product;
		f0(i,2)
			f0(j,2)
				f0(k,2)
					product.a[i][j] = (product.a[i][j] + (long long)a[i][k]*other.a[k][j]) % MOD;
		return product;
	};
};

Matrix expo_power(Matrix a, int k){
	Matrix product;
	f0(i,2)
		product.a[i][i]=1;
	while(k>0){
		if(k&1)
			product = product * a;
		a = a*a;
		k/=2;
	}
	return product;
}


void solve() {
	int n;
	cin>>n;
	Matrix single;
	single.a[0][0] = 19;
	single.a[0][1] = 7;
	single.a[1][0] = 6;
	single.a[1][1] = 20;
	Matrix total = expo_power(single,n);
	cout<<total.a[0][0]<<endl;
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