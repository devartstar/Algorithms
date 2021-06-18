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
const ll INF = 998244353;

void solve() {
	int n;
	cin>>n;
	vpii v(n);
	f0(i,n){
		cin>>v[i].first>>v[i].second;
	}
	int f[n];
	f[0] = 1;
    for(int i = 1; i < n; ++i)
        f[i] = (i*f[i-1])%INF;

    int res = f[n];
    for(int c = 0; c < 2; ++c){
        int d = 1;
        sort(all(v));
        int l = 0;
        while(l < n){
            int r = l + 1;
            while(r < n && v[l].first == v[r].first) ++r;
            d = (d*f[r-l])%INF;
            l = r;
        }
        res = (res+ INF - d)%INF;
        for(int i = 0; i < n; ++i) 
            swap(v[i].first, v[i].second);
    } 

	sort(all(v));
    int l = 0;
    int d = 1;
    while(l < n){
        int r = l + 1;
        while(r < n && v[l].first == v[r].first) ++r;
        map<int, int> m;
        for(int i = l; i < r; ++i) ++m[v[i].second];
        for(auto p : m) d = d*f[p.second]%INF;
        l = r;
    }
    for(int i = 1; i < n; ++i) 
        if(v[i - 1].second > v[i].second) 
        	d = 0;

	cout<<(res+d)%INF<<"\n";
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