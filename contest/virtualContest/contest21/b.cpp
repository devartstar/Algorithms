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

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


void solve() {
    string s, c;
    cin>>s>>c;
    int l1 = s.length();
    int l2 = c.length();
    debug(l1);  debug(l2);
    if(s<c){
        cout<<s<<endl;
        return;
    }
        int k = -1;
        f0(i,min(l1,l2)){
            if(s[i]<c[i]){
                cout<<s<<endl;
                return;
            }
            if(s[i]==c[i]){
                for(int j = i+1; j<l1;j++){
                    if(s[j]<s[i]){
                        swap(s[i],s[j]);
                        cout<<s<<endl;
                        return;
                    }
                }
            }
            if(s[i]>c[i]){
                k = i;
                break;
            }
        }
        debug(k);
        for(int j=k+1; j<l1; j++){
            if(s[j]<c[k]){
                swap(s[j],s[k]);
                if(s<c){
                    cout<<s<<endl;
                    return;
                }
                swap(s[j],s[k]);
            }
            if(s[j]==c[k]){
                swap(s[k],s[j]);
                if(s<c){
                    cout<<s<<endl;
                    return;
                }
                swap(s[k],s[j]);
            }
        }
        cout<<"---"<<endl;
    
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
int k = -1;
        f0(i,min(l1,l2)){
            if(s[i]>c[i]){
                k=i;
                break;
            }
        }
        if(k==-1){
            cout<<"---"<<endl;
            return;
            
        }else{
            bool found = false;
            vector<string> temp;
            for(int j = k+1; j<l1; j++){
                if(s[j]<c[k]){
                    found = true;
                    swap(s[j],s[k]);
                    break;
                }
                if(s[j]==c[k]){
                    swap(s[j],s[k]);
                    temp.pb(s);
                    swap(s[j],s[k]);
                }
            }
            if(!found){
                for(string str : ans){
                    if(str<c){
                        s = str;
                        found = true;
                        break;
                    }
                }
            }

            if(found){
                cout<<s<<endl;
            }else{
                cout<<"---"<<endl;
            }
        }
        */