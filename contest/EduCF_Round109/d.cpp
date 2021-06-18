#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define f0(i, n) for (int i = 0; i < n; i++) // 0 based indexing
#define f1(i, n) for (int i = 1; i <= n; i++) // 1 based indexing
#define f(i, a, b) for (int i = a; i <= b; i++)
#define rf(i, b, a) for (int i = b; i >= a; i--)
#define pb push_back
#define fi first
#define se second


const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


void solve() {
	int n;
	cin>>n;
	vi v(n+1);
	stack<int> l;
	stack<int> r;	
	f1(i,n){
		cin>>v[i];
	}
	rf(i,n,1){
		if(v[i]==0){
			r.push(i);
		}
	}
	
	int a,b;
	ll ans = 0;
	int used[1000001]={0};
	f1(i,n){
		if(l.empty() && r.empty())
			break;
		//cout<<i<<endl;
		if(v[i]==1){
			if(!l.empty())	a = abs(i-l.top());
			else 	a = INF;
			if(!r.empty())	b = abs(i-r.top());
			else	b=INF;
			//cout<<a<<" - "<<b<<endl;
			if(a<=b){
				cout<<i<<"--"<<l.top()<<"   "<<a<<endl;
				used[l.top()]=1;
				ans+=a;
				l.pop();
			}else{
				cout<<i<<"--"<<r.top()<<"   "<<b<<endl;
				used[r.top()]=1;
				ans+=b;
				r.pop();
			}
			}else{
			if(used[i]==0)
				l.push(i);// causing problems so used array
			if(r.top()<=i || r.top()==used[i])	r.pop();
		}
		/*
		1 0 0 1 1 0 0 1 1 1 0 0 0 0
		stack<int> l1(l);
		stack<int> r1(r);
		cout<<"Left stack - ";
		while(!l1.empty()){
			cout<<l1.top()<<" ";
			l1.pop();
		}
		cout<<"\n";
		cout<<"Right stack - ";
		while(!r1.empty()){
			cout<<r1.top()<<" ";
			r1.pop();
		}
		cout<<"\n";
		*/
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