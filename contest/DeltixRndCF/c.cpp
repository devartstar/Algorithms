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
    int a;
    stack <int> s;
    f0(i,n){
    	cin>>a;
		if(a>1){
			while(!s.empty()){
				int k = s.top();
				if(k+1!=a){
				  	s.pop();
				}else
					break;
			}
			assert(!s.empty());
			s.pop();
		}
		s.push(a);
		//printStack
		stack<int> s1(s);
		vi str;
		while(!s1.empty()){
			str.pb(s1.top());
			s1.pop();
		}
		reverse(str.begin(),str.end());
		f0(j,(int)str.size()-1)
			cout<<str[j]<<".";
		cout<<str[(int)str.size()-1]<<endl;
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