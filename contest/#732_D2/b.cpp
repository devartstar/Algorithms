
#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc = 1;
    cin >> tc;
    for(int t=1;t<=tc;t++) {
        int n,m;
        cin>>n>>m;
        vector<string> v;
        vector<string> v1;
        
        for(int i=0;i<n;i++){
            string s; 
            cin>>s;
            v.push_back(s);
        }
        for(int i=0;i<n-1;i++){
            string s; 
            cin>>s;
            v1.push_back(s);
        }
        string ans="";
        for(int i = 0; i<m;i++){
            vector<char> a1;
            vector<char> a11;
            for(int j=0;j<n;j++) 
                a1.push_back(v[j][i]);
            for(int j=0;j<n-1;j++) 
                a11.push_back(v1[j][i]);
            sort(a1.begin(),a1.end());
            sort(a11.begin(),a11.end());
            bool found = false;
            for(int j=0;j<n-1;j++){
                if(a11[j]!=a1[j]){
                    found = true;
                    ans+=a1[j];
                    break;
                }
            }
            if(found==false)    ans+=a1[n-1];
        }
        cout<<ans<<endl;
    }
}