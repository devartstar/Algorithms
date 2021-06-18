/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 13.06.2021 			|
	|	Time   - 02:30:16				|	
	|									|
	-------------------------------------
	
	Link - https://codeforces.com/problemset/problem/1138/A
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

// Time - O(N) solution

void solve(){
	int n;
	cin>>n;
	vi v(n);
	vi v1;
	v1.pb(0);
	cin>>v[0];
	f1(i,n-1)	{
		cin>>v[i];
		if(v[i]!=v[i-1])
			v1.pb(i);
	}
	v1.pb(n);
	/*
	f0(i,(int)v1.size())	cout<<v1[i]<<" ";
	cout<<"\n";
	*/
	int ans=0;
	for(int i=1;i<(int)v1.size()-1;i++){
		ans=max(ans,min(v1[i+1]-v1[i],v1[i]-v1[i-1]));
	}
	cout<<2*ans<<"\n";

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