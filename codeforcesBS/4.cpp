/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 13.06.2021 			|
	|	Time   - 03:07:16				|	
	|									|
	-------------------------------------
	
	Link - https://codeforces.com/problemset/problem/1476/A
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


ll solve() {
	ll n,k;
	cin>>n>>k;
	if(n==1)
		return k;
	// to find the first multiple of k greater than n
	if(n>k)	k = ceil(n*1.0/k)*k;	
	//cout<<"lol - "<<n<<" "<<k<<"\n";
	if(k%n==0)	return k/n;
	else return (k/n)+1;
}

	// 			!!! some other implementations
	/*
	// !!! code 1
	for(ll i=1;i<=n;i++){		// basically shouldnt start from 1....i*k distart as near a n as possible
		if(i*k>=n){
			if((i*k)%n==0)
				return ((i*k)/n);
			else
				return ((i*k)/n + 1);
			break;
		}
	}
	*/
	/*
	// !!! code 2
	for(int a=0;a<=k;a++){
		if((n+a)%k==0){
			int mul = (n+a)/k;
			if((mul*k)%n==0)	return (mul*k)/n;
			else return ((mul*k)/n+1);
		}
	}
	*/
	/*
	// !!! code 3	O(1) Time complexity
	if(k<n){
		int a=k,b=n;
		b=b+a/2;
		b=b-(b%a);
		if(b<n)	b+=a;
		if(b%n==0)	return b/n;
		else	return b/n+1;
	}else{
		if(k%n==0)	return k/n;
		else	return k/n+1;
	}
	*/

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