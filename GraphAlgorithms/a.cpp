#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, n1, fd, c = 0;
    cin >> n;
    n1 = n;
    long long ans = 0;

    while (n1 > 0)
    {
        c++;
        if (n1 < 10)
        {
            fd = n1 % 10;
        }
        n1 /= 10;
    }
    ans += fd;
    int num = 0;
    for (int i = 0; i < c; i++)
    {
        num = num * 10 + fd;
    }

    ans += 9 * (c - 1);

    if (num <= n)
    {
        ans++;
    }

    cout << ans - 1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}