

/*

		!!!HINT FOR SOLVING D - !!!

	Whenever u see 'at least N/3'
	!!! think randomization

	30 times....choose a random element
	REPEAT(30)
		i= random_person;
		iterate subset of s[i]:
			count friends with that subset
	O(30*2^P*N) !!! Way tooo slow

	!!! Sum of Subset O(30*(2^P+N))
	REPEAT(30):
		i = random_person();
		for j = 0....N-1:
			count[his subset]++;   
			// his subset = s[i](intersection)s[j]
			// s[i] = 10011110001
			// s[j] = 01101011101
			// his subset = 00001010001
		SOS
		iterate subsets of s[i]:
			check if (count >=N/2)
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