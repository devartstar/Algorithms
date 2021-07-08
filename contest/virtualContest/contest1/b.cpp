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
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	int a[n][m];
	f0(i,n)
		f0(j,m){
			cin>>arr[i][j];
			a[i][j]=0;
		}
	vpii v;
	int x,y,z,k;
	f0(i,n){
		f0(j,m){
			if(i+1<n && j+1<m){
				if(a[i][j]==arr[i][j] && a[i+1][j]==arr[i+1][j] && a[i][j+1]==arr[i][j+1] && a[i+1][j+1]==arr[i+1][j+1]){
					continue;
				}else{
					x=1,y=1,z=1,k=1;
					if(x==arr[i][j] && arr[i+1][j]==y && arr[i][j+1]==z && k==arr[i+1][j+1]){
                        v.push_back(make_pair(i+1,j+1));
                        a[i][j]=1;a[i+1][j]=1;a[i][j+1]=1;a[i+1][j+1]=1;
                    }
				}
			}
		}
	}
	bool ans=false;
    f0(i,n){
        f0(j,m){
            if(arr[i][j]!=a[i][j])
            	ans=true;
        }
    }
    
    if(ans==0){
        cout<<v.size()<<"\n";
        f0(i,(int)v.size()){
            cout<<v[i].first<<" "<<v[i].second<<"\n";
        }
    }
    else{
        cout<<-1<<"\n";
    }	

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