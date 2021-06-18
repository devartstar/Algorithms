/*
	Link : https://www.geeksforgeeks.org/ugly-numbers/
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
	int n;
	cin>>n;
	vi ugly(n);
	ugly[0]=1;
	int i2=0,i3=0,i5=0;
	int next_2,next_3,next_5;
	int next_ugly;
	next_2 = 2*ugly[i2];
	next_3 = 3*ugly[i3];
	next_5 = 5*ugly[i5];
	for(int i=1;i<n;i++){
		next_ugly = min(next_2,min(next_3,next_5));
		//cout<<next_ugly<<endl;
		ugly[i]=next_ugly;
		if(next_ugly == next_2){
			i2++;
			next_2 = ugly[i2]*2;
		}
		if(next_ugly == next_3){
			i3++;
			next_3 = ugly[i3]*3;
		}
		if(next_ugly == next_5){
			i5++;
			next_5 = ugly[i5]*5;
		}
	}
	return next_ugly;
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