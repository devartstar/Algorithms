#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,d,g,h,i,j;
	cin>>a;
	while(a--)
	{
		cin>>b;
		int c[b],f[b];
		for(int e=0;e<b;e++) cin>>c[e];
		for(int e=0;e<b;e++) cin>>f[e];
		sort(c,c+b);
		sort(f,f+b);
		g=0;
		h=b;
		while(g<h)
		{
			i=(g+h)>>1;
			j=i*100;
			for(int k=b-1;k>=(b+i)/4;k--) j+=c[k];
			d=0;
			for(int k=b-1;k>=0&&k>=(b+i)/4-i;k--) d+=f[k];
			if(j<d) g=i+1;
			else h=i;
		}
		cout<<g<<endl;
	}
}