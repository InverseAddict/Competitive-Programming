// Complexity O(n*(m-n+1))


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void search(string text,string pattern)
{
	ll m=text.size();
	ll n=pattern.size();
	for(ll i=0;i<=m-n;i++)
	{
		ll j;
		for( j=0;j<n;j++)
		{
			if(text[i+j]!=pattern[j])
			break;
		}
		if(j==n)
		cout<<"PATTERN FOUND AT "<<i<<endl;
	}
}
int main()
{
	string text,pattern;
	cin>>text>>pattern;
	search(text,pattern);
	return 0;
}

