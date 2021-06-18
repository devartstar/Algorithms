/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 13.06.2021 			|
	|	Time   - 11:32:56				|	
	|									|
	-------------------------------------
	
	Link - https://codeforces.com/problemset/problem/1335/C
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
	set<int> s;
	vi v(n);
	f0(i,n){
		cin>>v[i];
		s.insert(v[i]);
	}
	int n_distinct = (int)s.size();
	sort(all(v));
	int max_same=0;
	for(int it: s){
		auto a = lower_bound(all(v),it);
		auto b = upper_bound(all(v),it);
		//cout<<it<<" "<<a-v.begin()<<"  "<<b-v.begin()<<"\n";
		max_same=max(max_same, b-a);
	}
	//cout<<"lol"<<n_distinct<<","<<max_same<<"\n";
	int ans = max(min(n_distinct,max_same-1), min(n_distinct-1, max_same));
	cout<<ans<<"\n";
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