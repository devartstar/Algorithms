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
	int n,m;
	cin>>n>>m;
	string v;
	cin>>v;
	/*
	if(v.length()<=m+1){
		cout<<1<<"\n";
		return;
	}
	*/
	int  start = 0, ans = 0;
	while(start+m<n-1){
		int temp_start = start + m;
		bool ok = false;
		while(temp_start > start){
			if(v[temp_start]=='1'){
				ans++;
				//cout<<temp_start<<" ";
				ok=true;
				break;
			}
			temp_start--;
		}
		if(!ok){
			cout<<-1<<"\n";
			return;
		}
		start = temp_start;	
	}
	//cout<<"\n";
	cout<<ans+1<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}