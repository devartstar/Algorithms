/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 14.06.2021 			|
	|	Time   - 20:57:21				|	
	|									|
	-------------------------------------
	
	Link -  https://www.geeksforgeeks.org/maximum-sum-bi-tonic-sub-sequence/ 
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
	
	int max_left[n];
	int max_right[n];
	
	// TO TRACE BACK THE MAX_SUM_BITONIC_SEQUENCE
	int parent_left[n];
	int parent_right[n];	
	
	// BASE CASE
	f0(i,n)	max_left[i]=v[i];
	f0(i,n) max_right[i]=v[i];
	
	f0(i,n)	parent_left[i]=-1;
	f0(i,n)	parent_right[i]=-1;
	
	// RECURSION - for left of peak
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(v[i]>v[j]){
				max_left[i]=max(max_left[i], max_left[j] + v[i]);		
				if(max_left[i]==max_left[j]+v[i])
					parent_left[i]=j;
			}
		}
	}
	
	// RECURSION - for right of peak
	for(int i=n-2;i>=0;i--){
		for(int j=n-1;j>i;j--){
			if(v[i]>v[j]){
				max_right[i]=max(max_right[i], max_right[j] + v[i]);		
				if(max_right[i]==max_right[j]+v[i])
					parent_right[i]=j;
			}
		}
	}
	
	// FINDING ANSWER
	int ans = -100001, peak=0;
	f0(i,n){
		int val = max_left[i] + max_right[i] - v[i];
		if(val>ans){
			ans=val;
			peak=i;
		}
	}		
	cout<<ans<<"\n";
	
	// NOW RETRACING BACK THE ANSWER SEQUENCE
	vi result;
	int left = peak;
	while(left!=-1){
		result.insert(result.begin(), v[left]);
		left=parent_left[left];
	}
	int right = parent_right[peak];
	while(right!=-1){
		result.pb(v[right]);
		right=parent_right[right];
	}
	
	// DISPLAYING THE MAX SUM BI-TONIC SEQUENCE
	f0(i,(int)result.size())	cout<<result[i]<<" ";
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