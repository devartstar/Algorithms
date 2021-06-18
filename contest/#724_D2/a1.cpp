#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define f0(i, n) for (int i = 0; i < n; i++) // 0 based indexing
#define f1(i, n) for (int i = 1; i <= n; i++) // 1 based indexing
#define f(i, a, b) for (int i = a; i <= b; i++) // 1 based indexing
#define pb push_back
#define fi first
#define se second


const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


void solve() {
	ll n;
	cin>>n;
	vll v(n);
	f0(i,n)
		cin>>v[i];
	//cout<<"lol"<<endl;
	bool ans = false;
	vll k;
	while((int)v.size()<=300){
		k.clear();
		vll v1 = v;
		int k1 = (int)v.size();
		f0(i,(int)v.size()){
			for(int j=i+1;j<(int)v.size();j++){
				if(find(v.begin(),v.end(),abs(v[i]-v[j]))==v.end() && find(k.begin(),k.end(),abs(v[i]-v[j]))==k.end())
				{
					//cout<<abs(v[i]-v[j])<<endl;
					k.pb(abs(v[i]-v[j]));
					v1.pb(abs(v[i]-v[j]));	
				}
			}
		}
		//cout<<"lol1"<<endl;
		v=v1;
		int k2 = (int)v1.size();
		/*
		f0(i,k2)
			cout<<v[i]<<" ";
		cout<<"\n";
		*/
		if(k1==k2){
			ans=true;
			break;
		}
	}
	if(ans){
		cout<<"yes\n"<<(int)v.size()<<"\n";
		f0(i,(int)v.size()){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}else{
		cout<<"no\n";
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}