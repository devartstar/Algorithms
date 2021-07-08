#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        long long n;
        cin>>n;
        vector<long long> v(n);
        for(int i=0;i<n;i++) 
            cin>>v[i];
        if(n<=2){
            cout<<0<<endl;
            continue;
        }
        sort(v.begin(),v.end());
        long long ans[n];
        ans[0]=0;
        ans[1]=0;
        ans[2]=-1*v[2];
        long long sum=0;
        sum+=(ans[0]+ans[1]+ans[2]);
        for(int i=3;i<n;i++){
            ans[i]=ans[i-1]-((v[i]-v[i-1])*(i-2))-(v[i]-v[i-2]);
            sum+=ans[i];
        }
        cout<<sum<<endl;
    }
}