/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - ___curd___ 			|
	|	Time   - __curt__				|	
	|									|
	-------------------------------------
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
	ll b,c,f,p2,p1;
	cin>>b>>f>>c>>p1>>p2;
	ll ans=0;
	ll bun=b/2;
	if(bun>=c+f)
		ans+=c*p2+f*p1;
	else if(p2>p1)
	{
		if(bun>c)
		{
			ans+=c*p2;
			bun=bun-c;
		}
		else
		{
			ans+=bun*p2;
			bun=0;
		}
		if(bun>f)
			ans+=f*p1;
		else ans+=bun*p1;
	}
	else
	{
		if(bun>f)
		{
			ans+=f*p1;
			bun=bun-f;
		}
		else
		{
			ans+=bun*p1;
			bun=0;
		}
		if(bun>c)
			ans+=c*p2;
		else 
			ans+=bun*p2;
	}
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