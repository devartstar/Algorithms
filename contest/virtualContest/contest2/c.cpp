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
	vi v1(n);
	vi v[6];
	f0(i,n){
		cin>>v1[i];
		if(v1[i]==4)		v[0].pb(i);
		if(v1[i]==8)		v[1].pb(i);
		if(v1[i]==15)		v[2].pb(i);
		if(v1[i]==16)		v[3].pb(i);
		if(v1[i]==23)		v[4].pb(i);
		if(v1[i]==42)		v[5].pb(i);
	}
	int k=0;
	bool go = true;
	int min_val=n;
	f0(i,6){
		if((int)v[i].size()<min_val)
			min_val=(int)v[i].size();
	}
	if(k>=min_val)
		go=false;
	while(go){
		/*
		int a,b,c,d,e,f;
		a=v[0][k];
		b=v[1][k];
		c=v[2][k];		
		d=v[3][k];
		e=v[4][k];
		f=v[5][k];
		if(a<b && b<c && c<d && d<e && e<f){
			k++;
		}else{
			go=false;
		}
		*/
		int a = v[0][k];
		v[0][k]=-1;
		f1(i,5){
			bool found=false;
			for(int j=0; j<(int)v[i].size(); j++){
				if(v[i][j]!=-1 && v[i][j]>a){
					a=v[i][j];
					v[i][j]=-1;
					found=true;
					break;
				}
			}
			if(found==false){
				go=false;
				break;
			}
		}
		k++;
		if(k>=min_val)
			go=false;
	}
	int ans=0;
	//cout<<k<<"\n";
	f0(i,6){
		ans+=((int)v[i].size()-k);
	}
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