/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-06-29 15:21:00 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/contest/156/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define ull unsigned long long
#define lld long double
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
    string s1,s2;
    cin>>s1>>s2;
    int len1 = s1.length();
    int len2 = s2.length();
    int ans2=MAX_N,ans1=MAX_N;
    f0(i,len2){
        s1="_"+s1+"_";
    }
    len1 = s1.length();
    len2 = s2.length();
    f(i,0,len1-len2){
        int c=0;
        f0(j,len2){
            if(s2[j]!=s1[i+j]){
                c++;
            }
        }
        debug(i);
        debug(c);
        ans1 = min(ans1,c);
    }
    cout<<ans1<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
      freopen("error.txt", "w", stderr);
    #endif
    int tc = 1;
    //cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}


/*
if(len1>=len2){
        f0(i,len2){
            s1="_"+s1+"_";
        }
        len1 = s1.length();
        len2 = s2.length();
        f(i,0,len1-len2){
            int c=0;
            f0(j,len2){
                if(s2[j]!=s1[i+j]){
                    c++;
                }
            }
            debug(i);
            debug(c);
            ans1 = min(ans1,c);
        }
        cout<<ans1<<endl;
    }

    if(len1<len2){
        f(i,0,len2-len1){
            int c=0;
            f0(j,len1){
                if(s1[j]!=s2[i+j])
                    c++;
            }
            ans2=min(ans2,c);
        }
        ans2+=(len2-len1);
        cout<<ans2<<endl;
    }
*/