/*
	Link - https://codeforces.com/problemset/problem/1323/A
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


void solve() {
	int n;
	cin>>n;
	int a=-1,b=-1,c=-1;
	bool first=false;
	vi v(n);
	f0(i,n){
		cin>>v[i];
		if(v[i]%2==0)	c=i;
		else{
			if(first)	b=i;
			else{
				first=true;
				a=i;
			}
		}
	}
		
	if(c!=-1)
		cout<<1<<"\n"<<c+1<<"\n";
	else if(a!=-1 && b!=-1)
		cout<<2<<"\n"<<a+1<<" "<<b+1<<"\n";
	else
		cout<<-1<<"\n";
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