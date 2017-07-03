#include<iostream>
#include<algorithm>
using namespace std;
long long int power(long long int x,long long int y, long long int p)
{
   long long int res = 1;    
 
    x = x % p;  
 
    while (y > 0)
    {
        
        if (y & 1)
            res = (res*x) % p;
 
       
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
int main()
{
 
	while(1){
	
	 long long int n,k;
	 cin>>n>>k;
	 if(n==0 && k==0)
	 break;
	 long long int p=power(n,k,10000007);
	  long long int q=power(n,n,10000007);
	   long long int r=power(n-1,k,10000007);
	    long long int s=power(n-1,n-1,10000007);
	   
	    cout<<((p+q+2*r+2*s)%10000007)<<endl;
	}    return 0;
} 
