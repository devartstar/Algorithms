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

int maxindex(int* dist, int n){
	int mi = 0;
	for(int i=0;i<n;i++){
		if(dist[i]>dist[mi])
			mi=i;
	}
	return mi;
}

void selectKcities(int n, int w[4][4], int k){
	int* dist = new int[n];
	vector<int> centers;
	for(int i=0; i<n; i++){
		dist[i]=MAX_N;
	}
	
	int max = 0;
	for(int i=0; i<k; i++){
		centers.pb(max);
		for(int j=0; j<n; j++){
			dist[j] = min(dist[j], w[max][j]);
		}
		max = maxindex(dist,n);
	}
	cout<<dist[max]<<endl;
	for(int i=0; i<(int)centers.size(); i++){
		cout<<centers[i]<<" ";
	}
	cout<<endl;
}

void solve() {
	int n;
	/*
	cin>>n;
	int w[n][n];
	f0(i,n)
		f0(j,n)
			cin>>w[i][j];
	*/
	n = 4;
    int w[4][4] = { { 0, 4, 8, 5 },
                          { 4, 0, 10, 7 },
                          { 8, 10, 0, 9 },
                          { 5, 7, 9, 0 } };
	int k=2;
	selectKcities(n, w, k);
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