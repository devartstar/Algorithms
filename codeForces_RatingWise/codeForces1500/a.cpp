
#include <bits/stdc++.h>
using namespace std;


int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin>>n;
        string str1;
        string str2;
        cin>>str1>>str2;
        bool ok = true;
        for(int i=0;i<n;i++){
            if(str1[i]=='1' && str2[i]=='1'){
                cout<<"NO"<<endl;
                ok = false;
                break;
            }
        }
        if(ok)
            cout<<"YES"<<endl;
    }
}