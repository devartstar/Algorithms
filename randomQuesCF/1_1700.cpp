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

vector<ll> powersOfTwo(31);

void solve() {
	ll x,d;
	cin>>x>>d;
	powersOfTwo[0]=1;
	fll1(i,30){
		powersOfTwo[i]=powersOfTwo[i-1]*2;
	}
	fll1(i,30){
		powersOfTwo[i]--;
	}
	ll k=0;
	while(powersOfTwo[k]<=x){
		k++;
	}
	vll result;
	ll x1=x;
	ll j=k;
	while(j>=1){
		if(x1>=powersOfTwo[j]){
			x1=x1-powersOfTwo[j];
			result.pb(j);
			//cout<<j<<" "<<x1<<"\n";
		}
		if(x1==0){
			break;
		}else{
			j--;
		}
	}	
	ll n1 = x1;
	/*
	f0(i,(int)result.size())	cout<<result[i]<<" ":
	*/
	ll sum=0;
	fll0(i,(int)result.size())
		sum+=result[i];
	cout<<sum+n1<<"\n";
	
	vll fr;
	ll y=d;
	fll0(i,(int)result.size()){
		fr.insert(fr.end(),result[i],y);
		y+=d;
	}
	fll0(i,n1){
		fr.pb(y);
		y+=d;
	}
	fll0(i,(int)fr.size())
		cout<<fr[i]<<" ";
	cout<<"\n";
	
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