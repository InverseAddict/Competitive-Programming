#include <iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	
	int n;
	cin>>n;
	int i=1;
	int a[200]={0};
	a[199]=1;
	int b[200]={0};
	b[199]=1;
	while(i<n)
	{
		for(int j=1;j<=i;j++)
		{
			int t=0;
			for(int k=199;k>=0;k--)
			{
				
						b[k]=b[k]+a[k]+t;
						t=0;
						if(b[k]>9)
						{
							t=1;
							b[k]=b[k]%10;
							
						}
			}
			
		}
		
		for(int k=0;k<200;k++)
			a[k]=b[k];
			i++;
	}
	for(i=0;i<200;i++)
	{
		if(a[i]!=0)
		break;
	}
	for(int k=i;k<200;k++)
	cout<<a[k];
	cout<<endl;
}
	return 0;
}

