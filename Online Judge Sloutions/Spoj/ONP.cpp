#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		 string s;
		 stack<char> p;
		 cin>>s;
		 int i=0;
		 while(s[i]!=NULL)
		 {
		 	if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')
		 	p.push(s[i]);
		 	else if(s[i]==')')
		 	{
		 		while(p.top()!='(')
		 		{
		 			cout<<p.top();
		 			p.pop();
		 		}
		 		p.pop();
		 	}
		 	else
		 	cout<<s[i];
		 	i++; 
		 }
		 cout<<endl;
	}
	return 0;
}
