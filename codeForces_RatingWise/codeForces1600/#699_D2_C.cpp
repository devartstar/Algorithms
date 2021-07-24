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
    vi v1(n);
    vi v2(m);
    vi temp[n+1];
    vi temp1[n+1];
    f0(i,n) cin>>v[i];
    f0(i,n){
        cin>>v1[i];
        if(v1[i]!=v[i]){
            temp[v1[i]].pb(i+1);
        }
        else{
            temp1[v1[i]].pb(i+1);
        }
    }
    f0(i,m) cin>>v2[i];

    // f0(i,n+1){
    //     debug(temp[i]);
    // }
    // f0(i,n+1){
    //     debug(temp1[i]);
    // }

    vi freq(n+1, 0);
    vi freq1(n+1, 0);
    vi freq2(n+1, 0);
    vi assign(m,-1);

    f0(i,m){
        freq2[v2[i]]++;
    }
    f0(i,n){
        freq[v1[i]]++;
        if(v[i]!=v1[i]){
            freq1[v1[i]]++;
        }
    }

    // debug(freq);
    // debug(freq1);
    // debug(freq2);

    bool ok = true;

    f0(i,n){
        if(freq2[i]<freq1[i]){
            ok = false;
            break;
        }
    }
    if(ok==false){
        cout<<"NO"<<endl;
        return;
    }

    int k;
    f0(i,m){
        if(freq[v2[i]]>0){
            freq[v2[i]]--;
            int a;
            if((int)temp[v2[i]].size()>0){
                a = temp[v2[i]].back();
                temp[v2[i]].pop_back();
            }else{
                a = temp1[v2[i]].back();
                temp1[v2[i]].pop_back();
            }
            if(ok==false){
                assign[k] = a;
            }
            assign[i] = a;
            ok = true;
        }else{
            ok = false;
            k = i;
        }
    }
    
    debug(ok);

    if(ok==false){
        cout<<"NO"<<endl;
        return;
    }else{
        cout<<"YES"<<endl;
        f0(i,m) cout<<assign[i]<<" ";
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
        debug(t);
        solve();
    }
}




 /*
        vi freq(n+1, 0);
        vi freq1(n+1, 0);
        vi freq2(n+1, 0);
        vi assign(m,-1);
        

        f0(i,m){
            freq2[v2[i]]++;
        }
        f0(i,n){
            freq[v1[i]]++;
            if(v[i]!=v1[i]){
                freq1[v1[i]]++;
            }
        }


        bool ok = true;
        int k;
        f0(i,m){
            if(freq[v2[i]]>0){
                freq[v2[i]]--;
                if(ok==false){
                    assign[k] = temp[v2[i]].back();
                }
                assign[i] = temp[v2[i]].back();
                temp[v2[i]].pop_back();
                ok = true;
            }else{
                ok = false;
                k = i;
            }
        }


        f0(i,n){
            if(freq2[i]<freq1[i]){
                ok = false;
                break;
            }
        }



        if(ok==false){
            cout<<"NO"<<endl;
            rerurn;
        }else{
            cout<<"YES"<<endl;
            f0(i,m) cout<<assign[i]<<" ";
            cout<<endl;
        }
    */