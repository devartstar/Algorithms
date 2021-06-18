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

int n,sum;
vi v;
vi p;
bool dp[10001][10001];

void display(){
	f0(i,(int)p.size())
		cout<<p[i]<<" ";
	cout<<endl;
}

void printAllSubsets(int i, int s){
	
	if(i==0 && s!=0 && dp[0][s]){	// BASE CASE: reached the rist row
		p.pb(v[i]);
		if(v[i]==s)
			display();
		return;
	}
	if(i==0 && s==0){
		display();
		return;
	}

	/*
	// !!! Base Case
	if(i==0){
		if(s==0)
			display();
		if(s!=0 && dp[0][s]){
			p.pb(v[i]);
			if(v[i]==s)
				display();
		}
		return;
	}
	*/
	if(dp[i-1][s]){
		vi b = p;
		printAllSubsets(i-1,s);
	}
	if(s-v[i]>=0 && dp[i-1][s-v[i]]){
		p.pb(v[i]);
		printAllSubsets(i-1,s-v[i]);
	}
}

void isPresentSubsetSumDP() {
	if(n==0||sum<0)
		return;
	f0(i,n)
		dp[i][0] = true;
	f(i,1,sum)
		dp[0][i]=false;
	if(sum-v[0]>=0)
		dp[0][v[0]]=true;
	
	
	f(i,1,n-1)
		f(j,0,sum)
			dp[i][j] = dp[i-1][j] || (j-v[i]>=0?dp[i-1][j-v[i]]:false);
			
	
	cout<<"lol1"<<endl;
	f0(i,n){
		f0(j,sum+1)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
	
	if(dp[n-1][sum])
		printAllSubsets(n-1,sum);
	else
		cout<<"No such subset exists"<<endl;
}	

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        cin>>n>>sum;
        v.resize(n);
        f0(i,n)
        	cin>>v[i];
        isPresentSubsetSumDP();
    }
}