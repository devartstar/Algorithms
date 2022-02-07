/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - 2021-10-01 00:37:46 	|	
    |    	                            |
    -------------------------------------

    Link - https://www.spoj.com/problems/INVCNT/
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

const int MAX_N = 2e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vi a(MAX_N), b(MAX_N);
vi segtree(4*MAX_N);
// si - Segment Index ( array index )
// segstart - Segment Start ( range start )
// segend - Segment End ( range end )
 


// vi segtree(4*MAX_N);

int query(int si, int segstart, int segend, int querystart, int queryend){
    // COMPLETELY OUTSIDE
    if(querystart > segend || queryend < segstart){   
        return 0;
    }
    
    // COMPLETELY INSIDE
    if(segstart >= querystart && segend<=queryend){     
        return segtree[si];
    }
    
    int mid = segstart + (segend - segstart)/2;
    
    int left = query(2*si, segstart, mid, querystart, queryend);
    int right = query(2*si+1, mid+1, segend, querystart, queryend);
    
    return (left + right);
}

// qi - queryIndex (point where update takes place)

void update(int si, int segstart, int segend, int qi){
    if(segstart == segend){
        segtree[si]++;
        return;
    }
    
    int mid = segstart + (segend - segstart)/2;
    
    if(qi <= mid){
        update(2*si, segstart, mid, qi);
    }else{
        update(2*si+1, mid+1, segend, qi);
    }
    
    segtree[si] = (segtree[2*si] + segtree[2*si+1]);
}

void solve() {
    int n;
    cin>>n;
    segtree.clear();
    segtree.resize(4*MAX_N, 0);
    a.clear();
    a.resize(MAX_N, 0);
    b.clear();
    b.resize(MAX_N, 0);
    f1(i,n){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b.begin()+1, b.begin()+n+1);

    f1(i,n){
        a[i] = lower_bound(b.begin()+1, b.begin()+n+1, a[i]) - b.begin();
    }

    int mx = *max_element(a.begin()+1,a.begin()+n+1);

    ll ans = 0;
    f1(i,n){
        int val =  query(1, 1, mx, a[i]+1, mx);
        ans = ans + val;
        update(1,1,n,a[i]);
    }
    cout<<ans<<endl;
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