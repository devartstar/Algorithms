/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-07-23 11:46:11 	|	
    |    	                            |
    -------------------------------------

    Link - https://codeforces.com/contest/1553/problem/D
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

vi v[26];

bool case1(string s1, string s2){
    // first chosen character starts from odd position
    int prev;
    bool found = false;
    int ch = s2[0]-'a';
    for(int x : v[ch]){
        if(x&1){
            prev = x;
            found = true;
            break;
        }
    }
    if(!found)  return false;
    else        found = false;

    if(s2.length()>2){
        for(int i=1; i<s2.length()-1; i++){
            ch = s2[i] - 'a';
            int j = upper_bound(all(v[ch]), prev) - v[ch].begin();
            while(j<(int)v[ch].size()){
                int x = v[ch][j];
                if(x>prev && (x-prev-1)%2==0){
                    prev = x;
                    found = true;
                    break;
                }
                j++;
            }
            if(!found)  return false;
            else        found = false;
        }
    }

    ch = s2[s2.size()-1]-'a';
    int j = upper_bound(all(v[ch]), prev) - v[ch].begin();
    while(j<(int)v[ch].size()){
        int x = v[ch][j];
        if(x>prev && (x-prev-1)%2==0 && (s1.length()-x)%2==0){
            found = true;
            break;
        }
        j++;
    }
    if(found)   return true;
    else        return false;
}

bool case2(string s1, string s2){
    // first chosen character starts from even position
    int prev;
    bool found = false;
    int ch = s2[0]-'a';
    for(int x : v[ch]){
        if(!(x&1)){
            prev = x;
            found = true;
            break;
        }
    }
    if(!found)  return false;
    else        found = false;

    
    if(s2.length()>2){
        for(int i=1; i<s2.length()-1; i++){
            ch = s2[i] - 'a';
            int j = upper_bound(all(v[ch]), prev) - v[ch].begin();
            while(j<(int)v[ch].size()){
                int x = v[ch][j];
                if(x>prev && (x-prev-1)%2==0){
                    prev = x;
                    found = true;
                    break;
                }
                j++;
            }
            debug(found);
            if(!found)  return false;
            else        found = false;
        }
    }

    ch = s2[s2.size()-1]-'a';
    int j = upper_bound(all(v[ch]), prev) - v[ch].begin();
    while(j<(int)v[ch].size()){
        int x = v[ch][j];
        if(x>prev && (x-prev-1)%2==0 && (s1.length()-x)%2==0){
            found = true;
            break;
        }
        j++;
    }
    if(found)   return true;
    else        return false;
}

void solve() {
    string s1, s2;
    cin>>s1>>s2;
    if(s2.length()==1){
        bool ans = false;
        for(int i=0;i<s1.length(); i++){
            if(s2[0]==s1[i] && (s1.length()-(i+1))%2==0){
                ans=true;
                break;
            }
        }
        if(ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        return;
    }
    f0(i,s1.length()){
        v[s1[i]-'a'].pb(i+1);
    }
    bool ans1 = case1(s1,s2);
    bool ans2 = case2(s1,s2); 
    debug(ans1);
    debug(ans2);

    if(ans1 || ans2)    cout<<"YES"<<endl;
    else                cout<<"NO"<<endl;
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
        debug(t);
        f0(i,26)    v[i].clear();
        solve();
    }
}