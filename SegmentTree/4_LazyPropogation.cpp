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

int arr[MAX_N];
int st[MAX_N], lazy[4*MAX_N]; 

void build(int si, int ss, int se){
	if(ss==se){
		st[si]=arr[ss];
		return;
	}
	int mid = (ss+se)/2;
	build(2*si,ss,mid);
	build(2*si+1,mid+1,se);

	st[si]=st[2*si]+st[2*si+1];
}

int query(int si, int ss, int se, int qs, int qe){
	if(lazy[si]!=0){
		int dx = lazy[si];
		st[si]+= dx*(se-ss+1);
		if(ss!=se){
			lazy[2*si]+=dx;
			lazy[2*si+1]+=dx;
		}
	}
	if(qe<ss || qs>se)
		return 0;
	if(ss>=qs && se<=qe)
		return st[si];
	int mid = (ss+se)/2;	
	return query(2*si,ss,mid,qs,qe)+query(2*si+1,mid+1,se,qs,qe);
}

void update(int si, int ss, int se, int qs, int qe, int val){
	if(lazy[si]!=0){
		int dx = lazy[si];
		st[si]+= dx*(se-ss+1);
		if(ss!=se){
			lazy[2*si]+=dx;
			lazy[2*si+1]+=dx;
		}
	}
	if(qe<ss || qs>se)
		return;
	if(ss>=qs && se<=qe){
		int dx = (se-ss+1)*val;
		st[si]+=dx;
		if(ss!=se){
			lazy[2*si]+=val;
			lazy[2*si+1]+=val;
		}
		return;
	}

	int mid = (ss+se)/2;
	update(2*si, ss, mid, qs, qe, val);
	update(2*si+1, mid+1, se, qs, qe, val);
	st[si]=st[2*si]+st[2*si+1];
}

void solve() {
	int n;
	cin>>n;
	/*
		f1(i,n)
		cin>>arr[i];
	*/
	build(1,1,n);
	int q,code,l,r,val;
	cin>>q;
	while(q--){
		cin>>code;
		if(code==1){
			cin>>l>>r;
			cout<<query(1,1,n,l,r)<<endl;
		}else{
			cin>>l>>r>>val;
			update(1,1,n,l,r,val);
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