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

/*
//finding the last T in T T T T T T F F F F where T = operarion(arr[mid]) < something
	int left=0, right=n, ans=-1;
	while(left<=right){
		int mid = left + (right-left)/2;
		if(operarion(arr[mid]) < something){
			ans=mid;
			left=mid+1;
		}else{
			right=mid-1;
		}
	}
	cout<<ans<<"\n";	
	//finding the first T in F F F F T T T T T where T = operarion(arr[mid]) < something
	int left=0, right=n, ans=-1;
	while(left<=right){
		int mid = left + (right-left)/2;
		if(operarion(arr[mid]) < something){
			ans=mid;
			right=mid-1;
		}else{
			left=mid+1;
		}
	}
	cout<<ans<<"\n";	
*/
int solve() {
	int n;
	cin>>n;
	vi v(n);
	ll sum=0;
	f0(i,n){
		cin>>v[i];
		sum+=v[i];
	}
	if(sum>=n)
		return sum-n;
	else
		return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        cout<<solve()<<"\n";
    }
}