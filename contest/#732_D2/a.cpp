
#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc = 1;
    cin >> tc;
    for(int t=1;t<=tc;t++) {
         int n;
        cin>>n;
        vector<int> v(n);
        vector<int> v1(n);
        long long sum1=0, sum2=0;
        for(int i=0;i<n;i++) cin>>v[i], sum1+=v[i];
        for(int i=0;i<n;i++) cin>>v1[i], sum2+=v1[i];
        if(sum1!=sum2){
            cout<<-1<<endl;
            continue;
        } 
        vector<int> first;
        vector<int> last;
        for(int i=0;i<n;i++){
            if(v1[i]>v[i]){
                first.insert(first.begin(),v1[i]-v[i],i);
            }else if(v1[i]<v[i]){
                last.insert(last.begin(),v[i]-v1[i],i);
            }
        }
        cout<<first.size()<<endl;
        for(int i=0;i<(int)first.size();i++) cout<<last[i]+1<<" "<<first[i]+1<<endl;
        cout<<endl;
    }
}