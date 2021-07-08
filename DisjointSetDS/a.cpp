
#include <bits/stdc++.h>
using namespace std;
int main() {
    int tc = 1;
    cin >> tc;
    while(tc--){
        int n; 
        cin>>n;
        vector<int> temp(n+1);
        for(int i=1;i<=n;i++) 
            temp[i]=i;
        for(int i=1;i<=n-1;i+=2){
            swap(temp[i],temp[i+1]);
        }
        if(n%2==1){
            swap(temp[n],temp[n-1]);
        }
        for(int i=1;i<=n;i++) {
            cout<<temp[i]<<" ";
        }
        cout<<endl;
    }
}