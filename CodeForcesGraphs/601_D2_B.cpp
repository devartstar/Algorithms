<<<<<<< HEAD
/*
	https://codeforces.com/problemset/problem/1255/B
*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> res;

int solve(){
	int n,m,a;
	cin>>n>>m;
	vector<pair<int,int>> v(n+1);
	long long s=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		v.push_back({a,i});
		s+=a;
	}
	ans = 2*s;
	if(m<n || n<=2){
		return -1;
	}
	sort(v.begin(),v.end());

	res.push_back({1,2});
	res.push_back({1,3});
	int k=2;
	while(k+2<=n){
		res.push_back({k,k+2});
		k++;
	}
	res.push_back({n-1,n});
	int x = v[0].second, y = v[1].second;
	int sum = v[0].first + v[1].first;
	ans+=(m-n)*sum;
	while(n<m){
		res.push_back({x,y});
		n++;
	}

	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		res.clear();
		int a = solve();
		cout<<a<<endl;
		if(a!=-1){    
		 	for(pair<int,int> i : res){
		 	 	cout<<i.first<<" "<<i.second<<endl;
		 	}
		}
	}
}
=======
/*
	https://codeforces.com/problemset/problem/1255/B
*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> res;

int solve(){
	int n,m,a;
	cin>>n>>m;
	vector<pair<int,int>> v(n+1);
	long long s=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		v.push_back({a,i});
		s+=a;
	}
	ans = 2*s;
	if(m<n || n<=2){
		return -1;
	}
	sort(v.begin(),v.end());

	res.push_back({1,2});
	res.push_back({1,3});
	int k=2;
	while(k+2<=n){
		res.push_back({k,k+2});
		k++;
	}
	res.push_back({n-1,n});
	int x = v[0].second, y = v[1].second;
	int sum = v[0].first + v[1].first;
	ans+=(m-n)*sum;
	while(n<m){
		res.push_back({x,y});
		n++;
	}

	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		res.clear();
		int a = solve();
		cout<<a<<endl;
		if(a!=-1){    
		 	for(pair<int,int> i : res){
		 	 	cout<<i.first<<" "<<i.second<<endl;
		 	}
		}
	}
}
>>>>>>> f8b8a940c77db8a197b14ac8be0388e03d567e8c
