/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - ___curd___ 			|
	|	Time   - __curt__				|	
	|									|
	-------------------------------------
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


void solve() {
	int n;
	string s;
	cin>>n>>s;
	bool a=false;
	string s1="";
	string s2="";
	f0(i,n){
		if(a){
			if(s[i]=='1'){
				s1+='0';
				s2+='1';
			}
			if(s[i]=='2'){
				s1+='0';
				s2+='2';
			}
			if(s[i]=='0'){
				s1+='0';
				s2+='0';
			}
			continue;
		}
		if(s[i]=='1'){
				s1+='1';
				s2+='0';
				a=true;
			}
			if(s[i]=='2'){
				s1+='1';
				s2+='1';
			}
			if(s[i]=='0'){
				s1+='0';
				s2+='0';
			}
	}
	cout<<s1<<"\n";
	cout<<s2<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}