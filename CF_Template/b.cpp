#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        if(a+b>n-2 || abs(b-a)>=2){
            cout<<-1<<endl;
            continue;
        }
        if(b==a+1){
            int left = 1, right = n;
            for(; left<=b ;left++, right--){
                cout<<right<<" "<<left<<" ";
            }
            while(left <= right){
                cout<<left<<" ", left++;
            }
            cout<<endl;
        }else if(a==b+1){
            int left = 1, right = n;
            for(;left<=a;left++, right--){
                cout<<left<<" "<<right<<" ";
            }
            while(right>=left){
                cout<<right<<" ", right--;
            }
            cout<<endl;
        }else if(b==a){
            int left = 1, right = n;
            for(;left<=a;left++, right--){
                cout<<left<<" "<<right<<" ";
            }
            while(left <= right){
                cout<<left<<" ", left++;
            }
            cout<<endl;
        }
    }
}