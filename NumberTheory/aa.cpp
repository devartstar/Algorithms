#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin>>n;
	vector<long long> v(n);
	for(long long i=0;i<n;i++){
		cin>>v[i];
	}
	vector<pair<long long,long long>> s;
	s.push_back({0,0});
	long long ans = 0;
	long long cur = 0;
	for(long long i=0; i+1<n; i+=2){
		long long a = v[i];
		long long b = v[i+1];
		cur = cur + a - b;
		ans = ans + min(b, cur+b-s[0].first);
		while(!s.empty() && s.back().first > cur){
			ans += s.back().second;
			s.pop_back();
		}
		if(!s.empty() && s.back().first == cur){
			ans = ans + s.back().second;
			s.back().second++;
		}else{
			if(s.empty())
				s.push_back({cur,0});
			else
				s.push_back({cur,1});
		}
	}
	cout<<ans<<endl;
}