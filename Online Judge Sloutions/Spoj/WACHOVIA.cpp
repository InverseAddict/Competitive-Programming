#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll W,m;
		cin>>W>>m;
		ll wt[m];
		ll val[m];
		for(ll i=0;i<m;i++)
		{
			cin>>wt[i]>>val[i];
		}
		ll a[m+1][W+1];
		
		for(ll i=0;i<=m;i++)
		{
			for(ll j=0;j<=W;j++)
			{
				if(j==0 || i==0)
				a[i][j]=0;
				else if(wt[i-1]<=j)
				{
					a[i][j]=max(val[i-1]+a[i-1][j-wt[i-1]],a[i-1][j]);
				}
				else
				a[i][j]=a[i-1][j];
			}
		}
		cout<<"Hey stupid robber, you can get "<<a[m][W]<<"."<<endl;
	}
	return 0;
} 
