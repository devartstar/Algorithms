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
    int n,m;
    cin>>n>>m;
    vi v(n);

    vi present1;
    f0(i,n){
        cin >> v[i];
        if(v[i] == 1)   present1.pb(i);;
        //else            present1[i] = 0; 
    }
    if((int)present1.size()==0){
        cout<<-1<<endl;
        return;
    }
    set<int> taken;
    int s=-1,l=-1;    
    bool possible = true;
    // s = position of 1st element to be taken
    // l = position of last element to be taken
        
    // first element to be taken
    debug(present1);
    f(i,0,(int)present1.size()-1){
        if(present1[i]-(m-1)<=0){
            s=i;
        }
    }
    f(i,0,(int)present1.size()-1){
        if(present1[i]+m-1>=(n-1)){
            l=i;
            break;
        }
    }
    debug(s);   debug(l);
    if(s==-1 || l==-1){
        cout<<-1<<endl;
        return;
    }
    if(s>l){
        cout<<1<<endl;
        return;
    }

    taken.insert(present1[s]);
    f(i,s+1,l-1){
        debug(*(--taken.end()));
        debug(present1[i+1]);
        if(present1[i+1] - *(--taken.end())>2*(m-1)+1)  taken.insert(present1[i]);
    }
    
    taken.insert(present1[l]);
    // last element to be taken
    vi temp;
    for(int x : taken){
        temp.pb(x);
    }
    debug(taken);
    debug(temp);
    bool ok = true;
    if((int)temp.size()==2){
        if(temp[1] > temp[0]+2*(m-1)+1){
            debug("lol");
            ok=false;
        }
    }
    f(i,0,(int)temp.size()-1){
        if(i==0){
            if(temp[i]-m+1>0){
                ok = false;
                debug("lol1");
            }
            continue;
        }
        if(i==(int)temp.size()-1){
            if(temp[i]+m-1<n-1){
                ok = false;
                debug("lol2");
            }
            continue;
        }
        if(temp[i] > temp[i-1]+2*(m-1)+1 || temp[i+1] > temp[i]+2*(m-1)+1){ 
            ok = false; 
            debug("lol3");
        }
    }
    if(ok)
        cout<<(int)taken.size();
    else
        cout<<-1<<endl;
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