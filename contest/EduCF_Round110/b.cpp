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
	ll n;
	cin>>n;
	vi v(n);
	f0(i,n)
		cin>>v[i];
	ll c=0,ans = 0;
	f0(i,n){
		if(v[i]%2==0){
			c++;
			v[i]=-1;
		}
	}
	vi v1;
	f0(i,n)
		if(v[i]!=-1)
			v1.pb(v[i]);
	/*			
	if(c==1)
		ans+=(n-1);
	else if(c==2)
		ans+=(2*n-3);
	else		
		ans += (n*(n-1)/2 - (c-2)*(c-1)/2);
	*/
	
	//cout<<ans<<endl;
	ans+= (n*(n-1))/2 - ((n-c)*(n-c-1))/2; 
	for(int i=0;i<(int)v1.size()-1;i++){
		for(int j=i+1;j<(int)v1.size();j++){
			if(__gcd(v1[i],v1[j])>1){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
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