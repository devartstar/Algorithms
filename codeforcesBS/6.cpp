/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 13.06.2021 			|
	|	Time   - 04:25:42				|	
	|									|
	-------------------------------------
	
	Link - https://codeforces.com/problemset/problem/978/C
*/

#include <bits/stdc++.h>
using namespace std;
 
#define ar array
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<long, long>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define all(v) v.begin(),v.end()
#define f0(i, n) for (int i = 0; i < n; i++) // 0 based indexing
#define f1(i, n) for (int i = 1; i <= n; i++) // 1 based indexing
#define f(i, a, b) for (int i = a; i <= b; i++) // 1 based indexing
#define fll0(i, n) for (long long i = 0; i < n; i++) // 0 based indexing
#define fll1(i, n) for (long long i = 1; i <= n; i++) // 1 based indexing
#define fll(i, a, b) for (long long i = a; i <= b; i++) // 1 based indexing
#define pb push_back
#define fi first
#define se second
 
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll n,m;
vll v;
 
ll findPosition(ll x){
	ll left = 0, right = n-1;
	ll ans=-1;
	while(left<=right){
		ll mid = left+(right-left)/2;
		if(v[mid]<x){
			ans=mid;
			left=mid+1;
		}else
			right=mid-1;
	}
	return ans+1;
}
 

void solve() {
	ll sum=0;
	cin>>n>>m;
	vll a(n);
	v.resize(n);
	for(ll i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		v[i]=sum;
	}
	f0(i,m){
		ll x;
		cin>>x;
		ll ans = findPosition(x);
		if(ans==0)	cout<<1<<" "<<x<<"\n";
		else	cout<<ans+1<<" " <<x-v[ans-1]<<"\n";
	}
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


