/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 12.06.2021 			|
	|	Time   - 00:15:53				|	
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

int findPF(int n){
	//cout<<n<<" ";
	int ans=0;
	while(n%2==0){
		ans++;
		n/=2;
	}
	for(int i=3;i<=(int)sqrt(n);i+=2){
		if(n%i==0){
			while(n%i==0){
				ans++;
				n/=i;
			}
		}
	}
	if(n>2)	ans++;
	//cout<<ans<<" ";

	return ans;
}

void solve() {
	int a,b,k;
	cin>>a>>b>>k;
	int min_val,max_val;
	int x = __gcd(a,b);
	if(a==b)	min_val=0;
	else if(a==x || b==x)	min_val=1;
	else min_val=2;

	max_val = findPF(a)+findPF(b);
	//cout<<max_val<<" "<<min_val<<"\n";	
	if(k==1 && min_val==1){
		cout<<"YES"<<"\n";
		return;
	}
	if(k>=2 && k<=max_val && k>=min_val){
		cout<<"YES"<<"\n";
		return;
	}
	cout<<"NO"<<"\n";
	return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}