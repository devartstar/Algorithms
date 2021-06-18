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
void solve() {
	int n;
	cin>>n;
	vi v(n);
	f0(i,n)	cin>>v[i];
	sort(all(v),greater<int>());
	vi ans;
	int temp = 0;
	for(int i=0;i<n-1;i++){
		if(v[i]!=v[i+1]){
			temp += (i+1)*(v[i]-v[i+1]);
			ans.pb(temp + 2*v[i+1]);
		}
	}
	f0(i,(int)ans.size())	cout<<ans[i]<<" ";
	cout<<"\n";
	/*
	int a = v[0];
	int b = v[1];
	if(a==b){
		cout<<2*a<<"\n";
		return;
	}else{
		cout<<v[0]-v[1] + 2*v[1] <<"\n";
		return; 
	}
	//*
	
}
*/
void solve(){
	ll n;
	cin>>n;
	vll v(n+2);
	v[0]=0;
	v[n+1]=0;
	for(ll i=1;i<=n;i++) cin>>v[i];
	
	ll val=0;
	for(ll i=1;i<=n;i++){
		if(v[i]>v[i+1] && v[i]>v[i-1]){
			//ans=ans-(v[i]-max(v[i-1],v[i+1]));
			val = val + (v[i]-max(v[i-1],v[i+1]));
			v[i]=max(v[i-1],v[i+1]);
			//cout<<"lol "<<ans<<"\n";
		}
	}
	/*
	f0(i,n+2)	cout<<v[i]<<" ";
	cout<<"\n";
	*/
	ll ans=0;
	for(ll i=0;i<=n;i++){
		ans=ans+abs(v[i]-v[i+1]);
	}
	//cout<<ans<<","<<val<<"\n";
	cout<<ans + val<<"\n";
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