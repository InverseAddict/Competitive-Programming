#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int rev(int);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		int r,s;
		cin>>m>>n;
		r=rev(m);
		s=rev(n);
		cout<<rev(r+s);
		cout<<endl;
	}
	return 0;
}
int rev(int x)
{
	int a=x;
	int re=0,count=0;
	while(a>0)
	{
		count++;
		a/=10;
	}
	int base=pow(10,count-1);
	while(x>0)
	{
		re=re+(x%10)*base;
		base/=10;
		x/=10;
	}
	return re;
}
