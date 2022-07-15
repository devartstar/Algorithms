
#include <bits/stdc++.h>
using namespace std;

#define f0(i, n) for(int i = 0; i < n; i++)
#define f1(i, n) for(int i = 1; i <= n; i++)
#define ll long long

string right_rotate1(string s) {
    int len = (int)s.length();
    char ch = s[len-1];
    s.erase(len-1, 1);
    string res = "";
    res += ch;
    res += s;
    return res;
}

void solve() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v(n), pos(n);
	f0(i, n) {
		cin>>v[i];
		pos[v[i]-1] = i;
	}
	vector<ll> visited(n, 0);
	vector<ll> rotations;
	f0(i, n) {
		if(visited[i]) continue;
		string temp = "";
		temp += s[i];
		visited[i] = 1;
		int next = pos[i];
		while(next != i) {
			temp += s[next];
			visited[next] = 1;
			next = pos[next];
		}
		string copy = temp;
		string ss = right_rotate1(copy);
		int cnt = 1;
		while(ss != copy) {
		    cnt++;
		    ss = right_rotate1(ss);
		}
		rotations.push_back(cnt);
	}
	ll ans = rotations[0];
	f0(i, (int)rotations.size()) {
		ans = (ans * rotations[i]) / __gcd(ans, rotations[i]);
	}
	cout<<ans<<endl;
}



int main() {
	int t;
	// t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
}



