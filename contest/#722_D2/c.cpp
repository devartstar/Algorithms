#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define f0(i, n) for (int i = 0; i < n; i++) // 0 based indexing
#define f1(i, n) for (int i = 1; i <= n; i++) // 1 based indexing
#define f(i, a, b) for (int i = a; i <= b; i++) // 1 based indexing
#define pb push_back
#define fi first
#define se second


const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


void solve() {
    int n;
	cin>>n;
	vi v(n);
	set <int> s;
	f0(i,n){
		cin>>v[i];
		s.insert(v[i]);
	}
	if((int)s.size()==1){
		if(*(s.begin())==0)
			cout<<n<<endl;
		else
			cout<<1<<endl;
	}

	auto it = s.begin();
	int x = *it;
	int y = *(++it);
	vi d;
	d.pb(abs(y-x));
	int c=1;
	while(*min_element(d.begin(),d.end())>=y){
		c++;
		if(it==s.end())	break;
		x = *it;
		y = *(++it);
		d.pb(abs(y-x));
	}
	cout<<c<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}