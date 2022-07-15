

#include <bits/stdc++.h>
using namespace std;

#define f0(i, n) for(int i = 0; i < n; i++)
#define ff first
#define ss second

void solve() {
    int n;
	cin >> n;
	string s;
	cin>>s;
	vector<int> v(n), parent(n);
	f0(i, n) {
		cin>>v[i];
		parent[v[i] - 1] = i;
	}
	vector<int> visited(n, 0), aa;
	f0(i, n) {
		if(visited[i]) continue;
		string temp;
		visited[i] = 1;
		temp += s[i];
		int next = parent[i];
		while(next != i) {
			temp += s[next];
			visited[next] = 1;
			next = parent[next];
		}
		// temp -> all characters that will come to pos 1
		
		string pre = temp;
		f0(i, temp.length()) {
			rotate(temp.rbegin(), temp.rbegin()+1, temp.rend());
			// move all 1 place right
			if(temp == pre) {
				aa.push_back(i+1);
				break;
			}
		}
	}
	long long ans = aa[0];
	f0(i, aa.size()) {
		ans = (1ll * ans * aa[i]) / __gcd(ans, aa[i] * 1ll);
	}
	cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}










