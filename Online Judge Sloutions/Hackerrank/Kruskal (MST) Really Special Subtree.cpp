#include<bits/stdc++.h>
using namespace std;
int v,e;
vector<pair<int,pair<int,int> > > ve;
vector<int> par;
vector<int> ranke;
vector<int > ans;
int find(int p)
{
    while(p!=par[p])
    p=par[p];
    return p;
}
void unions(int p,int q)
{
    
    if(ranke[p]>ranke[q])
    {
        par[q]=p;
    }
    else
    {
        par[p]=q;
        
        //rank[q]+=1;
    }
    if(ranke[p]==ranke[q])
    {
        ranke[q]++;
    }
}
int main()
{
    cin>>v>>e;
    ve.resize(e);
    par.resize(v);
    ranke.resize(v);
    ans.resize(e);
    for(int i=0;i<v;i++)
    {
        par[i]=i;
        ranke[i]=0;
    }
    for(int i=0;i<e;i++)
    {
        ans[i]=0;
       
        cin>>ve[i].second.first;
        cin>>ve[i].second.second;
         cin>>ve[i].first;
    }
    sort(ve.begin(),ve.end());
    for(int i=0;i<e;i++)
    {
        int p=ve[i].second.first;
        int q=ve[i].second.second;
        if(find(p)!=find(q))
        {
            unions(find(p),find(q));
            ans[i]=1;
        }
        //for(int i=;i<v;i++)
    }
    int fi=0;
    for(int i=0;i<e;i++)
    {
        if(ans[i]) fi+=ve[i].first;
    }
    cout<<fi<<endl;
    return 0;
}
