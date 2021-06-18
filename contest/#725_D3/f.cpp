/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 11.06.2021 			|
	|	Time   - 21:19:12				|	
	|									|
	-------------------------------------
	
	Link - https://codeforces.com/contest/1538/problem/F
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
#define f0(i, n) for (int i = 0; i < n; i++)            // 0 based indexing
#define f1(i, n) for (int i = 1; i <= n; i++)           // 1 based indexing
#define f(i, a, b) for (int i = a; i <= b; i++)         // 1 based indexing
#define fll0(i, n) for (long long i = 0; i < n; i++)    // 0 based indexing
#define fll1(i, n) for (long long i = 1; i <= n; i++)   // 1 based indexing
#define fll(i, a, b) for (long long i = a; i <= b; i++) // 1 based indexing
#define pb push_back
#define fi first
#define se second

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve()
{
    ll a, b;
    cin >> a >> b;
    ll dp[11];
    ll val = 1;
    f0(i, 11)
    {
        dp[i] = (b / val) - (a / val);
        val = val * 10;
    }
    // f0(i, 11)
    //         cout
    //     << dp[i] << " ";
    // cout << "\n";
    // ll sum = dp[10];
    // for (int i = 9; i >= 0; i--)
    // {
    //     dp[i] -= sum;
    //     sum += dp[i];
    // }
    ll ans = 0;
    f0(i, 11)
    {
        ans += dp[i];
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
        solve();
    }
}

// LOGIC -
/*
	1,11
	1,2,3,4,5,6,7,8,9,10,11
	11/10^1 - 1/10^1 = 1*2
	11/10^0 - 1*10^0 = (11-1)*1 - (dp[1])
	2+10 



    1 - 131
    1,2,3,
    99 -> 100 = 3
    //ans+= 1*3

    //-----
    9->10 = 2
    19->20 = 2
    29->30 = 2
    .
    .
    .
    89->90 = 2
    109->110 = 
    119->120
    129->130
    // ans+= 13*2

    // ans+= 130*1

    130 13 1
    117 12 1
    116 12 1

    489999 -> 490000
    1



    1-1000000000
      1000000000


    1111111110
    1111111110
    1111111110
*/
