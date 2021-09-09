/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - ___________________ 	|	
    |    	                            |
    -------------------------------------

    Link - 
    Number of disting sets of 2 five digit numbers such that
    abcde/fghij = N
    where every digit is different and on dividig gives N
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define ull unsigned long long
#define lld long double
#define vi vector<int>
#define vb vector<bool>
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
#define ff first
#define ss second
#define mp make_pair

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll w) {cerr << w;}
void _print(int w) {cerr << w;}
void _print(string w) {cerr << w;}
void _print(char w) {cerr << w;}
void _print(lld w) {cerr << w;}
void _print(double w) {cerr << w;}
void _print(ull w) {cerr << w;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


void solve() {
	int x;
	cin>>x;
	ll c = 0;
    vi v(10);
	f0(i,10)	
		v[i]=i;
	do{
		int n1=0,n2=0;
		f0(i,5){
			n1 = n1*10+v[i];
			n2 = n2*10+v[i+5];
		}
		if(n1/n2==x){
			c++;
		}
	}while(next_permutation(all(v)));
	cout<<c<<endl;
}

void solve1(){
    int x;
    cin>>x;
    int n1, n2;
    int c=0;
    for(int n2=1234; n2<=98765/x; n2++){
        n1 = n2*x;
        vb isPrersent(10, false);
        int temp1 = n1, temp2 = n2;
        while(temp1>0){
            isPrersent[temp1%10] = true;
            temp1/=10;
        }
        while(temp2>0){
            isPrersent[temp2%10] = true;
            temp2/=10;
        }
        f0(i,10)
            if(isPrersent[i]==false && i!=0)
                continue;
        c++;
    }
    cout<<c<<endl;
}

int main() {
    int tc = 1;
    //cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
        solve1();
    }
}