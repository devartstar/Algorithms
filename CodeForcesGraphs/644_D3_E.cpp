<<<<<<< HEAD
/*				ACCEPTED
		https://codeforces.com/problemset/problem/1360/E
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

int arr[51][51];


void solve() {
 	int n;
 	string s;
 	cin>>n;
 	for(int i=0;i<n;i++){
 		cin>>s;
 		for(int j=0;j<n;j++){
			arr[i][j]=(int)s[j]-'0'; 			
 		}
 	}
 	/*
 	f0(i,n){
 		f0(j,n){
 			cout<<arr[i][j]<<" ";
 		}
 		cout<<endl;	
 	}
 	*/
 	bool ans=true;
 	for(int i=n-2;i>=0;i--){
 		for(int j=n-2;j>=0;j--){
 			if(arr[i][j] && !arr[i+1][j] && !arr[i][j+1])
 				ans=false;
 		}
 	}
 	cout<<(ans? "YES":"NO")<<endl;
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
=======
/*				ACCEPTED
		https://codeforces.com/problemset/problem/1360/E
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

int arr[51][51];


void solve() {
 	int n;
 	string s;
 	cin>>n;
 	for(int i=0;i<n;i++){
 		cin>>s;
 		for(int j=0;j<n;j++){
			arr[i][j]=(int)s[j]-'0'; 			
 		}
 	}
 	/*
 	f0(i,n){
 		f0(j,n){
 			cout<<arr[i][j]<<" ";
 		}
 		cout<<endl;	
 	}
 	*/
 	bool ans=true;
 	for(int i=n-2;i>=0;i--){
 		for(int j=n-2;j>=0;j--){
 			if(arr[i][j] && !arr[i+1][j] && !arr[i][j+1])
 				ans=false;
 		}
 	}
 	cout<<(ans? "YES":"NO")<<endl;
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
>>>>>>> f8b8a940c77db8a197b14ac8be0388e03d567e8c
}