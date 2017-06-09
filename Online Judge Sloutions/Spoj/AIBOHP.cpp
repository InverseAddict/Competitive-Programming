#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll lcs(string &s,string &y)
{
	ll n=s.size();
	ll a[n+1][n+1];
	for(ll i=0;i<=n;i++)
	{
		for(ll j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			a[i][j]=0;
			else if(s[i-1]==y[j-1])
			a[i][j]=a[i-1][j-1]+1;
			else
			a[i][j]=max(a[i-1][j],a[i][j-1]);
		}
	}
	return a[n][n];
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll t;
	cin>>t;
	string s,y,n;
	while(t--)
	{
		cin>>s;
		ll n=s.size();
		y.resize(n);
		reverse_copy(s.begin(),s.end(),y.begin());
		cout<<n-lcs(s,y)<<endl;
	}
	return 0;
}
