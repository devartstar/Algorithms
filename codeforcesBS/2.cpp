/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 13.06.2021 			|
	|	Time   - 02:08:30				|	
	|									|
	-------------------------------------
	
	Link - https://codeforces.com/problemset/problem/202/A
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<long, long>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define all(v) v.begin(),v.end()
#define f0(i, n) for (int i = 0; i < n; i++) // 0 based indexing
#define f1(i, n) for (int i = 1; i <= n; i++) // 1 based indexing
#define f(i, a, b) for (int i = a; i <= b; i++) // 1 based indexing
#define fll0(i, n) for (long long i = 0; i < n; i++) // 0 based indexing
#define fll1(i, n) for (long long i = 1; i <= n; i++) // 1 based indexing
#define fll(i, a, b) for (long long i = a; i <= b; i++) // 1 based indexing
#define pb push_back
#define fi first
#define se second

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<string> v;

bool isPalindrome(string s){
	int left = 0,right = s.length()-1;
	while(left<right){
		if(s[left]!=s[right])
			return false;
		left++;
		right--;
	}
	return true;
}

void solve(string s,string ans){
	if(s.empty()){
		if(isPalindrome(ans))
			v.pb(ans);
		return;
	}
	solve(s.substr(1),ans+s[0]);	// consider the element
	solve(s.substr(1),ans);		// dont consider the element
}

/*
void solve() {
	string s;
	cin>>s;
	int len = s.length();
	vector<string> v;
	for(int sl=1;sl<=len;sl++){
		for(int j=0;j<=len-sl;j++){
			string temp = s.substr(j,sl);
			cout<<temp<<"\n";
			if(isPalindrome(temp))
				v.pb(temp);
		}
	}
	sort(all(v));
	cout<<v[-1]<<"\n";
}
*/


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        string s,ans="";
        cin>>s;
        solve(s,ans);
        sort(all(v));
        cout<<v[(int)v.size()-1]<<"\n";
    }
}