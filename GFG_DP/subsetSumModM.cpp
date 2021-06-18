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

int n,m;
vector<int> arr;

bool subsetSumModM_DP() {
	// 1. if (n>m) By pigeonhole principle its always true
	if(n>m)
		return true;
	
	// DP[0,1,2,3,.....m] -- finally DP[0] matters to us.
	bool DP[m];
	memset(DP,false,m);
	
	// one by one iterating over all elements of arr[]
	for(int i=0;i<n;i++){
		// if (DP[0]) => success
		if(DP[0])
			return true;
			
		// creating a temporary array for the curr run 
		bool temp[m];
		memset(temp,false,m);
		
		for(int j=0; j<m; j++){
			// if (we have already reached a value = j after mod m) then subsetSum.exe(j + arr[i])mod m is also achievable
			if(DP[j])
				temp[(j+arr[i])%m]=true;
		}
		
		//updating the value of DP with temp aray values
		for(int j=0; j<m; j++)
			DP[j] = temp[j];
		
		// also for arr[i] as single element
		DP[arr[i]%m] = true;
	}
	return DP[0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        cin>>n>>m;
        arr.resize(n);
        f0(i,n)
        	cin>>arr[i];
        bool ans = subsetSumModM_DP();
        if(ans){
        	cout<<"Such subset exists"<<endl;
        }else{
        	cout<<"Such subset dosent exists"<<endl;
        }
    }
}