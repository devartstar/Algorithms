/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 11.06.2021 			|
	|	Time   - 18:46:14				|	
	|									|
	-------------------------------------
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

void solve()
{
	int n, l, r;
	cin >> n >> l >> r;
	vi v(n);
	f0(i, n) cin >> v[i];
	sort(v.begin(), v.end());
	int right = n - 1;
	while (v[right] > r)
		right--;
	int a = 0, ans = 0;
	while (right > a)
	{
		bool k = false;
		for (int left = a; left < right; left++)
		{
			if (v[left] + v[right] > r)
				break;
			if (v[left] + v[right] >= l)
			{
				cout << left << "," << right << "\n";
				if (!k)
				{
					a = left;
					k = true;
				}
				ans++;
			}
		}
		right--;
	}
	cout << ans << "\n";
}

void solve1()
{
	int n, l, r;
	cin >> n >> l >> r;
	vi v(n);
	f0(i, n) cin >> v[i];
	sort(v.begin(), v.end());
	int right = n - 1;
	while (v[right] > r)
		right--;
	int a = 0, b = 0, ans = 0;

	if (v[right] + v[right - 1] < l)
	{
		cout << 0 << "\n";
		return;
	}

	while (right > a)
	{

		for (int left = a; left < right; left++)
		{
			if (v[left] + v[right] > r)
				break;
			if (v[left] + v[right] >= l)
			{

				a = left;
				break;
			}
		}
		bool kr = false;
		if (b < right)
		{
			for (int j = b; j < right; j++)
			{
				if (v[j] + v[right] > r)
				{
					kr = true;
					b = j - 1;
					break;
				}
			}
		}

		if (!kr)
			b = right - 1;
		if (b == a)
		{
			if (v[right] + v[a] >= l && v[right] + v[a] <= r)
				ans++;
		}
		else
			ans += (b - a + 1);

		right--;
	}
	cout << ans << "\n";
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
		solve1();
	}
}