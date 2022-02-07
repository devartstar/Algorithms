#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define file "test"
#define forr(_a,_b,_c) for(_a = _b; _a <= _c; ++_a)
#define ford(_a,_b,_c) for(_a = (_b) + 1; _a --> _c;)
#define forf(_a,_b,_c) for(_a = _b; _a < _c; ++_a)
#define vi vector
#define sz(_v) _v.begin(), _v.end()
string yes[2] = {"NO\n","YES\n"};
const ll mod = ll(1e9) + 7;
const ll inf = ll(1e16) + 1;
bool testc = 0;

const int N = 1e2 + 5;
ll n, i, m, k, x, y, c, t, xx, yy, j, cnt, co, a[N][N], ma, mi = 2e18;
bool tf;

void solve() {
    cin >> m >> n >> k >> y >> x;

    if(m > 2) cycle = n * (m * 2 - 2); 
    // 3 rows so the cycle will go through m * 2 - 2 rows
    else cycle = n * m; // 1 row and 2 rows

    calc = k % cycle;
    if(!calc) calc = cycle;
    //calculate how many asks left after all the cycles

    //brute forces add number of asks to the matrix
    forr(j,1,m) forr(i,1,n) {
        ++cnt;
        if(cnt <= calc) ++a[i][j];
    }
    ford(j,m - 1,2) forr(i,1,n) { // this one only run when m > 2
        ++cnt;
        if(cnt <= calc) ++a[i][j];
    }

    //calcute number of asks from cycles to plus the min, max, and Sergei's seat
    calc = k / cycle;
    if(k % cycle == 0) --calc;
    //if it end on the final cell of the cycle (2,m) then it will count 1 more cycle

    //first row
    forr(i,1,n) {
        a[i][1] += calc; //add number of asks from cycles
        ma = max(ma,a[i][1]);
        mi = min(mi,a[i][1]);
    }

    //last row
    if(m != 1) forr(i,1,n) {
        a[i][m] += calc; //add number of asks from cycles
        ma = max(ma,a[i][m]);
        mi = min(mi,a[i][m]);
    }

    // row 2nd to row (n - 1)th
    forr(j,2,m - 1) forr(i,1,n) {
        a[i][j] += calc * 2; //need to time 2 because a cycle will run those rows twice
        ma = max(ma,a[i][j]);
        mi = min(mi,a[i][j]);
    }

    cout << ma << " " << mi << " " << a[x][y];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifdef umf
	freopen(file".inp","r",stdin); freopen(file".out","w",stdout);
	// freopen("debug.txt","w",stderr);
	#endif

	int testcase = 1;
	if(testc) cin >> testcase;

	

	while(testcase-- > 0) {
		solve();
	}

	return 0;
}