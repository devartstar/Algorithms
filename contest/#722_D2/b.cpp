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
	vi v(n);
	f0(i,n){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int c = 0,k=0;
	f0(i,n){
		if(v[i]==0)
			k++;
		if(k==2){
			c++;	
			break;
		}

		if(v[i]>0){
			c++;
			break;
		}
		c++;
	}
	cout<<c<<endl;
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