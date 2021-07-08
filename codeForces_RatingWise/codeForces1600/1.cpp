/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - ___________________ 	|	
    |    	                            |
    -------------------------------------

    Link - 
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<long, long>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define all(v) v.begin(),v.end()
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

int v[1001][1001];
int n,m;
int visited[1001][1001];
int dist[1001][1001];
int parent[1001][1001];
int c=0;
vpii temp;


bool isValid(int x,int y){
    return (x>=0 && x<n && y>=0 && y<m && !visited[x][y] && v[x][y]==1); // Maybe some other conditions too
}

void dfs(int x,int y, int par){
    visited[x][y]=1;
    parent[x][y]=par;
    temp.pb(make_pair(x,y));
    c++;
    
    if(isValid(x,y-1))	//top
        dfs(x,y-1, par);
    if(isValid(x+1,y))	//right
        dfs(x+1,y, par);
    if(isValid(x,y+1))	//down
        dfs(x,y+1, par);
    if(isValid(x-1,y))	//left
        dfs(x-1,y, par);
}



void solve(){
    int k=0;
    f0(i,n){
        f0(j,m){
            if(!visited[i][j] && v[i][j]==1){
                k++;
                dfs(i,j,k);
                for(pii a : temp)
                    dist[a.first][a.second]=c;
                c=0;
                temp.clear();
            }
                
        }
    }

    f0(i,n){
        f0(j,m){
            if(v[i][j]==0){
                int ans=0;
                set<pii> res;
                if(i>0 && v[i-1][j]==1){
                    res.insert({parent[i-1][j],dist[i-1][j]});
                }
                if(i<n-1 && v[i+1][j]==1){
                    res.insert({parent[i+1][j],dist[i+1][j]});
                }
                if(j>0 && v[i][j-1]==1){
                    res.insert({parent[i][j-1],dist[i][j-1]});
                }
                if(j<m-1 && v[i][j+1]==1){
                    res.insert({parent[i][j+1],dist[i][j+1]});
                }
                // for(pii x : res){
                //     cout<<x.first<<" "<<x.second<<endl;
                // }
                for(pii x : res){
                    ans+=x.second;
                }
                cout<<(ans+1)%10;
            }else{
                cout<<".";
            }
        }
        cout<<endl;
    }
        
}


void makeGraph(){
    cin>>n>>m;
    f0(i,n){
        string s;
        cin>>s;
        f0(j,m){
            char ch=s[j];
            if(ch=='.'){
                v[i][j]=1;
            }else{
                v[i][j]=0;
            }
            parent[i][j]=0;
            dist[i][j]=0;
            visited[i][j]=0;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    //cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        makeGraph();
        solve();
    }
}




