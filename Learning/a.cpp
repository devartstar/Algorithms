
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
      int n, x, y;
      cin>>n>>x>>y;
      int mid = (n+1)/2;
      int xd = abs(y - mid), yd = abs(x - mid);
      if(xd%2==0 && yd%2==0){
        cout<<0<<endl;
        continue;
      }
      if(xd%2==1 && yd%2==1){
        cout<<0<<endl;
        continue;
      }
      if((xd%2==0 && yd%2==1) || (xd%2==1 && yd%2==0)){
        cout<<1<<endl;
        continue;
      }
    }
}