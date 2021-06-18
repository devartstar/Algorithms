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
	char arr[n][m];
	char sol1[n][m];
	char sol2[n][m];
	char start,end;
	
	f0(i,n){
		string s;
		cin>>s;
		f0(j,m){
			arr[i][j]=s[j];
		}
		
	}
	
	start='R';
	end='W';
	f0(i,n){
		swap(start,end);
		f0(j,m){
			if(j%2==0)
				sol1[i][j]=start;
			else
				sol1[i][j]=end;
		}
	}

	start='W';
	end='R';
	f0(i,n){
		swap(start,end);
		f0(j,m){
			if(j%2==0)
				sol2[i][j]=start;
			else
				sol2[i][j]=end;
		}
	}	

	
	
	bool ans1=true,ans2=true;
	f0(i,n){
		f0(j,m){
			if(arr[i][j]=='R' && sol1[i][j]=='W'){
				ans1=false;
				break;
			}
			if(arr[i][j]=='W' && sol1[i][j]=='R'){
				ans1=false;
				break;
			}
		}
	}
	f0(i,n){
		f0(j,m){
			if(arr[i][j]=='R' && sol2[i][j]=='W'){
				ans2=false;
				break;
			}
			if(arr[i][j]=='W' && sol2[i][j]=='R'){
				ans2=false;
				break;
			}
		}
	}
	if(ans1==false && ans2==false)
		cout<<"no"<<"\n";
	else{
		if(ans1){
			cout<<"yes"<<"\n";
			f0(i,n){
				f0(j,m)	cout<<sol1[i][j];
				cout<<"\n";
			}
		}else if(ans2){
			cout<<"yes"<<"\n";
			f0(i,n){
				f0(j,m)	cout<<sol2[i][j];
				cout<<"\n";
			}
		}
	}
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