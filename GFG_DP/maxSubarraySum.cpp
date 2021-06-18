/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 16.06.2021 			|
	|	Time   - 06:28:35				|	
	|									|
	-------------------------------------
	
	!!!	KADANE'S ALGORITHM
	Link - https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
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
	int max_ans = v[0];
	int current_ans=0;
	for(int i=0;i<n;i++){
		current_ans=max(v[i],current_ans+v[i]);
		max_ans = max(max_ans, current_ans);
	}
	cout<<max_ans<<"\n";
}

/*
//	If we want to display the array also
*/
void solve1(){
	int n;
	cin>>n;
	vi v(n);
	f0(i,n)	cin>>v[i];
	int current_ans = 0;
	int max_ans=v[0];
	int start=0,end=0;
	f0(i,n){
		if(current_ans+v[i]>=current_ans){
			current_ans=current_ans+v[i];
		}else{
			current_ans=v[i];
			start=i;
		}
		if(current_ans>=max_ans){
			max_ans=current_ans;
			end=i;
			cout<<start<<" "<<end<<"\n";		
		}
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
        solve1();
    }
}