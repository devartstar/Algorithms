/*
	Link - https://codeforces.com/problemset/problem/1462/B
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define f0(i, n) for (int i = 0; i < n; i++) // 0 based indexing
#define f1(i, n) for (int i = 1; i <= n; i++) // 1 based indexing
#define f(i, a, b) for (int i = a; i <= b; i++) // 1 based indexing
#define pb push_back
#define fi first
#define se second


const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

/*
void solve() {
	int n;
	cin>>n;
	string s;
	cin>>s;
	int pos = s.find("2020");
	if(pos==0 || pos==n-4){
		cout<<"YES"<<"\n";
		return;
	}
	if(s[0]=='2' && s.substr(n-3,3)=="020"){
		cout<<"YES"<<"\n";
		return;
	}
	if(s.substr(0,2)=="20" && s.substr(n-2,2)=="20"){
		cout<<"YES"<<"\n";
		return;
	}
	if(s.substr(0,3)=="202" && s[n-1]=='0'){
		cout<<"YES"<<"\n";
		return;
	}
	cout<<"NO"<<"\n";
	return;
}
*/

void solve(){
	int n;
	string s;
	cin>>n>>s;
	bool ans=false;
	for(int first=0;first<=4;first++){
		int second = 4-first;
		string s1 = s.substr(0,first)+s.substr(n-second);
		if(s1=="2020")
			ans=true;
	}
	cout<<(ans?"YES":"NO")<<endl;
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