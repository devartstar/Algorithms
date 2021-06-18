/*  		ACCEPTED
  	https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/owl-fight/
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

vi v;

void applyUnion(int a,int b){
	v[a]=min(v[a],v[b]);
	v[b]=a;
}

int applyFind(int a){
	if(v[a]<0)
		return a;
	else
		return v[a] = applyFind(v[a]);	
}

void solve() {
 	int n,m,a,b;
 	cin>>n>>m;
 	v.resize(n+1);
 	f1(i,n)	v[i]=-1*i;
 	f1(i,m){
 		cin>>a>>b;
 		a=applyFind(a);
 		b=applyFind(b);
 		if(a!=b)	applyUnion(a,b);
 	}
 	/*
 	for(int i:v)	cout<<i<<" ";
 	cout<<endl;
 	*/
 	int k;
 	cin>>k;
 	f1(i,k){
 		//cout<<"lol"<<endl;
 		int x,y,x1,y1;
 		cin>>x>>y;
 		x1=abs(v[applyFind(x)]);
 		y1=abs(v[applyFind(y)]);
 		if(x1==y1){
 			cout<<"TIE"<<endl;
 		}
 		if(x1>y1){
 			cout<<x<<endl;
		}
		if(x1<y1){
   			cout<<y<<endl;
		}
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