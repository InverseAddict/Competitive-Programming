//Time Complexity O(nlogn)

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll merge(vector<ll> &v,vector<ll> &temp,ll left,ll mid,ll right)
{
	ll i=left;
	ll j=mid+1;
	ll k=left; // for temp array
	ll inv_count=0;
	while(i<=mid && j<=right)
	{
		if(v[i]<=v[j])
		{
			temp[k++]=v[i++];
		}
		else
		{
			temp[k++]=v[j++];
			inv_count+=mid-i+1;
		}
		
	}
	while(i<=mid)
	temp[k++]=v[i++];
	while(j<=right)
	temp[k++]=v[j++];
	for(ll p=left;p<=right;p++)
	v[p]=temp[p];
	return inv_count;
}

ll mergesort(vector<ll> &v, vector<ll> &temp,ll left,ll right)
{
	ll inv_count=0,mid;
	if(left<right)
	{
		mid=(left+right)/2;
		inv_count+=mergesort(v,temp,left,mid);
		inv_count+=mergesort(v,temp,mid+1,right);
		inv_count+=merge(v,temp,left,mid,right); 
		
	}
	return inv_count;
}

ll count (vector<ll> &v, ll n)
{
	vector<ll> temp(n);
	return mergesort(v,temp,0,n-1);
}


int main()
{
    ll t;
    cin>>t;
    while(t--){
	ll n;
	cin>>n;
	vector<ll> v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
        cout<<count(v,n)<<endl;}
	//for(ll i=0;i<n;i++)
//	{
	//	cout<<v[i]<<" ";
	//}
	return 0;
}
