// /*
//     -------------------------------------
//     |									|
//     |	Author - Devjit Choudhury		|
//     |	Date   - 2021-07-16 07:44:41 	|	
//     |    	                            |
//     -------------------------------------

//     Link - https://codeforces.com/contest/1503/problem/A
// */

// #include <bits/stdc++.h>
// using namespace std;

// #define ar array
// #define ll long long
// #define ull unsigned long long
// #define lld long double
// #define vi vector<int>
// #define pii pair<int,int>
// #define pll pair<long, long>
// #define vll vector<long long>
// #define vpii vector<pair<int,int>>
// #define all(v) v.begin(),v.end()
// #define f0(i, n) for (int i = 0; i < n; i++) // 0 based indexing
// #define f1(i, n) for (int i = 1; i <= n; i++) // 1 based indexing
// #define f(i, a, b) for (int i = a; i <= b; i++) // 1 based indexing
// #define fll0(i, n) for (long long i = 0; i < n; i++) // 0 based indexing
// #define fll1(i, n) for (long long i = 1; i <= n; i++) // 1 based indexing
// #define fll(i, a, b) for (long long i = a; i <= b; i++) // 1 based indexing
// #define pb push_back
// #define ff first
// #define ss second
// #define mp make_pair

// #ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
// #else
// #define debug(x)
// #endif

// void _print(ll w) {cerr << w;}
// void _print(int w) {cerr << w;}
// void _print(string w) {cerr << w;}
// void _print(char w) {cerr << w;}
// void _print(lld w) {cerr << w;}
// void _print(double w) {cerr << w;}
// void _print(ull w) {cerr << w;}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// const int MAX_N = 1e5 + 1;
// const ll MOD = 1e9 + 7;
// const ll INF = 1e9;


// void solve() {
//     int n;
//     cin>>n;
//     string s;
//     cin>>s;
//     if(s[0]=='0'){
//         cout<<"NO"<<endl;
//         return;
//     }
//     vi a(n);
//     vi b(n);
//     a[0]=1;
//     b[0]=1;
//     f(i,1,n-1){
//         if(s[i]=='0'){
//             if(a[i-1]>b[i-1]){
//                 a[i] = a[i-1]-1;
//                 b[i] = b[i-1]+1;
//             }else{
//                 a[i] = a[i-1]+1;
//                 b[i] = b[i-1]-1;
//             }
//         }else{
//             if(a[i-1]==0 || b[i-1]==0){
//                 a[i] = a[i-1]+1;
//                 b[i] = b[i-1]+1;
//             }else{
//                 a[i] = a[i-1]-1;
//                 b[i] = b[i-1]-1;
//                 if(a[i]==0 && b[i]==0 && (i+1<n ? s[i+1]=='0': false)){    // IMPORTANT STEP
//                     a[i] = a[i-1]+1;
//                     b[i] = b[i-1]+1;
//                 }
//             }
//         }
//     }
//     if(a[n-1]!=0 || b[n-1]!=0){
//         cout<<"NO"<<endl;
//         return;
//     }
//     string ans1 ="(";
//     string ans2 ="(";
//     bool ans = true;
//     f(i,1,n-1){
//         if(a[i]<0 || b[i]<0){
//             ans = false;
//             break;
//         }
//         if(a[i]==a[i-1]+1){
//             ans1 +='(';
//         }else if(a[i]==a[i-1]-1){
//             ans1 += ')';
//         }
        
//         if(b[i]==b[i-1]+1){
//             ans2 += '(';
//         }else if(b[i]==b[i-1]-1){
//             ans2 += ')';
//         }
//     }
//     if(ans){
//         cout<<"YES"<<endl;
//         cout<<ans1<<endl;
//         cout<<ans2<<endl;
//     }else{
//         cout<<"NO"<<endl;
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     #ifndef ONLINE_JUDGE
//       freopen("input.txt","r",stdin);
//       freopen("output.txt","w",stdout);
//       freopen("error.txt", "w", stderr);
//     #endif
//     int tc = 1;
//     cin >> tc;
//     f1(t,tc) {
//         // cout << "Case #" << t  << ": ";
//         solve();
//     }
// }

// TUTORIAL LOGIC

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
    int n;
    string s; 
    cin>>n>>s;
    int c = 0;
    f0(i,n){
        c += (s[i]=='1');
    }
    if(c&1 || s[0]=='0' || s[n-1]=='0'){
        cout<<"NO"<<endl;
        return;
    }
    string ans1, ans2;
    int k=0;
    bool flip = false;
    f0(i,n){
        if(s[i]=='1'){
            ans1.pb(2*k<c ? '(' : ')');
            ans2.pb(ans1.back());
            k++;
        }else{
            ans1.pb(flip ? '(' : ')');
            ans2.pb(flip ? ')' : '(');
            flip = !flip;
        }
    }
    cout<<"YES"<<endl;
    cout<<ans1<<endl;
    cout<<ans2<<endl;
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