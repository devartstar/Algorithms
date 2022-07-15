vector<vector<int>> dp(500, vector<int>(500, -1));

int rec(int i, int j, string str1, string str2) {
  if (i == 0) {
    return j;
  }
  if (j == 0) {
    return i;
  }
  
  int ans = 1 + min({
    rec(i, j - 1, str1, str2), // Insert
    rec(i - 1, j, str1, str2), // Remove
    rec(i - 1, j - 1, str1, str2) // Replace
  });
 
  if (str1[i - 1] == str2[j - 1]) {
    ans = min(ans, rec(i - 1, j - 1, str1, str2));
  }
  return ans;
}
 
int editDistance(string str1, string str2) {
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 500; j++) {
			dp[i][j] = -1;
		}
	}
	int n = str1.length() + 1, m = str2.length() + 1;
	int ans = rec(n, m, str1, str2);
	return ans;
}