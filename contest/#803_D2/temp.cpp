#include <bits/stdc++.h>
using namespace std;

bool isLowerCase(char ch) {
	return ch >= 'a' && ch <= 'z';
}

string minWindow(string s, string t) {
        int n = (int)s.length(), m = (int)t.length();
		cout << n << " " << m << endl;
		vector<vector<int>> freq(52, vector<int>(n, 0));
		if(isLowerCase(s[0]))
			freq[s[0]-'a'][0] = 1;
		else
			freq[s[0]-'A'+26][0] = 1;

		for(int i = 1; i < n; i++) {
			for(int j = 0; j < 52; j++) {
				freq[j][i] = freq[j][i - 1];
			}
			if(isLowerCase(s[i]))
				freq[s[i]-'a'][i]++;
			else
				freq[s[i] - 'A' + 26][i]++;
		}

		cout << "FREQ :- " << endl;
		for (int j = 0; j < 52; j++) {
			for (int i = 0; i < n; i++) {
				cout << freq[j][i] << " ";
			}
			cout << endl;
		}

		vector<int> temp(52, 0);
        for(int i = 0; i < m ; i++) {
			if(isLowerCase(t[i]))
				temp[t[i] - 'a']++;
			else
				temp[t[i] - 'A' + 26]++;
		}
		cout << endl;
		cout << endl;
		cout << endl;

		cout << "TEMP :- " << endl;
		for (int i = 0; i < 52; i++)
			cout << temp[i] << " ";
		cout << endl;
		cout << endl;
		cout << endl;

		int anslen = 1e9;
        string ans = "";
        int start_ind = -1;
        
        for(int i = 0; i < n-m+1; i++) {
            int mxpos = i;
            bool ok = true;
            for(int j = 0; j < 52; j++) {
                int val = (i - 1 >= 0 ? freq[j][i-1] : 0);
				int pos = upper_bound(freq[j].begin(), freq[j].end(), val + temp[j] - 1) - freq[j].begin();
				pos = max(i, pos);
				if(pos >= n || (pos < n && freq[j][pos] - val < temp[j])) {
                    ok = false;
                    break;
                }
				cout << i << "," << j << " " << val + temp[j] - 1 << " " << pos << endl;
				mxpos = max(mxpos, pos);
            }
            if(ok) {
                if(mxpos - i + 1 < anslen) {
                    anslen = mxpos - i + 1;
                    start_ind = i;
                }
            }
        }
        if(start_ind == -1) {
            return "";
        }
        for(int i = 0; i < anslen; i++) {
            ans += s[start_ind + i];
        }
        return ans;
    }

int main() {
	string a, b;
	cin >> a >> b;
	cout << minWindow(a, b) << endl;
}