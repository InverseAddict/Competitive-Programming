#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//#define MOD 1000000007
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll MOD=1e9+7;
	ll n;
	cin>>n;
	
	char ch;
	string s;
	
	vector<string> vu;
	vector<string> vb;
	
	
	
	for(ll i=0;i<n;i++)
	{
		cin>>ch>>s;
		if(ch=='+') vu.push_back(s);
		else vb.push_back(s);
	}
	
	if(vb.size()==0)
	{
		cout<<0<<endl;
		return 0;
	}
	if(vu.size()==0)
	{
		set<char> rt;
		for(ll i=0;i<vb.size();i++)
		{
			string x=vb[i];
			rt.insert(x[0]);
		}
		cout<<rt.size()<<endl;
		set<char>::iterator at;
		for(at=rt.begin();at!=rt.end();at++) cout<<*at<<endl;
		return 0;
	}
	
	sort(vu.begin(),vu.end());
	sort(vb.begin(),vb.end());
	
	
	
	map<ll,set<ll> > m;
	
	ll p1=vu.size();
	
	for(ll i=0;i<p1;i++)
	{
		string x=vu[i];
		ll p=x.size();
		ll y=0;
		for(ll j=0;j<p;j++)
		{
			ll qwer=pow((x[j]-'a'+8-1),j+4+1+1+1);
			y+=qwer;
			m[j].insert(y);
			//cout<<j<<" "<<m[j].size()<<endl;
		}
	}
	
	ll p2=vb.size();
	map<ll,ll> ans;   // this stores upto which index that string i need in final answer 
	for(ll i=0;i<p2;i++)
	{
		string y=vb[i];
		ll p=y.size();
		ll x=0;
		bool flag=false;
		for(ll j=0;j<p;j++)
		{
			ll qwer=pow((y[j]-'a'+8-1),j+4+1+1+1);
			x+=qwer;
			if(m[j].find(x)==m[j].end() || m[j].size()==0) 
			{
				ans[i]=j;
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			cout<<-1<<endl;
			return 0;
		}
		//cout<<y<<" "<<ans[i]<<" ";
	}
	//cout<<endl;
	// cout<<p2<<endl;
	/*for(ll i=0;i<p2;i++)   /// Prlling all the optimized blocked sites before comparing them with all other blocled sites
	{
		string x=vb[i];
		for(ll j=0;j<=ans[i];j++)
		{
			cout<<x[j];
		}
		cout<<endl;
	}*/
	
	
	map<ll,set<ll> > ansfinal; 
	ll ret[p2]={0};                    // if in the end ret[i]=1 that means that is the final anwer after compaaring
	for(ll i=p2-1;i>=0;i--)
	{
		string x=vb[i];
		ll p=0;
		for(ll j=0;j<=ans[i];j++)
		{
			ll qwer=pow((x[j]-'a'+8-1),j+4+1+1+1);
			
			p+=qwer;
		}
		if(ansfinal[ans[i]].find(p)==ansfinal[ans[i]].end() || ansfinal[ans[i]].size()==0) 
		{
			ret[i]=1;
			p=0;
			for(ll j=0;j<=ans[i];j++)
			{ 
				ll qwer=pow((x[j]-'a'+7),j+4+1+1+1);
				p+=qwer;
				ansfinal[j].insert(p);
			}
		}
		
	}
	ll k=0;
	for(ll i=0;i<p2;i++) 
	{
		if(ret[i]) k++;
	}
	//cout<<k<<endl;
	set<string> an;
	for(ll i=0;i<p2;i++)
	{
		string h=vb[i];
		if(ret[i])
		{
			string p;
			for(ll j=0;j<=ans[i];j++)
			{
				p+=h[j];
			}
			an.insert(p);
		}
	}
	
	
	
	cout<<an.size()<<endl;
	set<string>::iterator it;
	for(it=an.begin();it!=an.end();it++) cout<<*it<<endl;
	return 0;
}

