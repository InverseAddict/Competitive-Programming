#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll calc(ll a,ll b)
{
	ll x=a-b;
	ll k = x/5 +(x%5)/2 + (x%5)%2 ;
	return k;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		ll ans[n][6];
		
		ans[0][0]=0;
		ans[0][1]=1;
		ans[0][2]=1;
		ans[0][3]=ans[0][4]=2;
		ans[0][5]=1;
		
		for(ll i=1;i<n;i++)
		{
			for(ll j=0;j<6;j++)
			{
				ans[i][j]=calc(a[i],a[0]-j);
			}
		}
		for(ll i=0;i<6;i++)
		{
			for(ll j=1;j<n;j++)
			{
				ans[j][i]+=ans[j-1][i];
			}
		}
		ll final=1e18;
		for(ll i=0;i<6;i++)
		{
			final=min(final,ans[n-1][i]);
		}
		cout<<final<<endl;
	}
	return 0;
}
