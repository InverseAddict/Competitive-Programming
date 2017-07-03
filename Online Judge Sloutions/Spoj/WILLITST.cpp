#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	long long int j=n;
	int flag=0;
	while(n>1)
	{
		if((n%2)!=0)
		{
			flag=1;
			
			break;
		}
		n=n/2;
	}
	if(flag || j==1)
	cout<<"NIE"<<endl;
	else
	cout<<"TAK"<<endl;
	return 0;
}
