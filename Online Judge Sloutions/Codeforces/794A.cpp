#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll a,b,c;
	cin>>a>>b>>c;
	ll n;
	cin>>n;
	map<ll,ll> m;
	ll aa;
	for(ll i=0;i<n;i++)
	{
		cin>>aa;
		m[aa]++;
	}
	
	map<ll,ll>::iterator it;
	ll ans=0;
	
	for(it=m.begin();it!=m.end();it++)
	{
		if(it->first>b && it->first<c) ans+=it->second;
	}
	cout<<ans<<endl;
	return 0;
}
