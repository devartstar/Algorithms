
#include <bits/stdc++.h>
using namespace std;

#define f0(i, n) for(int i = 0; i < n; i++)
#define f1(i, n) for(int i = 1; i <= n; i++)

void solve() {
	int n;
	cin >> n;
	vector<int> B(n);
	f0(i, n) cin>>B[i];
	if(is_sorted(B.begin(), B.end())) cout << "YES" << endl;
	else cout << "NO" << endl;
}



int main() {
	int t;
	// t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
}