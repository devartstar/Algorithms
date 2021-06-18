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


string solve() {
	int n;
	cin>>n;
	string s;
	cin>>s;
	bool a[26];
	bool aa[26][26];
	bool aaa[26][26];
	memset(a,false,sizeof(a));
	memset(aa,false,sizeof(aa));
	memset(aaa,false,sizeof(aaa));
	// a - 97
	f0(i,n)
		a[s[i]-97]=true;
	f0(i,n-1)
		aa[s[i]-97][s[i+1]-97]=true;
	f0(i,n-2)
		if(s[i]=='a')
			aaa[s[i+1]-97][s[i+2]-97]=true;
	string ans="";
	f0(i,26)
		if(!a[i]){
			ans = (char)(97+i);
			return ans;
		}
	f0(i,26)
		f0(j,26)
			if(!aa[i][j]){
				char x = 97+i;
				char y = 97+j;
				ans=ans+x+y;
				return ans;
			}
	f0(i,26)
		f0(j,26)
			if(!aaa[i][j]){
				char x = 97+i;
				char y = 97+j;
				ans=ans+'a'+x+y;
				return ans;
			}
	
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    f1(t,tc) {
        // cout << "Case #" << t  << ": ";
        cout<<solve()<<"\n";
    }
}