#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin>>n>>m;

        int c = 0;
        for(int i=2; i*i<=m; i++){
            if(m%i==0){
                c++;
            }
            while(m%i==0){
                m/=i;
            }
        }
        if(m>1){
            c++;
        }

        if(c==0){
            cout<<0<<endl;
            continue;
        }

        while(c >= 1){
            if(n%c == 0){
                cout<<c<<endl;
                break;
            }
            c--;
        }
    }
}