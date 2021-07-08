/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Date   - ___________________ 	|	
    |    	                            |
    -------------------------------------

    Link - 
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<long, long>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define all(v) v.begin(),v.end()
#define f0(i, n) for (int i = 0; i < n; i++) // 0 based indexing
#define f1(i, n) for (int i = 1; i <= n; i++) // 1 based indexing
#define f(i, a, b) for (int i = a; i <= b; i++) // 1 based indexing
#define fll0(i, n) for (long long i = 0; i < n; i++) // 0 based indexing
#define fll1(i, n) for (long long i = 1; i <= n; i++) // 1 based indexing
#define fll(i, a, b) for (long long i = a; i <= b; i++) // 1 based indexing
#define pb push_back
#define fi first
#define se second

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


void solve() {
    int n;
    cin>>n;
    vi v(n);
    int no=0,ne=0;
    f0(i,n){
        cin>>v[i];
        if(v[i]%2==1)  no++;
        else            ne++;
    }

    //cout<<no<< " "<<ne<<endl;
    if(no==1 && ne==1){
        if(abs(v[0]-v[1])==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        return;
    }
    //cout<<no<<" "<<ne<<endl;
    if((no%2==0 && ne%2==0)){
        cout<<"YES"<<endl;
        return;
    }
    else if(no%2==1 && ne%2==1){
        sort(all(v));
        bool ok=false;
        f(i,0,n-2){
            //cout<<abs(v[i]-v[i+1])<<endl;
            if(abs(v[i]-v[i+1])==1){
                //cout<<"lol"<<endl;
                ok=true;
                break;
            }
        }
        if(ok)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}




       /*
       sort(all(v));
    f0(i,(int)v.size()-1){
        if(abs(v[i]-v[i+1])==1)
        {
            v[i]=-1,v[i+1]=-1;
        }
    }
    if(n==0){
        cout<<"YES"<<endl;
        return;
    }
    f0(i,n){
        if(v[i]%2==0)   ne++;
        else            no++;
    }

    if((no%2==0 && ne%2==0) || (no%2==1 && ne%2==1))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
*/