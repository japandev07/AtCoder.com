#include<iostream>
#include<vector>
#include<map>
#include<cassert>
#include<atcoder/dsu>
using namespace std;
int N,M;
vector<int>f(vector<int>P,int Q)
{
	int mx=0;
	for(int i=0;i<M;i++)mx=max(mx,P[i]+1);
	atcoder::dsu uf(M+mx);
	for(int i=0;i<M;i++)
	{
		if(P[i]>=0&&Q>>i&1)uf.merge(i,M+P[i]);
		if(i+1<M)
		{
			if(Q>>i&1&&Q>>i+1&1)uf.merge(i,i+1);
			if(P[i]>=0&&P[i+1]>=0)
			{
				assert(P[i]==P[i+1]);
				//uf.merge(M+P[i],M+P[i+1]);
			}
		}
	}
	int st=P[M];
	vector<int>ret(M+1);
	for(int i=0;i<M;i++)ret[i]=-1;
	int sz=0;
	for(vector<int>g:uf.groups())
	{
		bool out=false;
		bool fn=false;
		for(int v:g)
		{
			if(v<M)
			{
				fn=true;
				if(!(Q>>v&1))out=true;
			}
		}
		if(out)continue;
		if(!fn)
		{
			assert(g.size()==1);
			if(st>0)return vector<int>();
			st=1;
		}
		else
		{
			for(int v:g)if(v<M)ret[v]=sz;
			sz++;
		}
	}
	ret[M]=st;
	return ret;
}
vector<vector<int> >TO;
int main()
{
	cin>>N>>M;
	map<vector<int>,int>mp;
	vector<vector<int> >Q;
	{
		vector<int>fst(M+1,-1);
		fst[M]=0;
		mp[fst]=0;
		Q.push_back(fst);
	}
	for(int i=0;i<Q.size();i++)
	{
		assert(mp[Q[i]]==i);
		TO.push_back(vector<int>(1<<M,-1));
		for(int j=0;j<1<<M;j++)
		{
			vector<int>nxt=f(Q[i],j);
			if(!nxt.empty())
			{
				if(mp.find(nxt)==mp.end())
				{
					int sz=mp.size();
					mp[nxt]=sz;
					Q.push_back(nxt);
				}
				TO.back()[j]=mp[nxt];
			}
		}
	}
	vector<int>dp(mp.size(),(int)1e9);
	vector<int>pc(1<<M);
	for(int i=0;i<1<<M;i++)pc[i]=__builtin_popcount(i);
	dp[0]=0;
	int all=0;
	for(int i=0;i<N;i++)
	{
		vector<int>nxt(mp.size(),(int)1e9);
		string s;cin>>s;
		int t=0;
		for(int j=0;j<M;j++)if(s[j]=='#')t|=1<<j,all++;
		for(int j=0;j<TO.size();j++)if(dp[j]<(int)1e9)
		{
			for(int k=0;k<1<<M;k++)if((k&t)==t&&TO[j][k]!=-1)
			{
				nxt[TO[j][k]]=min(nxt[TO[j][k]],dp[j]+pc[k]);
			}
		}
		dp=nxt;
	}
	int ans=1e9;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		int mx=0;
		for(int i=0;i<M;i++)mx=max(mx,it->first[i]+1);
		if(it->first[M]==1)
		{
			if(mx==0)
			{
				ans=min(ans,dp[it->second]);
			}
		}
		else
		{
			if(mx==1)
			{
				ans=min(ans,dp[it->second]);
			}
		}
	}
	cout<<ans-all<<endl;
}

