#include <bits/stdc++.h>
using namespace std;

int n=4; // no of variables

string decToBinary(int n)
{
    string ans="";
    for (int i = 10; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            ans = ans + "1";
        else
            ans = ans + "0";
    }
    cout<<ans<<endl;
}
 
int main()
{
    vector<string> v;
    for(int i=1; i<(int)pow(2,n); i++){
        cout<<i<<endl;
        string temp = decToBinary(i);
        v.push_back(temp);
        cout<<temp<<endl;
    }
}