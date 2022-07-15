#include <bits/stdc++.h>
using namespace std;

#define f0(i, n) for(int i = 0; i < n; i++)

void solve() {
    int n, k;
    cin>>n>>k;
    string s; 
	cin >> s;
    vector<int> presum(n, 0);
    f0(i, n) {
        if(s[i] == 'W') presum[i] = 1;
        if(i > 0) presum[i] += presum[i-1];
    }
    int val = presum[k-1];
    for(int i = k; i < n; i++) {
        val = min(val, presum[i] - presum[i-k]);
    }
    cout << val <<end;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}