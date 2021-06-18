/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 09.06.2021 			|
	|	Time   - 18:03:00				|	
	|									|
	-------------------------------------
	
	Link - https://www.geeksforgeeks.org/golomb-sequence/
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

/*
	Base Case - a[1] = 1
	a[n+1] = 1 + a[n+1-a[a[n]]]
*/

void solveDP(){
	int n; cin>>n;
	int dp[n+1];
	dp[1]=1;
	f(i,2,n)
		dp[i] = 1 + dp[i-dp[dp[i-1]]];
	f1(i,n)
		cout<<dp[i]<<" ";
	cout<<"\n";
}

void solve() {
	int n;
	cin>>n;
	vi sequence{0,1,2,2};
	f(i,3,n){
		// !!! vector.insert(iterator_position, number_of_times_element)
		sequence.insert(sequence.end(),sequence[i],i);
		if((int)sequence.size()>n)
			break;
	}
	f1(i,n)
		cout<<sequence[i]<<" ";
	cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
        solveDP();
    }
}