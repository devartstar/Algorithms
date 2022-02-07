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

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#define size(x) (ll)x.size()
//------------------------------------------------------------------------------------------------------------
// JUST A BUNCH OF HELPER FUNCTIONS :-

//  PRIMES
//------------------------------------------------------------------------------------------------------------
// Checks if a single number is Prine :- (n<=10^14)
bool check_Prime(ll n){ if(n==1) return false; for(ll i =1; i*i<=n; i++) if(n%i) return false; return true; }
// Prime Sieve :- (x<=10^7) 
vb sieve(int x = MAX_N+5){ vb isPrime(x+1, true); isPrime[0]=isPrime[1]=false; for(int i=2; i<=x; i++){ if(isPrime[i]){ for(int j=i*2; j<=x; j+=i){ isPrime[j]=false; } } } return isPrime; }
// Segmented Pirme Sieve :
vb segmented_Sieve(int l, int r){ vb isPrime = sieve((ll)sqrt(r*1.0)); vi primes; f0(i,size(isPrime)) if(isPrime[i])  primes.pb(i); vb isPrimeinRange(r-l+1, true); for(int x : primes){ int i = (ll)ceil((l*1.0)/x)*x; while(i<=r){ isPrimeinRange[i-l] = false; i+=x; } } return isPrimeinRange; }// (l + isPrimeinRange[i]) (for all i is the answer)


// FACTORS

//------------------------------------------------------------------------------------------------------------
// Prime Factorization
vector<int> gsf(MAX_N + 5);
void get_Smallest_Factor(){ gsf[1] = 1; for(int i=2; i<=MAX_N; i++){ if(i%2==0 && i>2) gsf[i] = 2; else gsf[i] = i; } for(int i=3; i*i<=MAX_N; i++){ if(gsf[i] == i){ for(int j=i*i; j<=MAX_N; j+=i){ if(gsf[j] == j) gsf[j] = i; } } } }
vector<int> getFactotization(int x){ get_Smallest_Factor(); vector<int> ans; while(x!=1){ ans.push_back(gsf[x]); x/=gsf[x]; } return ans; }
// store the prime factors of x in pf
// vector<int> pf = getFactotization(x);

// Number of Factors
ll count_Factors(ll n){ map<ll,ll> m; for(int i=2; i*i<=n; i++){ while(n%i==0){ m[i]++; n/=i; } } if(n>1) m[n]++; ll ans = 1; for(auto it : m){ ans *= it.second; } return ans; }


void solve() {
    int ans;
    ans = count_Factors(39);
    debug(ans);

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