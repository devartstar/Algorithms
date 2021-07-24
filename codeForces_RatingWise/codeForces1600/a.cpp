

#include <bits/stdc++.h>
using namespace std;


int main() {
    int tc = 1;
    cin >> tc;
    while(tc--){
        long long n;
        cin>>n;
        long long c=0;
        if(n%10==9) c++;
        c += n/10;
        cout<<c<<endl;
    }
}