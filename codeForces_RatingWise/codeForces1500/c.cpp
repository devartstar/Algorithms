
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin>>n;
    vector<long long> v(n);
    double k1 = 0;
    for(int i=0; i<n; i++){
        cin>>v[i];
        k1 += v[i];
    }
    k1 /= n;
    double te = 2*k1;
    if((long long)ceil(te) != (long long)floor(te)){
        cout<<"0"<<endl;
        return;
    }
    long long tex = (long long)te;
    sort(v.begin(), v.end());
    long long ans = 0;
    for(long long i = 0; i<n; i++){
        if(tex - v[i] < v[0] || tex-v[i] > v[n-1]){
            continue;
        }
        long long i1 = lower_bound(v.begin(), v.end(), tex-v[i]) - v.begin();
        if(v[i1] + v[i] != tex) continue;
        long long i2 = upper_bound(v.begin(), v.end(), tex-v[i]) - v.begin();
        long long len = max(i2 - max(i+1, i1), 0ll);
        ans += len;
    }
    cout<<ans<<endl;

}

int main() {
    int tc = 1;
    cin >> tc;
    while(tc--) {
        solve();
    }
}