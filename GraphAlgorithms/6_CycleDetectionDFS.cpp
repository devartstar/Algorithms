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
#define fll0(i, n) for (long long i = 0; i < n; i++) // 0 based indexing
#define fll1(i, n) for (long long i = 1; i <= n; i++) // 1 based indexing
#define fll(i, a, b) for (long long i = a; i <= b; i++) // 1 based indexing
#define pb push_back
#define fi first
#define se second


const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n,m;
vi v[100001];
int visited[100001];

bool cycleDetection(int node, int par){
	visited[node]=1;
	
	for(int child : v[node]){
		if(!visited[child]){
			if(cycleDetection(child,node)==true){
				return true;		
			}
		}
		else{
			if(child!=par)
				return true;
		}
	}
	return false;
}

void makeGraph(){
	int a,b;
	cin>>n>>m;
	f0(i,m){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc = 1;

    f1(t,tc) {
        // cout << "Case #" << t  << ": ";

        f1(i,n){
        	v[i].clear();
        	visited[i]=0;
        }
        makeGraph();        
        if(cycleDetection(1,-1))
        	cout<<"Cycle Detected"<<endl;
        else
        	cout<<"Cycle Not Detected"<<endl;
    }
}


// cycle detection
// bool isCycle(int node, int par) {
// 	visited[node] = 1;
// 	for(int child : graph[node]) {
// 		if(!visited[child]) {
// 			bool ok = isCycle(child, node);
// 			if(ok)
// 				return true;
// 		} else {
// 			if(child != par)
// 				return true;
// 		}
// 	}
// 	return false;
// }

basic