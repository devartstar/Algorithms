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
    ll a,b,c;
    cin>>a>>b>>c;
    if(a==0){
        cout<<0<<endl;
        return;
    }
    if(b==0){
        if(a==1)
            cout<<1<<endl;
        return;
    }
    if(c==0){
        int pos=0;
        if(a>=1){
            pos++;
            if(b>=1){
                pos++;
            }
        }
        cout<<pos<<endl;
        return;
    }
    a--;
    if(a==0){
        int pos=1;
        if(b>=1){
            pos++;
            b--;
            if(c>=1){
                pos++;
                if(b>=1){
                    pos++;
                }
            }
        }
        cout<<pos<<endl;
        return;
    }
    ll xb = 1+(b-1)*2;
    ll xa = 4+(a-1)*4;
    ll xc = 2+(c-1)*4;
    //cout<<xa<<" "<<xb<<" "<<xc<<endl;
    if(xa<xb && xa<xc){
        int pos = xa;
        a=a-((pos-4)/4+1);
        b=b-((pos-1)/2+1);
        c=c-((pos-2)/4+1);
        if(xb>=1){
            pos++;
            b--;
            if(xc>=1){
                pos++;
                if(xb>=1){
                    pos++;
                }
            }
        }
        cout<<1+pos<<endl;
        return;
    }

    if(xb<xa && xb<xc){
        int pos = xb;
        a=a-((pos-4)/4+1);
        b=b-((pos-1)/2+1);
        c=c-((pos-2)/4+1);
        if(b%2==0){
            if(a>=1){
                pos++;
            }
            cout<<1+pos<<endl;
            return;
        }
        if(b%2==1){
            if(c>=1){
                pos++;
            }
            cout<<1+pos<<endl;
            return;
        }
    }

    if(xc<xa && xc<xb){
        int pos = xc;
        a=a-((pos-4)/4+1);
        b=b-((pos-1)/2+1);
        c=c-((pos-2)/4+1);
        if(b>=1){
            pos++;
            b--;
            if(a>=1){
                pos++;
                if(b>=1){
                    pos++;
                }
            }
        }
        cout<<1+pos<<endl;
        return;
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
    //cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}