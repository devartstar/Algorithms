#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		long long n, m;
		cin >> n >> m;
		long long val = (m * (m + 1)) / 2 + m * ((n * (n + 1)) / 2 - 1);
		cout << val << endl;
	}
}
