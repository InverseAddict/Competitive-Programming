#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];
    ll ans[n]={0};
    ans[0]=1;
    for(ll i=1;i<n;i++)
    {
        if(a[i]>a[i-1]) ans[i]=ans[i-1]+1;
        else ans[i]=1;
    }
    /*for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;*/
    for(ll i=n-2;i>=0;i--)
    {
        if(a[i]>a[i+1]) 
        {
            if(ans[i]>ans[i+1]) continue;
            else ans[i]=ans[i+1]+1;
        }
        else if(a[i]<a[i+1])
        {
            if(ans[i]<ans[i+1]) continue;
            else ans[i]=ans[i+1]-1;
        }
    }
    /*for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;*/
    ll final=0;
    for(ll i=0;i<n;i++) final+=ans[i];
    cout<<final<<endl;
    return 0;
}
