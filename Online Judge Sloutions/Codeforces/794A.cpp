
Problem:There are many safes arranged in a line, where the i-th safe from the left is called safe i. There are n banknotes left in all the safes in total. The i-th banknote is in safe xi. Oleg is now at safe a. There are two security guards, one of which guards the safe b such that b < a, i.e. the first guard is to the left of Oleg. The other guard guards the safe c so that c > a, i.e. he is to the right of Oleg.The two guards are very lazy, so they do not move. In every second, Oleg can either take all the banknotes from the current safe or move to any of the neighboring safes. However, he cannot visit any safe that is guarded by security guards at any time, becaues he might be charged for stealing. Determine the maximum amount of banknotes Oleg can gather.

Solution Approach: We store the occurence of each element in a map.Then we traverse the map and if the key value of map i.e. the position at which notes are stored is between the position of security guards we increment the answer.
	
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
