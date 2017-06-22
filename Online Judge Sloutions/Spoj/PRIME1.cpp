#include<iostream>
#include<algorithm>
using namespace std;
int main()
{int t;
cin>>t;
while(t--){
	int m,n;
	cin>>m>>n;
	int i,j;
	
	for(i=m;i<=n;i++){
		int count=0;
		for(j=2;j*j<=i;j++)
		{   if(count==0){
		
			if(i%j==0)
			count++;}
		}
		if(count==0 && i!=1)
		cout<<i<<endl;
	}
}
return 0;
}
	
