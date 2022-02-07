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

const int MAX_N = 1e6 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m;
vector<char> v[MAX_N];
vector<char> fin_ans[MAX_N];
vector<pii> ans;
vi visited[MAX_N];

bool inBound(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool isValid(int x,int y){
    bool ok = false;
    debug(mp(x,y));
    f0(i,n){
        debug(fin_ans[i]);
    }
    if
    (
        (inBound(x-1, y) && (fin_ans[x-1][y]=='+' || fin_ans[x-1][y]=='L')) ||
        (inBound(x+1, y) && (fin_ans[x+1][y]=='+' || fin_ans[x+1][y]=='L')) ||
        (inBound(x, y-1) && (fin_ans[x][y-1]=='+' || fin_ans[x][y-1]=='L')) ||
        (inBound(x, y+1) && (fin_ans[x][y+1]=='+' || fin_ans[x][y+1]=='L'))
    )
        ok = true;
    debug(ok);
    int c=0;
    if( inBound(x-1, y) && (fin_ans[x-1][y]=='.')){
        debug(mp(x-1, y));
        c++;
    }
    if( inBound(x+1, y) && (fin_ans[x+1][y]=='.')){
        debug(mp(x+1, y));
        c++;
    }
    if( inBound(x, y-1) && (fin_ans[x][y-1]=='.')){
        debug(mp(x, y-1));
        c++;
    }
    if( inBound(x, y+1) && (fin_ans[x][y+1]=='.')){
        debug(mp(x, y+1));
        c++;
    }
    debug(c);
    return (inBound(x,y) && visited[x][y]==0 && c>=0 && c<=1 && ok && v[x][y]=='.');
    // return (inBound(x,y) && visited[x][y]==0 && c<=2 && c>0 && v[x][y]=='.'); // Maybe some other conditions too
}

void dfs(int x,int y){
    visited[x][y]=1;
    ans.pb(mp(x,y));
    if(fin_ans[x][y] != 'L')    fin_ans[x][y] = '+';
    debug(ans);

    if(isValid(x,y-1)){	//top
        debug("lol1");
        dfs(x,y-1);
    }
    if(isValid(x+1,y)){	//right
        debug("lol2");
        dfs(x+1,y);
    }
    if(isValid(x,y+1)){	//down
        debug("lol3");
        dfs(x,y+1);
    }
    if(isValid(x-1,y)){	//left
        debug("lol4");
        dfs(x-1,y);
    }
}


void solve() {
    cin>>n>>m;
    pii pos;
    ans.clear();
    f0(i,n){
        v[i].clear();
        fin_ans[i].clear();
        visited[i].clear();

        string s;
        cin>>s;
        f0(j,m){
            visited[i].pb(0);
            v[i].pb(s[j]);
            fin_ans[i].pb(s[j]);
            if(v[i][j] == 'L')  pos = mp(i,j);
        }
    }
    f0(i,n){
        debug(v[i]);
    }
    debug(pos);

    dfs(pos.ff, pos.ss);
    debug(ans);
    // cout<<(int)ans.size()<<endl;
    f0(i,n){
        f0(j,m){
            cout<<fin_ans[i][j];
        }
        cout<<endl;
    }
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
|| v[x-1][y]=='L'
|| v[x+1][y]=='L'
|| v[x][y-1]=='L'
|| v[x][y+1]=='L'
*/