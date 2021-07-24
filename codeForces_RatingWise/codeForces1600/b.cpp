

#include <bits/stdc++.h>
using namespace std;


int main() {
    int testcase;
    cin >> testcase;
    while(testcase--){
        string a, b;
        cin>>a>>b;
        int na = a.length();
        int nb = b.length();

        vector<int> v[27];
        for(int i=0;i<na;i++){
            v[a[i]-'a'].push_back(i+1);
        }

        int prev;
        bool ans = true;
        for(int i=0;i<nb;i++){
            bool dofk = false;
            char ch = b[i];
            int k = ch - 'a'; 
            if(i==0){
                for(int j=0;j<(int)v[k].size();j++){
                    if(v[k][j]%2==1){
                        prev = v[k][j];
                        dofk = true;
                        break;
                    }
                }
                if(dofk == false){
                    ans = false;
                    break;
                }
                continue;
            }

            for(int j=0;j<(int)v[k].size();j++){
                if(v[k][j]>prev && (v[k][j]-prev-1)%2==0){
                    prev = v[k][j];
                    dofk = true;
                    break;
                }
            }
            if(dofk == false){
                ans = false;
                break;
            }
            continue;

            if(i==nb-1){
                for(int j=0;j<(int)v[k].size();j++){
                    if(v[k][j]>prev && (v[k][j]-prev-1)%2==0 && (na - v[k][j] - 1)%2==0){
                        prev = v[k][j];
                        dofk = true;
                        break;
                    }
                }
            }

            if(dofk == false){
                ans = false;
                break;
            }
        }

        if(ans){
            cout<<"YES"<<endl;
            continue;
        }


        prev = -1;
        ans = true;
        for(int i=0;i< nb;i++){
            bool dofk = false;
            char ch = b[i];
            int k = ch - 'a'; 
            if(i==0){
                for(int j=0;j<(int)v[k].size();j++){
                    if(v[k][j]%2==0){
                        prev = v[k][j];
                        dofk = true;
                        break;
                    }
                }
                if(dofk == false){
                    ans = false;
                    break;
                }
                continue;
            }

            for(int j=0;j<(int)v[k].size();j++){
                if(v[k][j]>prev && (v[k][j]-prev-1)%2==0){
                    prev = v[k][j];
                    dofk = true;
                    break;
                }
            }
            if(dofk == false){
                ans = false;
                break;
            }
            continue;

            if(i==nb-1){
                for(int j=0;j<(int)v[k].size();j++){
                    if(v[k][j]>prev && (v[k][j]-prev-1)%2==0 && (na - v[k][j] - 1)%2==0){
                        prev = v[k][j];
                        dofk = true;
                        break;
                    }
                }
            }

            if(dofk == false){
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