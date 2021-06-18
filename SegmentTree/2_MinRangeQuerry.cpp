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

int arr[100001],st[400004];

void build(int si, int ss, int se){
	if(ss==se){	//Leaf Node
		st[si]=arr[ss];
		return;
	}
	int mid = (ss+se)/2;
	build(2*si,ss,mid);
	build(2*si+1,mid+1,se);
	st[si]=min(st[2*si],st[2*si+1]);
}

int query(int si, int ss, int se, int qs, int qe){
	if(se<qs || qe<ss)
		return INF;
	if(qs<=ss && qe>=se)
		return st[si];
	int mid = (ss+se)/2;
	return min(query(2*si,ss,mid,qs,qe),query(2*si+1,mid+1,se,qs,qe));
}

void solve() {
	int n,q,l,r;
	cin>>n;
	f1(i,n){
		cin>>arr[i];
	}
	//cout<<"lol1"<<endl;
	build(1,1,n);
	//cout<<"lol2"<<endl;
	cin>>q;
	while(q--){
		cin>>l>>r;
		cout<<query(1,1,n,l+1,r+1)<<endl;			
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