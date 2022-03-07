#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include <ctime>
#include <memory.h>
#include <algorithm>
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt((x)*1.)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define getar(m,n) for(int i_=0; i_<n; ++i_) cin>>m[i_];
#define fill(m,v) memset(m,v,sizeof(m));
#define flush {cout.flush();fflush(stdout);}
#define random(x) ((rand()<<15|rand())%(x))
#define pi 3.1415926535897932
#define y1 stupid_cmath
#define y0 stupid_cmath_make_me_cry
#define tm stupid_ctime
#define long long long
using namespace std;

int n,m;
int i,j,k,l;
int g[303][303];
int a[303][303], r[303][303], t[303][303];
int inf;

void mul(int a[303][303], int b[303][303]){
	fill(t,195);
	int i,j,k;
	for(i=0;i<n;++i)
	for(j=0;j<n;++j){
		for(k=0;k<n;++k) t[i][j] = max(t[i][j], a[i][k]+b[k][j]);
	}
	memcpy(a,t,sizeof(t));
}

void pow(int b){
	memcpy(a,g,sizeof(g));
	fill(r,195);
	for(int i=0;i<n;++i) r[i][i] = 0;
	while(b){
		if(b&1) mul(r,a);
		mul(a,a);
		b>>=1;
	}
}

int main(){
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
	cin>>n>>m;
	
	inf = 1e9;
	for(i=0;i<n;++i)
	for(j=0;j<n;++j) if(i!=j) g[i][j] = -inf;
	
	for(k=0;k<m;++k){
		cin>>i>>j;
		--i; --j;
		cin>>g[i][j]>>g[j][i];
	}
	
	
	int kl, kr, k;
	kl = 2; kr = n+10;
	
	int ans = 0;
	while(kl<kr){
		k = (kl+kr)>>1;
		
		pow(k);
		
		
		for(i=0;i<n;++i) if(r[i][i]>0) break;
		
		if(i==n) kl=k+1; else{
			ans = k;
			kr = k;
		}
	}
	
	
	cout<<ans<<endl;
	
	return 0;
}