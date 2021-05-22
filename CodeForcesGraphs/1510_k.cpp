/*	 	 	ACCEPTED -- HARD
	https://codeforces.com/problemset/problem/1510/K
*/
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

vll v;
vll v1;
long long ans=0;
long long ans1=0;
long long n;

void imp1(){
	f1(i,n){
		swap(v[2*i-1],v[2*i]);
	}
}
void imp2(){
	f1(i,n){
		swap(v[i],v[n+i]);
	}
}

long long solve1() { 
	long long first;
	first=v[1];
	if(is_sorted(v.begin(),v.end())){
		return ans1;
	}else{
		imp2();
		ans1++;
		if(is_sorted(v.begin(),v.end())){
			return ans1;
		}
	}
	//cout<<"lol "<<v[1]<<" "<<first<<endl;
	while(v[1]!=first){
		if(ans1%2==1){
			//cout<<"imp1"<<endl;
			imp1();
		}
		else{
			//cout<<"imp2"<<endl;
			imp2();
		}
		ans1++;

		if(is_sorted(v.begin(),v.end())){
			return ans1;
		}
	}
	return -1;
}



int solve() {
	long long first;
	first=v[1];
	//cout<<first<<endl;
	if(is_sorted(v.begin(),v.end())){
		return ans;
	}else{
		imp1();
		ans++;
		if(is_sorted(v.begin(),v.end())){
			return ans;
		}
	}
	//cout<<"lol "<<v[1]<<" "<<first<<endl;
	while(v[1]!=first){
		//cout<<v[1]<<endl;
		if(ans%2==0){
			//cout<<"imp1"<<endl;
			imp1();
		}
		else{
			//cout<<"imp2"<<endl;
			imp2();
		}
		ans++;
		if(is_sorted(v.begin(),v.end())){
			return ans;
		}
	}
	return -1;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int tc=1;
    //cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
		cin>>n;
		v.resize(2*n+1);
		v1.resize(2*n+1);
		v[0]=0;
		f1(i,2*n){
			cin>>v[i];
			v1[i]=v[i];
		}

        long long a = solve();
        //cout<<"lol"<<endl;
        v=v1;
        long long b = solve1();
        //cout<<a<<" "<<b<<endl;

        if(a==-1 && b==-1)
        	cout<<-1<<endl;
        if(a==-1 && b>=0)
        	cout<<b<<endl;
        if(a>=0 && b==-1)
    		cout<<a<<endl;
    	if(a>=0 && b>=0)
    		cout<<min(a,b)<<endl;
    }
}