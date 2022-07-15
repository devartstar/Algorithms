


const int INF = 1e9 + 7;

int Solution::jump(vector<int> &A) {
	int n = (int)A.size();
	vector<int> dp(n+1, INF);
    // dp[i] => minimum number of moves to reach to index - i
    fot(int i = 0; i < n; i++) {		
		for(int jump = 1; jump <= A; jump++) {
			if(i + jump < n)
				dp[i + jump] = min(dp[i + jump], dp[i] + 1)
		}
	}
	return dp[n];
}