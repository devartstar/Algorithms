/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 17.06.2021 			|
	|	Time   - 10:30:24				|	
	|									|
	-------------------------------------
	
	Link - https://codeforces.com/gym/332778/problem/D
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

ll fact(int n){
	ll fact=1;
	f1(i,n){
		fact*=i;
		fact=fact%998244353;
	}
	return fact;
}

void solve() {
	int n;
	cin>>n;
	vpii v(n);
	f0(i,n){
		cin>>v[i].first>>v[i].second;
	}
	map<int,int> m1;
	map<int,int> m2;
	map<pii, int> m3;
	
	//	counted the frequency of repetition of every element
	f0(i,n){
		m1[v[i].first]++;
		m2[v[i].second]++;
		m3[make_pair(v[i].first,v[i].second)]++;
		/*
		for(auto& a : m1)	cout<<a.first<<"-"<<a.second<<" ";
		cout<<"\n";
		for(auto& a : m2)	cout<<a.first<<"-"<<a.second<<" ";
		cout<<"\n";
		*/
	}
	ll ans = fact(n);
	ll c1=1,c2=1,c3=1;
	for(auto a : m1)	c1*=fact(a.second);
	for(auto a : m2)	c2*=fact(a.second);
	for(auto a : m3)	c3*=fact(a.second);
	/*
	for(auto& a : m1)	cout<<a.first<<"-"<<a.second<<" ";
	cout<<"\n";
	for(auto& a : m2)	cout<<a.first<<"-"<<a.second<<" ";
	cout<<"\n";

	
	cout<<ans<<" "<<c1<<" "<<c2<<" "<<c3<<"\n";
	*/	
	cout<<(ans-c1-c2+c3)%998244353<<"\n";
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