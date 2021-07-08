
#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc = 1;
    cin >> tc;
    while(tc--){
        long long n; 
        cin>>n;
        vector<long long> v(n+1);
        set<pair<long long,long long>> s;
        long long cnt=0;
        for(int i=1;i<=n;i++){
            cin>>v[i];
            long long mx = 2*i-1;
            if(v[i]>mx){
                s.insert({v[i],i});
                continue;    
            }
            for(pair<long long,long long> x : s){
                if(x.first*v[i]>mx){
                    break;
                }
                if(x.first*v[i]==x.second+i){
                    cnt++;
                }
            }
            s.insert({v[i],i});
        }
        cout<<cnt<<endl;
    }
}