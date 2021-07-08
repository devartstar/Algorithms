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
	int arr[6] = {4,8,15,16,23,42};
	f0(i,n)	cin>>v[i];
	int freq[43];
	f0(i,43)	freq[i]=0;
	int ans=0,k;
	f0(i,n){
		if(v[i]==4)		k=0;
		if(v[i]==8)		k=1;
		if(v[i]==15)	k=2;
		if(v[i]==16)	k=3;
		if(v[i]==23)	k=4;
		if(v[i]==42)	k=5;
		
		if(k==0)
			freq[arr[k]]++;
		else {	
			if(freq[arr[k]]<freq[arr[k-1]])
				freq[arr[k]]++;
			else{
				ans++;
			}
		}
	}
	//cout<<ans<<"\n";
	int min_freq = freq[arr[0]];
	f1(i,5){
		//cout<<freq[arr[i]]<<" ";
		min_freq=min(min_freq,freq[arr[i]]);
	}
	//cout<<"\n";
	//cout<<min_freq<<"\n";
	f0(i,6)
		ans+= (freq[arr[i]] - min_freq);
	cout<<ans<<"\n";
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