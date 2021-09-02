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

const int N = int(2e5) + 99;
const int INF = int(1e9) + 99;

int tc;
string s, t;
int nxt[N][26];

void solve(){
    cin >> s >> t;
    for(int i = 0; i < s.size() + 5; ++i)
        for(int j = 0; j < 26; ++j)
            nxt[i][j] = INF;
    
    for(int i = int(s.size()) - 1; i >= 0; --i){
        for(int j = 0; j < 26; ++j)
            nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i] - 'a'] = i;
    }    

    int res = 1, pos = 0;
    for(int i = 0; i < t.size(); ++i){
        if(pos == s.size()){
            pos = 0;
            ++res;
        }
        if(nxt[pos][t[i] - 'a'] == INF){
            pos = 0; 
            ++res;
        }
        if(nxt[pos][t[i] - 'a'] == INF && pos == 0){
            res = INF;
            break;
        }    
        pos = nxt[pos][t[i] - 'a'] + 1;
        
    }

    if(res >= INF) cout << -1 << endl;
    else cout << res << endl;
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
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}

/*
bool isSubsequence(string s, string t){
    int j=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]==t[j])
            j++;
    }
    return j==t.length();
}

void solve() {
    string s, t, t1;
    cin>>s>>t;
    string z="";
    int ans = 0;
    t1 = t;
    while(z!=t1){
        int left = 0, right =t.length();
        while(left<=right){
            int mid = left + (right-left)/2;
            string temp = t.substr(0,mid+1);
            if(isSubsequence(s,temp)){
                left = mid + 1;
            }
            else{
                right = mid -1;
            }
        } 
        if(right==-1){   // no subseq found
            ans = -1;
            break;
        }
        else{
            ans++;
            z += t.substr(0,left);
            t.erase(0,left);       
        }
    }
    cout<<ans<<endl;
}
*/