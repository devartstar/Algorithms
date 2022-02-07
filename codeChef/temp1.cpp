#include <bits/stdc++.h>

using namespace std;

const int MX = 5000;

char a[MX + 1], b[MX + 1];
int f[MX + 1][MX + 1], g[MX + 1][MX + 1];

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n, m;
		ignore = scanf("%d %d %s %s", &n, &m, a, b);
        int dp[n+1][m+1][2];
        for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++) dp[i][j][0] = dp[i][j][1] = 3*MX;

		
		dp[0][1][1] = dp[1][0][0] = 1;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++) {
				if (i < n) {
					if (i > 0) dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][0] + (a[i - 1] != a[i]));
					if (j > 0) dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][1] + (b[j - 1] != a[i]));
				}
				
				if (j < m) {
					if (i > 0) dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][0] + (a[i - 1] != b[j]));
					if (j > 0) dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][1] + (b[j - 1] != b[j]));
				}
			}
		
		printf("%d\n", min(dp[n][m][0], dp[n][m][1]));
	}
	
	return 0;
}