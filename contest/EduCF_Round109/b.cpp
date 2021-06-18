/*
		!!! ACCEPTED
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

/*
	FIND min number of operations to sort the given array
	min is always <=3
	!!! rearrange the elements in it in any way you want.
	min = 0 -> Already sorted
	min = 1 -> First or last or both element is in place
	min = 2 -> Both first and last element out of place
	min = 3 -> first element in last and last element in first
*/

void solve() {
	int n;
	cin>>n;
	vi v(n);
	f0(i,n)
		cin>>v[i];
	if(is_sorted(v.begin(),v.end())){
		cout<<0<<"\n";
		return;
	}
	if(v[0]==n && v[n-1]==1){
		cout<<3<<"\n";
		return;
	}
	if(v[0]==1 || v[n-1]==n){
		cout<<1<<"\n";
		return;
	}
	if(v[0]!=1 && v[n-1]!=n){
		cout<<2<<"\n";
		return;
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}