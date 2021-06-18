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

vi arr;
vi st;

void buildTree(int si, int ss, int se){
	if(ss==se){
		st[si]=arr[ss];
		return;
	}
	int mid = (ss+se)/2;
	buildTree(2*si,ss,mid);
	buildTree(2*si+1,mid+1,se);

	st[si]=min(st[2*si],st[2*si+1]);
}

int answerQuery(int si, int ss, int se, int qs, int qe){
	if(qs>se || qe<ss)
		return INF;
	if(qs<=ss && qe>=se)
		return qt[si];
	int mid = (ss+se)/2;
	int l = answerQuery(2*si, int ss, int mid, int qs, int qe); 
	int r = answerQuery(2*si+1, int mid+1, int se, int qs, int qe); 

	return min(l,r);

}

void update(int si, int ss, int se, int qi){
	if(ss=se){
		st[si]==arr[ss];
	}
	int mid = (ss+se)/2;
	if(qi<=mid)
		update(2*si,ss,mid,qi);
	else
		update(2*si+1,mid+1,se,qi);		
	st[si]=min(st[2*si],st[2*si+1]);	
}

void solve() {
  	int n;
  	cin>>n;
	arr.resize(n+1);
	st.resize(4*n+1);
	f1(i,n){
		cin>>arr[i];
	}

	// !!!	BUILD TREE
	buildTree(1,1,n);
	f1(int node : st){
		cout<<node<<" ";
	}
	cout<<endl;
	int q;

	// !!!	UPDATE
	int i,val;
	cin>>i>>val
	arr[i]=val;
	update(1,1,n,i);

	// !!!	QUERY SELECTOR
	cin>>q;
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<answerQuery(1,1,n,x,y)<<endl;
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