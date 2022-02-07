

#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin>>n;
        int seq[n][5];
        vector<int> tot(5, 0);    
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin>>seq[i][j];
                tot[j] += seq[i][j];
            }
        }
        bool ok = true;
        for(int col1=0;col1<5;col1++){
            int col2;
            for(col2=col1+1; col2<5; col2++){
                int c1,c2,c;
                c1=c2=c=0;
                for(int i=0;i<n;i++){
                    if(seq[i][col1]==0 && seq[i][col2]==1)  c2++;
                    if(seq[i][col1]==1 && seq[i][col2]==0)  c1++;
                    if(seq[i][col1]==1 && seq[i][col2]==1)  c++;
                }
                if(c1>=n/2 && c2>=n/2){
                    cout<<"YES"<<endl;
                    ok = false;
                    break;
                }else{
                    int l1 = max(n/2 - c1, 0);
                    int l2 = max(n/2 - c2, 0);
                    if(l1 + l2 <= c){
                        cout<<"YES"<<endl;
                        ok = false;
                        break;
                    }
                }
                if(!ok)
                break;
            }
            if(!ok)
                break;
            
        }
        if(ok)
        cout<<"NO"<<endl;
    }
}