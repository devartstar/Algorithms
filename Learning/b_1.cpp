

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        long long n;  
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++)
        cin>>v[i];
        long long ans = 0;
        for(int i=0; i<31; i++){
            long long c = 0;
            for(int j=0; j<n; j++){
                if(v[j]&(1<<i)) c++;
            }
            if(c>=2)    ans = ans + (1<<i);
        }
        cout<<ans<<endl;
    }
}