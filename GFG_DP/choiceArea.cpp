/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 08.06.2021 			|
	|	Time   - 19:55:53				|	
	|									|
	-------------------------------------
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

struct Area{
	int a;
	int b;
}

int calc(int A, int B, Area X, Area Y, Area Z, int last, map<pair<int,int>> &memo){
	if(A<=0||B<=0)
		return 0;
	pair<int,int> cur = make_pair(A,B);
	
	if(memo.find(cur)!=memo.end())
		return memo[cur];
		
	int temp;
	switch(last){
		case 1:
			temp = max(calc(A+Y.a,B+Y.b,X,Y,Z,2,memo),calc(A+Z.a,B+Z.b,X,Y,Z,3,memo));
			break;
		case 2:
			temp = max(calc(A+X.a,B+X.b,X,Y,Z,1,memo),calc(A+Z.a,B+Z.b,X,Y,Z,3,memo));	
			break;
		case 3:
			temp = max(calc(A+Y.a,B+Y.b,X,Y,Z,2,memo),calc(A+X.a,B+X.b,X,Y,Z,1,memo));
			break;
	}
	
	memo[cur]=temp;
	return temp;
}

int getMaxPower(int A, int B, Area X, Area Y, Area Z){
	if( A<=0 || B<=0 )
		return 0;
	map<pair<int,int>,int> memo;
	return max(calc(A,B,X,Y,Z,1,memo),max(calc(A,B,X,Y,Z,2,memo),calc(A,B,X,Y,Z,3,memo)));
}

void solve() {
	int A,B;
	cout<<"Enter Powers : ";
	cin>>A>>B;
	Area X,Y,X;
	cout<<"Enter values for Area X ";
	cin>>X.a>>X.b;
	cout<<"Enter values for Area Y ";
	cin>>Y.a>>Y.b;
	cout<<"Enter values for Area Z ";
	cin>>Z.a>>Z.b;
	cout<<getMaxPower(A,B,X,Y,Z);
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