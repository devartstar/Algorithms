/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - ___________________ 	|
	|    	                            |
	-------------------------------------

	Link - 
*/

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ar array
#define ll long long
#define ull unsigned long long
#define lld long double
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<long long, long long>>
#define vb vector<bool>
#define all(v) v.begin(),v.end()
#define f0(i, n) for (int i = 0; i < n; i++) // 0 based indexing
#define f0r(i, n) for (int i = n-1; i >= 0; i--)
#define f1(i, n) for (int i = 1; i <= n; i++) // 1 based indexing
#define f1r(i, n) for (int i = n; i >= 1; i--)
#define f(i, a, b) for (int i = a; i <= b; i++) // 1 based indexing
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define fll0(i, n) for (long long i = 0; i < n; i++) // 0 based indexing
#define fll1(i, n) for (long long i = 1; i <= n; i++) // 1 based indexing
#define fll(i, a, b) for (long long i = a; i <= b; i++) // 1 based indexing
#define disp(v) for(auto x : v) cout<<x<<" "; cout<<endl;
#define disp0(v, n) for(int i = 0; i < n; i++) cout<<v[i]<<" "; cout<<endl;
#define disp0r(v, n) for(int i = n-1; i >= 0; i--) cout<<v[i]<<" "; cout<<endl;
#define disp1(v, n) for(int i = 1; i <= n; i++) cout<<v[i]<<" "; cout<<endl;
#define disp1r(v, n) for(int i = n; i >= 1; i--) cout<<v[i]<<" "; cout<<endl;
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define sz(v) (int)v.size()
#define len(v) (int)v.length()

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll w) {cerr << w;}
void _print(int w) {cerr << w;}
void _print(string w) {cerr << w;}
void _print(char w) {cerr << w;}
void _print(lld w) {cerr << w;}
void _print(double w) {cerr << w;}
void _print(ull w) {cerr << w;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int innerBS(int val, vector<int> B, int n2) {
    int left = 0, right = n2;
    while(left < right - 1) {
		debug(mp(left, right));
		int mid = left + (right - left) / 2;
        if(B[mid] < val) left = mid;
        else right = mid;
    }
    return left;
}


double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    double ans = 0;
    int pos;
    int n1 = (int)A.size(), n2 = (int)B.size();
    if(n1 == 0) {
		if(n2 == 1) {
			return B[0];
		}
        if(n2 & 1) {
            int temp = n2/2;
            return (B[temp] + B[temp-1]) * 1.0 / 2;
        } else {
            int temp = n2/2;
            return B[temp-1];
        }
    }
    if(n2 == 0) {
		if(n1 == 1) {
			return A[0];
		}
        if(n1 & 1) {
            int temp = n1/2;
            return (A[temp] + A[temp-1]) * 1.0 / 2;
        } else {
            int temp = n1/2;
            return A[temp-1];
        }
    }
    int left = 0, right = n1;
    while(left < right - 1) {
		debug(mp(left, right));
		int mid = left + (right - left) / 2;
        int val = A[mid];
		debug(mp(mid, val));
        int temp = innerBS(A[mid], B, n2);
		debug(temp);
		if(mid + pos <= (n1 + n2)/2 ) {
            pos = temp;
            left = mid;
        } else {
            right = mid;
        }
    }
    if((n1 + n2) & 1) {
        ans = ((A[left] + B[pos]) * 1.0) / 2;
    } else {
        if(A[left] > B[pos]) ans = A[left];
        else ans = B[pos];
    }
    return ans;
}

void solve() {
	int n1, n2;
	cin>>n1>>n2;
	vi A(n1), B(n2);
	f0(i, n1) cin>>A[i];
	f0(i, n2) cin>>B[i];
	cout<<findMedianSortedArrays(A, B)<<endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt","r",stdin);
	  freopen("output.txt","w",stdout);
	  freopen("error.txt", "w", stderr);
	#endif
	int tc = 1;
	//cin >> tc;
	f1(t,tc) {
		// cout << "Case #" << t  << ": ";
		solve();
	}
}
