/*
  	https://codeforces.com/problemset/problem/522/A
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define vi vector<int>
#define vs vector<string>
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

vi v[100001];
vi visited;
vi level;
vs  names;
int n;

void dfs(int node, int lev){
	visited[node]=1;
	level[node]=lev;
	
	for(int child : v[node]){	//no need to check if(child==parent) then continue as no cycle
		if(!visited[child]){
			dfs(child,lev+1);
		}
	}
}

void solve(){
	f1(i,n){
		if(!visited[i])
			dfs(i,1);
	}
	cout<<*max_element(level.begin(),level.end())+1<<endl;
}

void makeGraph(){
	int k=0;
	f1(i,n){
		string a,b,c;
		cin>>a>>b>>c;
		transform(a.begin(),a.end(),a.begin(),::tolower) ;
		transform(c.begin(),c.end(),c.begin(),::tolower);
		int x,y;
		auto it = find(names.begin(),names.end(),c);
		if(it==names.end()){
			//cout<<c<<" not found"<<endl;
			names.pb(c);
			x=k++;
		}else{
			x=it-names.begin();
			//cout<<c<<" found "<<x<<endl;
		}
		auto it1 = find(names.begin(),names.end(),a); 
		if(it1==names.end()){
			//cout<<a<<" not found"<<endl;			
			names.pb(a);
			y=k++;
		}else{
			y=it1-names.begin();
			//cout<<a<<" found "<<y<<endl;
		}
		//cout<<x<<" "<<y<<endl;
		v[x].pb(y);
	}
}

void displayGraph(){
	f1(i,n){
		cout<<i<<" -> ";
		for(int child : v[i]){
   			cout<<child<<" ";
		}
		cout<<endl;

	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	//cin >> tc;
    int tc = 1;

    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        cin>>n;
        visited.resize(n+1);
        level.resize(n+1);
        f1(i,n){
        	v[i].clear();
        	visited[i]=0;
        	level[i]=0;
        }
        makeGraph();
        //displayGraph();
		solve();
    }
}