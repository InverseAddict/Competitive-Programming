#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		map<string,int> m;
		string s;
		int n;
		for(int i=0;i<4;i++)
		{
			cin>>s>>n;
			m[s]=n;
		}
		if(m["RealMadrid"]<m["Malaga"] && m["Barcelona"]>m["Eibar"])
		cout<<"Barcelona\n";
		else 
		cout<<"RealMadrid\n";
	}
	return 0;
}
