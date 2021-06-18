/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 15.06.2021 			|
	|	Time   - 06:42:29				|	
	|									|
	-------------------------------------
	
	Link -
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
	vi a(n);
	vi b(n);
	f0(i,n){
		cin>>a[i];
		a[i]--;
	}
	f0(i,n){
		cin>>b[i];
		b[i]--;
	}
	vi v1(n);
	f0(i,n){
		if(a[i]==b[i]){
			cout<<0<<"\n";
			return;
		}
		v1[a[i]]=b[i];
	}
	set<int> s;
	int visited[n]={0};
	int k=0;
	for(int i=0;i<n;i++){
		if(visited[i])	continue;
		else	k++;
		int first=i,second=v1[i];
		while(second!=i){
			visited[first]=1;
			visited[second]=1;
			s.insert(first);
			s.insert(second);
			first=second;
			second=v1[first];
		}
		if((int)s.size()==n)
			break;
	}
	ll val=1;
	for(int l=1;l<=k;l++){
		val = (val*2)%MOD;
	}
	cout<<val<<"\n";
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