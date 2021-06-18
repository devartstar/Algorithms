/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 13.06.2021 			|
	|	Time   - 07:16:39				|	
	|									|
	-------------------------------------
	
	Link - https://codeforces.com/problemset/problem/706/B
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

int n,q;
vi shop;

int findPosition(int x){
	int left = 0, right = n-1;
	int ans=-1;
	while(left<=right){
		int mid= left+(right-left)/2;
		if(shop[mid]<=x){
			ans=mid;
			left=mid+1;
		}else 	right=mid-1;
	}
	//cout<<x<<"-"<<ans<<"\n";
	return ans;
}

void solve() {
	cin>>n;
	shop.resize(n);
	f0(i,n)	cin>>shop[i];
	sort(all(shop));
	cin>>q;
	f0(i,q){
		int x;
		cin>>x;
		/*
		if(x<shop[0])
			cout<<0<<"\n";
		else{
			int ans = findPosition(x)+1;
			
			if(ans<n && shop[ans]==x)
				ans++;
			cout<<ans<<"\n";	
		}
		*/
		int ans = findPosition(x)+1;
		cout<<ans<<"\n";
	}
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