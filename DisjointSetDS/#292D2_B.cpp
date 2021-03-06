#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define vector<int> vector<int>
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


bool solve() {
 	int n,m;
 	cin>>n>>m;
 	int c=0;
 	bool bh[n]={true};
 	bool gh[m]={true};
 	int x,a;
 	cin>>x;
 	f0(i,x){
 		cin>>a;
 		bh[a]=true;
 	}
 	int y;
 	cin>>y;
 	f0(i,y){
 		cin>>a;
 		gh[a]=true;
 	}

 	int i=0,j=0;
 	while(c<m*n){
 		i%=n;
 		j%=m;
 		if(bh[i] && !gh[j] ){
 			gh[j]=true;
 			c=0;
 		}else if(!bh[i] && gh[j]){
 			bh[i]=true;
 			c=0;
 		}else{
 			c++;
 		}
  		i++;
		j++;
 		if(find(bh,bh+n,false)==bh+n && find(gh,gh+m,false)==gh+m){
			return true;
			break; 			                                 
 		}
 		//cout<<c<<endl;
 	}
 	return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        if(solve()){
        	cout<<"YES"<<endl;
        }else{
			cout<<"NO"<<endl;
        }
    }
}