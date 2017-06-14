// Time Complexity O(n+m) in all cases

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void LPS(string pattern,ll m,vector<ll>  &lps)
{
	lps[0]=0;
	ll j=0;
	ll i=1;
	while(i<m)
	{
		if(pattern[i]==pattern[j])
		{
			j++;
			lps[i]=j;
			i++;
		}
		else
		{
			if(j==0)
			lps[i++]=0;
			else
			j=lps[j-1];
		}
	}
}
void KMPsearch(string text,string pattern)
{
	ll n=text.size();
	ll m=pattern.size();
	vector<ll> lps(m);
	LPS(pattern,m,lps);
	ll i=0;
	ll j=0;
	while(i<n)
	{
		if(text[i]==pattern[j])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			cout<<"PATTERN FOUND AT "<<i-j<<endl;
			j=lps[j-1];
		}
		else if(text[i]!=pattern[j] && i<n)
		{
			if(j==0)
			i++;
			else
			j=lps[j-1];
		}
	}
}

int main()
{
	string text,pattern;
	getline(cin,text);
	getline(cin,pattern);
	KMPsearch(text,pattern);
	return 0;
}
