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
	f0(i,n){
		string s;
		cin>>s;
		f0(j,m)
			arr[i][j]=s[j];
	}
	vi v(n);
	f0(i,n)	cin>>v[i];
	vi top(m);
	f0(j,m){
		int i=0;
		while(arr[i][j]!='#'){
			i++;
			if(i==n)	break;
		}
		top[j]=i;
	}
	
	int helper[n+1][m+2];
	memset(helper,-1,sizeof(helper));
	int parent[m];
	f0(i,m)	parent[i]=i;
	int val=0;
	f0(j,m){
		int x = top[j]+1;
		int left,mid,right;
		left=j;mid=j+1;right=j+2;
		helper[x-1][mid]=val;
		for(int i=x;i<=n;i++){
			if(helper[i][left]!=-1){
				// intersection
				parent[val]=parent[helper[i][left]];
			}
			if(helper[i][mid]!=-1){
				// intersection
				parent[val]=parent[helper[i][mid]];
			}
			if(helper[i][right]!=-1){
				// intersection
				parent[val]=parent[helper[i][right]];
			}
			helper[i][left]=helper[i][mid]=helper[i][right]=val;
		}
		val++;
	}
	// !!! Debug
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+2;j++){
			cout<<helper[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"parent\n";
	f0(i,m){
		cout<<parent[i]<<" ";
	}
	cout<<"\n";
	//
	int final_ans=0;
	f0(i,m){
		if(parent[i]==i)	final_ans++;
	}
	cout<<final_ans<<"\n";
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