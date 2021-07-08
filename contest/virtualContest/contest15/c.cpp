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
    cin>>n;
    vi v(n);
    f0(i,n) cin>>v[i];
    int left = 0, right = n-1;
    vector<char> ans;
    int temp = -1;
    while(left<=right){
        int l = v[left];
        int r = v[right];
        debug(temp); debug(l); debug(r);
        if(l<r){
            if(l>temp)  ans.pb('L'), temp=v[left], left++;          // temp is to store the previous element inserted in ans
            else if(r>temp) ans.pb('R'), temp=v[right], right--;
            else break;
        }else if(r<l){
            if(r>temp)  ans.pb('R'), temp=v[right],  right--;
            else if(l>temp) ans.pb('L'), temp=v[left], left++;
            else break;
        }else if(l==r){
            break;
        }
    }
    int left1 = left;
    int right1 = right;
    int prev1 = temp;
    vi tempans1;
    while(left1<=right1){
        if(v[left1]>prev1){
            prev1 = v[left1];
            tempans1.pb('L');
            left1++;
        }else{
            break;
        }
    }
    int left2 = left;
    int right2 = right;
    int prev2 = temp;
    vi tempans2;
    while(left2<=right2){
        if(v[right2]>prev2){
            prev2 = v[right2];
            tempans2.pb('R');
            right2--;
        }else{
            break;
        }
    }


    if((int)tempans1.size()>(int)tempans2.size()){
        cout<<(int)ans.size()+(int)tempans1.size()<<endl;
        for(char x : ans)       cout<<x;
        for(char x : tempans1)  cout<<x;
        cout<<endl;
    }else{
        cout<<(int)ans.size()+(int)tempans2.size()<<endl;
        for(char x : ans)       cout<<x;
        for(char x : tempans2)  cout<<x;
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
    //cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}


/*

if(v[left]<v[right]){
            if(v[left]>temp){
                ans.pb(v[left]);
                left++;
            }else if(v[right]>temp){
                ans.pb(right);
                right--;
            }else{
                break;
            }
        }else{
            if(v[right]>temp){
                ans.pb(v[right]);
                right--;
            }else if(v[left]>temp){
                ans.pb(left);
                left++;
            }else{
                break;
            }
        }

*/

/*

if(l<=temp) break;
            int j = (right-left)/2;
            debug(j);
            int ok = 0;
            for(int a=1; a<=j; a++){
                int left1 = left+a;
                int right1 = right-a;
                // debug(left1);
                // debug(right1);
                if(v[left1]!=v[right1]){
                    if(v[left1]<v[right1]){
                        if(v[left1]>l)  ok=-1;
                        else if(v[right1]>l) ok=1;
                    }
                    if(v[right1]<v[left1]){
                        if(v[right1]>l) ok=1;
                        else if(v[left1]>l) ok=-1;
                    }
                    break;
                }
            }
            debug(ok);
            if(ok==-1 || ok==0){
                ans.pb('L');
                temp=l;
                left++;
            }
            if(ok==1){
                ans.pb('R');
                temp=r;
                right--;
            }
*/