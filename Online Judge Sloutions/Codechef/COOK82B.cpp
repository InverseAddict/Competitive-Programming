#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<ll,ll> m;
#define MOD 1000000007
void primeFactors(ll n)
{
    while (n%2 == 0)
    {
        m[2]++;
        n = n/2;
    }
    for (ll i = 3; i*i <= n; i = i+2)
    {
        while (n%i == 0)
        {
            m[i]++;
            n = n/i;
        }
    }
    if (n > 2)
        m[n]++;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
int main()
{
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++) cin>>a[i];
	bool ty=true;
	for(ll i=1;i<n;i++)
	{
		if(a[i]!=a[i-1]) ty=false;
	}
	if(ty) {
	cout<<"justdoit\n";
	return 0;} 
	for(ll i=0;i<n;i++)
	{
		primeFactors(a[i]);
	}
	map<ll,ll>::iterator it;
	bool flag=true;
	for(it=m.begin();it!=m.end();it++)
	{
		if(it->second%n!=0) flag=false;
	}
	if(flag)
	{
		cout<<"justdoit\n";
		return 0;
	}
	ll me=n+1;
	for(it=m.begin();it!=m.end();it++)
	{
		it->second=it->second%me;
	}
	
	ll ans=1;
	//cout<<power(3,5,2)<<endl;
	for(it=m.begin();it!=m.end();it++)
	{
		ll ff=it->first;
		ll ss=it->second;
		if(ss==0) continue;
		ll p=power(ff,me-ss,MOD);
		ans=((ans%MOD)*(p%MOD))%MOD;
		
	}
	cout<<ans<<endl;
	return 0;
}

