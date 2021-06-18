/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 11.06.2021 			|
	|	Time   - 13:07:58				|	
	|									|
	-------------------------------------
	
	Link - https://codeforces.com/contest/1538/problem/B
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


void solve() {
	int n;
	cin>>n;
	vi v(n);
	ll s=0;
	f0(i,n){
		cin>>v[i];
		s+=v[i];
	}
	if(s%n!=0){
		cout<<-1<<"\n";
		return;
	}
	s/=n;
	int ans=0;
	f0(i,n){
		v[i]=v[i]-s;
		if(v[i]>0)	ans++;
	}
	cout<<ans<<endl;
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