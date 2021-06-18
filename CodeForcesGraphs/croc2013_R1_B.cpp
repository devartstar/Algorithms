<<<<<<< HEAD
/*			ACCEPTED
  		https://codeforces.com/problemset/problem/292/B
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

vi v[100001];
int visited[100001];
int visited1[100001];
int in[100001];
int n,m;
int deg1=0,deg2=0,degm=0;
//bool cyc;

void makeGraph(){
	int a,b;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);		
		in[a]++;
		in[b]++;
	}
}

void dfs(int node){
	visited[node]=1;
	for(int child : v[node]){
		if(!visited[child]){
			dfs(child);
		}
	}
}
    /*
bool isCycle(int node, int parent)
{
    visited1[node] = 1;

    for (auto child = v[node].begin(); child != v[node].end(); child++)
    {
        if (!visited1[*child])
        {
            if (isCycle(*child, node) == true)
            {
                cout << node << ":::" << *child << endl;
                return true;
            }
        }
        else if (*child != node)
        {
            cout << node << ":::" << *child << endl;
            return true;
        }
    }
    return false;
}
  */

bool scc(){
	int c=0;
	f1(i,n){
		if(!visited[i]){
			c++;
			dfs(i);
		}
	}
	if(c==1)	return true;
	else	return false;
}

void cdeg(){

	f1(i,n){
		if(in[i]==2)	
			deg2++;
		if(in[i]==1)
			deg1++;
		if(in[i]==m)			
			degm++;
	}
}

bool isBus(){
	//	all except 2 have degree 2
	// connected component --- all are visited in 1 dfs call
	if(deg2==n-2 && deg1==2 && degm==0 )
		return true;
	return false;
}
bool isRing(){
	//	all have degree 2
	// connected component --- all are visited in 1 dfs call
	// is cyclic
	if(deg2==n && deg1==0 && degm==0 )
		return true;
	return false;
}
bool isStar(){
	// v[i].size() == m then a star
	if(degm>=1)
		return true;
	return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    //cin >> tc;
    tc = 1;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";

		f1(i,n){
			v[i].clear();
			visited[i]=0;
			visited[i]=0;
			in[i]=0;
		}

		makeGraph();
		cdeg();
		//	cyc = isCycle(1,-1);                                         
		//cout<<deg1<<" "<<deg2<<" "<<degm<<" "<<cyc<<endl;
		if(isStar())	cout<<"star topology"<<endl;	
		else if(isRing())	cout<<"ring topology"<<endl;
		else if(isBus())	cout<<"bus topology"<<endl;
		else	cout<<"unknown topology"<<endl;


    }
=======
/*			ACCEPTED
  		https://codeforces.com/problemset/problem/292/B
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

vi v[100001];
int visited[100001];
int visited1[100001];
int in[100001];
int n,m;
int deg1=0,deg2=0,degm=0;
//bool cyc;

void makeGraph(){
	int a,b;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);		
		in[a]++;
		in[b]++;
	}
}

void dfs(int node){
	visited[node]=1;
	for(int child : v[node]){
		if(!visited[child]){
			dfs(child);
		}
	}
}
    /*
bool isCycle(int node, int parent)
{
    visited1[node] = 1;

    for (auto child = v[node].begin(); child != v[node].end(); child++)
    {
        if (!visited1[*child])
        {
            if (isCycle(*child, node) == true)
            {
                cout << node << ":::" << *child << endl;
                return true;
            }
        }
        else if (*child != node)
        {
            cout << node << ":::" << *child << endl;
            return true;
        }
    }
    return false;
}
  */

bool scc(){
	int c=0;
	f1(i,n){
		if(!visited[i]){
			c++;
			dfs(i);
		}
	}
	if(c==1)	return true;
	else	return false;
}

void cdeg(){

	f1(i,n){
		if(in[i]==2)	
			deg2++;
		if(in[i]==1)
			deg1++;
		if(in[i]==m)			
			degm++;
	}
}

bool isBus(){
	//	all except 2 have degree 2
	// connected component --- all are visited in 1 dfs call
	if(deg2==n-2 && deg1==2 && degm==0 )
		return true;
	return false;
}
bool isRing(){
	//	all have degree 2
	// connected component --- all are visited in 1 dfs call
	// is cyclic
	if(deg2==n && deg1==0 && degm==0 )
		return true;
	return false;
}
bool isStar(){
	// v[i].size() == m then a star
	if(degm>=1)
		return true;
	return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    //cin >> tc;
    tc = 1;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";

		f1(i,n){
			v[i].clear();
			visited[i]=0;
			visited[i]=0;
			in[i]=0;
		}

		makeGraph();
		cdeg();
		//	cyc = isCycle(1,-1);                                         
		//cout<<deg1<<" "<<deg2<<" "<<degm<<" "<<cyc<<endl;
		if(isStar())	cout<<"star topology"<<endl;	
		else if(isRing())	cout<<"ring topology"<<endl;
		else if(isBus())	cout<<"bus topology"<<endl;
		else	cout<<"unknown topology"<<endl;


    }
>>>>>>> f8b8a940c77db8a197b14ac8be0388e03d567e8c
}