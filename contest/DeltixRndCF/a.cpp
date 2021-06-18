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
 	int n,m;
 	cin>>n>>m;
 	string s;
 	char ch[n];
 	cin>>s;
 	m = min(n,m);
 	while(m--){
 		memset(ch,'0',sizeof(ch));
 		f0(i,n){
 			int c=0;
 			if(s[i]=='0'){
 	 			if(i-1>=0 && s[i-1]=='1')
 	 				c++;
				if(i+1<n && s[i+1]=='1')
					c++;
 			}
 			if(c==1)
 				ch[i]='1';
 		}
 		f0(i,n)
 			if(ch[i]=='1')
 				s[i]='1';
 	}
	cout<<s<<endl; 	
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