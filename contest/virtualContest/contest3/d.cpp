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
	cin>>n;
	vi v(n);
	bool allSame=true;
	f0(i,n){
		cin>>v[i];
		if(i>0 && v[i]!=v[i-1])
			allSame=false;
	}	
	vector<int> color(n);

	if(allSame){
		cout<<1<<"\n";
		f0(i,n)	cout<<1<<" ";
		cout<<"\n";
		return;
	}
	
	color[0]=0;
	int ans;
	f(i,1,n-1){
		if(i==n-1){
			// check with i-1 & 0
			if(v[i-1]==v[i]){
				if(color[i-1]==color[0]){
					/*if(v[i]==v[0]){
						ans=2;
						color[i]=color[i-1];
					}else{
						ans=3;
						color[i]=2;
					}
					*/
					if(v[i]==v[0]){
						ans=1;
						color[i]=color[i-1];
					}
					else{
						ans=2;
						color[i]=color[i-1]^1;
					}
				}
				if(color[i-1]!=color[0]){
					ans=2;
					color[i]=color[i-1];
				}
			}
			if(v[i]!=v[i-1]){
				if(color[i-1]==color[0]){
					ans=2;
					color[i]=color[i-1]^1;
				}else{
					if(v[i]==v[0]){
						ans=2;
						color[i]=color[0];
					}else{
						ans=3;
						color[i]=2;
					}
				}
			}
			break;
		}
		color[i]=color[i-1]^1;
	}
	cout<<ans<<"\n";
	f0(i,n){
		cout<<color[i]+1<<" ";
	}
	cout<<"\n";
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