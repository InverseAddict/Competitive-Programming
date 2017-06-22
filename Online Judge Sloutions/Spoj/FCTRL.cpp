#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int h=5,count=0;
		while(h<=n)
		h*=5;
		while(h>=5)
		{
		count=count+(n/h);
		h/=5;
		}
		cout<<count<<endl;
	}
	return 0;
}
