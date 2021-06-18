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
	f0(i,n)	cin>>v[i];
	int lis[n];
	int lds[n];
	f0(i,n){
		lis[i]=1;
		lds[i]=1;
	}
	
	int parent_lis[n];
	int parent_lds[n];
	f0(i,n){
		parent_lis[i]=-1;
		parent_lds[i]=-1;
	}
		
	f1(i,n-1){
		f0(j,i){
			if(v[j]<v[i]){
				lis[i]=max(lis[i],lis[j]+1);
				if(lis[i]==lis[j]+1)
					parent_lis[i]=j;
			}
		}
	}
	for(int i=n-2;i>=0;i--){
		for(int j=n-1;j>i;j--){
			if(v[i]>v[j]){
				lds[i]=max(lds[i],lds[j]+1);
				if(lds[i]==lds[j]+1)
					parent_lds[i]=j;
			}
		}
	}
	
	int ans=-1,peak;
	f0(i,n){
		int val = lis[i]+lds[i]-1;
		if(val>ans){
			ans=val;
			peak=i;
		}
		
	}
	cout<<ans<<"\n";
	
	// retreat back the longest bitonic sequence
	vi result;
	int left=peak;
	while(left!=-1){
		result.insert(result.begin(), v[left]);
		left=parent_lis[left];
	}
	int right=parent_lds[peak];
	while(right!=-1){
		result.pb(v[right]);
		right=parent_lds[right];
	}

	f0(i,(int)result.size())
		cout<<result[i]<<" ";
	cout<<"\n";

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