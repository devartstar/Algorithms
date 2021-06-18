/*
	Link : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
	Logic -
		dp[s] = number of ways to get sum 's' so far
		
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


int solve() {
	int d,f,target;
	cin>>d>>f>>target;
	vll ways(target+1);
	ways[0]=1;	// one way to get sum = 0
	for(int rep = 1; rep<=d; rep++){
		vll new_ways(target+1);
		for(int already = 0; already<=target; already++){
			for(int pipes=1;pipes<=f; pipes++){
				if(already+pipes<=target){
					ll& tmp = new_ways[already+pipes];
					tmp+=ways[already];
					if(tmp>=MOD)
						tmp-=MOD;
					//cout<<tmp<<endl;
				}
		   }
		}
		ways=new_ways;
	}
	return ways[target];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        cout<<solve()<<endl;
    }
}