/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 11.06.2021 			|
	|	Time   - 19:49:04				|	
	|									|
	-------------------------------------
	
	Link - https://codeforces.com/contest/1538/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<long, long>
#define vll vector<long long>
#define vpii vector<pair<int, int>>
#define all(v) v.begin(), v.end()
#define f0(i, n) for (int i = 0; i < n; i++)			// 0 based indexing
#define f1(i, n) for (int i = 1; i <= n; i++)			// 1 based indexing
#define f(i, a, b) for (int i = a; i <= b; i++)			// 1 based indexing
#define fll0(i, n) for (long long i = 0; i < n; i++)	// 0 based indexing
#define fll1(i, n) for (long long i = 1; i <= n; i++)	// 1 based indexing
#define fll(i, a, b) for (long long i = a; i <= b; i++) // 1 based indexing
#define pb push_back
#define fi first
#define se second

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, l, r;
vi v;

ll calc(int x)
{
	ll ans = 0;
	for (int i = 0, j = n - 1; i < j; i++)
	{
		while (i < j && v[i] + v[j] > x)
		{
			// CASE 1 - increase the left pointer by 1 and get the right pointer
			//			- taken care by outer for loop

			// CASE 2 - decrease the right pointer by 1 and get the left pointer
			j--;
		}
		ans += (max(j - i, 0));
	}
	return ans;
}

void solve()
{

	cin >> n >> l >> r;
	v.resize(n);
	f0(i, n) cin >> v[i];
	sort(v.begin(), v.end());
	cout << calc(r) - calc(l - 1) << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc = 1;
	cin >> tc;
	f1(t, tc)
	{
		// cout << "Case #" << t  << ": ";
		solve();
	}
}