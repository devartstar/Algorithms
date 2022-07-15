#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) {
        cin>>v[i];
    }
    ll ind = n-1;
    while(ind >= 0 && v[ind] == 0) ind--;
	if(ind < 0) {
		cout << "YES" << endl;
		return;
	}
    if(v[ind] > 0) {
        cout<<"NO"<<endl;
        return;
    }
    vector<ll> temp(n, 0);
    for(ll i = 0; i <= ind; i++) temp[i] = 1;
    temp[ind] = v[ind];
    
    ll prev_val = v[ind] * -1;
    ind--;
    while(ind > 0) {
        if(prev_val > 0) {
            temp[ind] += prev_val - 1;
        }
        if(temp[ind] < v[ind]) {
            cout<<"NO"<<endl;
            return;
        }
        prev_val = temp[ind] - v[ind];
        temp[ind] = v[ind];
        ind--;
    }
    if(prev_val > 0) {
        temp[0] += prev_val - 1;
    }
    if(temp[0] == v[0]) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int t;
    t = 1;
    cin>>t;
    while(t--) solve();
}