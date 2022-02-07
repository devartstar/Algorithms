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
#define endl '\n'

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


// Time Complexity O(N logN)
void stl_sort(){
    vector<int> v = {4, 1, 6, 2, 3};
    sort(v.begin(), v.end());
    debug("before :");
    debug(v);
    debug("after :");
    debug(v);
    
    v = {4, 1, 6, 2, 3};
    int k = 2;
    // sorts the first k elements
    sort(v.begin(), v.begin() + k); 
    debug("before :");
    debug(v);
    debug("after :");
    debug(v);
    

    vector<string> v1 = {"mouse", "dog", "cat", "ant", "moth", "elephant"};
    // lambda function
    auto sortByLength = [] (const auto& a, const auto& b){
        return a.size() < b.size();
    };
    debug("before :");
    debug(v1);
    sort(all(v1), sortByLength);
    debug("after :");
    debug(v1);


    // STABLE SORT GAURANTEES THE RELATIVE ORDER
    v1 = {"mouse", "dog", "cat", "ant", "moth", "elephant"};
    debug("before :");
    debug(v1);
    stable_sort(all(v1), sortByLength);
    debug("after :");
    debug(v1);
}

void binsrc(){
    vector<int> v = {7, 5, 3, 1};
    cout<<(binary_search(all(v), 3, greater<int>()) ? "FOUND" : "NOT FOUND");   // op - found
    cout<<endl;
    cout<<(binary_search(all(v), 4, greater<int>()) ? "FOUND" : "NOT FOUND");   // op - not found
    cout<<endl;

    v = {1, 3, 3, 5, 7};
    auto it0 = lower_bound(all(v), 0);
    auto it1 = lower_bound(all(v), 3);
    auto it2 = lower_bound(all(v), 4);
    auto it3 = lower_bound(all(v), 8);

    cout<<distance(v.begin(), it0)<<endl;
    cout<<distance(v.begin(), it1)<<endl;
    cout<<distance(v.begin(), it2)<<endl;
    cout<<distance(v.begin(), it3)<<endl;
}

int main(){

    // stl_sort();
    binsrc();
}

