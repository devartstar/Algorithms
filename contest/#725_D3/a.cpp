/*
	-------------------------------------
	|									|
	|	Author - Devjit Choudhury		|
	|	Date   - 11.06.2021 			|
	|	Time   - 12:48:16				|	
	|									|
	-------------------------------------
	
	Link - https://codeforces.com/contest/1538/problem/A
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

int find_min(int a, int b, int c, int d){
	return min(min(a,b),min(c,d));
}

void solve() {
	int n;
	cin>>n;
	vi v(n);
	int min_ele = MAX_N, min_ele_index=-1;
	int max_ele = -1, max_ele_index=-1;
	//cout<<"lol1"<<endl;
	f0(i,n){
		//cout<<"lol2"<<endl;
		cin>>v[i];
		if(v[i]>max_ele){
			max_ele=v[i];
			max_ele_index=i+1;
		}
		if(v[i]<min_ele){
			min_ele=v[i];
			min_ele_index=i+1;
		}
	}
	cout<<find_min(max(max_ele_index,min_ele_index),max(n+1-max_ele_index,n+1-min_ele_index),max_ele_index+n+1-min_ele_index,min_ele_index+n+1-max_ele_index)<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
	cin >> tc;
	//cout<<"hi"<<endl;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        //cout<<"lolll"<<endl;
        solve();
    }
}