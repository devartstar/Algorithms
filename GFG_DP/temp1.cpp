
#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc = 1;
    cin >> tc;
    while(tc--){
        long long n;
        cin>>n;
        vector<long long> v(n+1);
        v[0] = -1*1000000007;
        long long calc=0;
        for(int i=1;i<=n;i++){
            cin>>v[i];
            calc+=v[i];
        }
        double a1 = *max_element(v.begin(),v.end())*1.0;
        double b1 = (calc-a1)*1.0;
        

        double ans = a1 + b1/(n-1);
        printf("%.8f\n", ans);
    }
}
