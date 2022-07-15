#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		string ss = "";
		cin >> n >> s;
		if(s[0] != 9) {
			for (int i = 0; i < n; i++) {
				ss = char('0' + (9 - (s[i] - '0'))) + ss;
			}
		} else {
			bool ok = false;
			for (int i = n - 1; i >= 0; i--) {
				if(ok) {
					if(s[i] == '0')
						ss = '0' + ss, ok = false;
					else if(s[i] == '1')
						ss = char('0' + (10 - (s[i] - '0'))) + ss, ok = true;
					else
						ss = char('0' + (10 - (s[i] - '0'))) + ss, ok = true;
				} else {
					if(s[i] == '0')
						ss = '1' + ss, ok = false;
					else if(s[i] == '1')
						ss = '0' + ss, ok = false;
					else
						ss = char('0' + (11 - (s[i] - '0'))) + ss, ok = true;
				}
			}
		}
		cout << ss << endl;
	}
}
