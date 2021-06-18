/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 08.06.2021 			|
	|	Time   - 20:17:39				|	
	|									|
	-------------------------------------
	
	Link - https://www.geeksforgeeks.org/fractional-knapsack-problem/
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

struct item{
	ll weight;
	ll value;
	double ratio;
};

bool comp(item a, item b){
	return a.ratio-b.ratio>=0;
}

void solve() {
	ll n,val;	// number of elements in the knapsack list
	cin>>n>>val;
	item v[n];
	f0(i,n){
		cin>>v[i].value>>v[i].weight;
		v[i].ratio = (double)v[i].value/(double)v[i].weight;
	}
	sort(v,v+n,comp);
	ll j=0;
	ll ans=0;
	while(val-v[j].weight>0){
		ans+=v[j].value;
		val-=v[j].weight;
		j++;
		//cout<<ans<<"\n";
	}
	ans+=(ll)(val)*v[j].ratio;
	cout<<ans<<"\n";
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