/*
	Link - https://codeforces.com/problemset/problem/1466/B
*/

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
	int n;
	cin>>n;
	vi v(n);
	f0(i,n){
		cin>>v[i];
		if(i>=1){
			if(v[i]<=v[i-1]){
				v[i]++;
			}
		}
	}
	set<int> s(v.begin(),v.end());
	cout<<(int)s.size()<<"\n";
}
/*
void solve(){
	int n;
	cin>>n;
	vector<pair<int,int>> v;
	int freq[200001]={0};
	f0(i,n){
		int x;
		cin>>x;
		if(freq[x]==0){
			v.pb({x,1});
			freq[x]++;
		}
		else
			freq[x]++;
	}
	f0(i,(int)v.size()){
		v[i].second = freq[v[i].first];
	}
	int c=0;
	sort(v.begin(),v.end());
	f0(i,(int)v.size()
	f0(i,(int)v.size()){
		if(v[i].second>1 && v[i+1].first==v[i].first+1){
			v[i].second--;
			v[i+1].second++;
		}
		if(v[i].second>=1)
			c++;
	}
	cout<<c<<endl;
}
*/
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