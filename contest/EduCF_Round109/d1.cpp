/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 09.06.2021 			|
	|	Time   - 06:34:35				|	
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

/*
	_ _ _ A _ _ B _ C D E
	_ _ _ x _ _ x _ x x x
	
	Graph Matching with no intersections
	parametric search / alien streak
	!!! DP Solution
		- Person last used
		- Available Spots
		- Sum of values
		dp[position_of_past_person_used][Last_position_occupied] = Value
		dp[i][j] -> dp[i][j+1] Slot j+1 not taken by person i+1
		dp[i][j] -> dp[i+1][j+1] Slot j+1 occupied by person i+1
		solution is min( all k of dp[n][k] )
*/

void solve() {
	int n;
	cin>>n;
	vi present;
	vi absent;
	present.pb(0);
	absent.pb(0);
	f0(i,n){
		int x;
		cin>>x;
		if(x&1)	present.pb(i+1);
		else	absent.pb(i+1);
	}
	int n_person = (int)present.size();
	int n_position = (int)absent.size();

	int dp[n_person+1][n_position+1];
	f0(i,n_person+1)
		f0(j,n_position+1)
			dp[i][j]=INF;
	// !!! Base Case
	dp[0][0]=0;
	
	// Recurse
	f0(i,n_person){
		f0(j,n_position){
			// currently at state  -  last occupied person - i'th | last occupied position - j'th

			// (i+1)th person occupies the jth position
			if(i<n_person-1 && j<n_position-1)
				dp[i+1][j+1]=min(dp[i+1][j+1], dp[i][j] + abs(present[i+1]-absent[j+1]));
				
			//ith person dosent occupy the jth position
			if(j<n_position-1)
				dp[i][j+1] = min(dp[i][j+1],dp[i][j]);
		}
	}

	f0(i,n_person){
		f0(j,n_position)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
	
	cout<<dp[n_person-1][n_position-1]<<"\n";
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