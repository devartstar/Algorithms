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

int arr[100001];
int st[400004];

void build(int si, int ss, int se){
	if(ss==se){
		// storing the number of odd elements in the range (ss,se) in the nodes
		if(arr[ss]&1)	
			st[si]=1;
		else
			st[si]=0;
		return;
	}
	int mid = (ss+se)/2;
	build(2*si, ss, mid);
	build(2*si+1, mid+1, se);
	st[si]=st[2*si]+st[2*si+1];
}

int query(int si, int ss, int se, int qs, int qe){
	if(se<qs || qe<ss){
		//cout<<si<<endl;
		//cout<<"ret- "<<0<<endl;
		return 0;
	}
		
	if(qs<=ss && qe>=se){
		//cout<<"ret- "<<st[si]<<endl;
		return st[si];
	}
		
	int mid = (ss+se)/2;
	int l = query(2*si, ss, mid, qs, qe);			
	int r = query(2*si+1, mid+1, se, qs, qe);			
	//cout<<"ret- "<<l+r<<endl;
	return l+r;
}

void update(int si,int ss,int se,int idx){
    if(ss==se){
		// storing the number of odd elements in the range (ss,se) in the nodes
		if(arr[ss]&1)	
			st[si]=1;
		else
			st[si]=0;
		return;
	}
	int mid = (ss+se)/2;
	if(idx<=mid)
		update(2*si, ss, mid, idx);
	else
		update(2*si+1, mid+1, se, idx);

	st[si]=st[2*si]+st[2*si+1];
} 

void solve() {
 	int n;
 	cin>>n;
 	f1(i,n){
 	cin>>arr[i];
 	}
	build(1,1,n);
	f1(i,4*n)
		cout<<st[i]<<" ";
	cout<<endl;
	int q,ca,a,b;
	cin>>q;

	while(q--){
		cin>>ca>>a>>b;	// l and r according to 1 based indexing		
		if(ca==1){
			int nOdd=query(1,1,n,a,b);
			int nEven=(b-a+1)-nOdd;
			cout<<"Number of Odd Elemnts between "<<a<<" and "<<b<<" = "<<nOdd<<endl;
			cout<<"Number of Even Elemnts between "<<a<<" and "<<b<<" = "<<nEven<<endl;
		}
		if(ca==2){
			arr[a]=b;
			update(1,1,n,a);		
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