#include <bits/stdc++.h>
using namespace std;


int main() {
    int tc = 1;
    cin >> tc;
    for(int t=1;t<=tc;t++) {
        int n;
        cin>>n;
        vector<pair<int,int>> ans1(100001);
        vector<pair<int,int>> ans2(100001); 
        for(int i=0;i<100001;i++){
            ans1[i]=make_pair(0,0);
            ans2[i]=make_pair(0,0);
        }
        vector<int> v(n);
        vector<int> v1(n);
        set<int> s;
        for(int i=0;i<n;i++){
            cin>>v[i];
            v1[i] = v[i];
            s.insert(v[i]);
        }
        sort(v1.begin(),v1.end());
        for(int i=0;i<n;i++){
            if(i%2==1){
                ans1[v[i]].first++;
                ans2[v1[i]].first++;
            }else{
                ans1[v[i]].second++;
                ans2[v1[i]].second++;
            }
        }
        bool ans = true;
        for(int x : s){
            if(ans1[x].first!=ans2[x].first || ans1[x].second!=ans2[x].second){
                ans = false;
                break;
            }
        }
        if(ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}