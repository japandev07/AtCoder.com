#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m,w[N],to[N];
struct edge{
	int v,id,nxt;
}e[N<<1];
int hd[N],tot;
void Add(int u,int v,int id){e[++tot]={v,id,hd[u]},hd[u]=tot;}
int top[N],fa[N],dfn[N],sz[N],son[N],id;
void dfs(int u){
	sz[u]=1;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa[u])continue;
		to[e[i].id]=v,fa[v]=u;
		dfs(v);
		sz[u]+=sz[v];
		if(!son[u]||sz[v]>sz[son[u]])son[u]=v;
	}
}
void dfs2(int u,int tp){
	top[u]=tp,dfn[u]=++id;
	if(son[u])dfs2(son[u],tp);
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
ll c[N];
void add(int i,int x){for(;i<=n;i+=i&-i)c[i]+=x;}
ll sum(int i){ll s=0;for(;i;i&=i-1)s+=c[i];return s;}
ll sum(int l,int r){return sum(r)-sum(l-1);}
ll qry(int u,int v){
	ll s=0;
	while(top[u]!=top[v]){
		if(dfn[u]<dfn[v])swap(u,v);
		s+=sum(dfn[top[u]],dfn[u]);
		u=fa[top[u]];
	}
	if(u==v)return s;
	if(dfn[u]<dfn[v])swap(u,v);
	s+=sum(dfn[v]+1,dfn[u]);
	return s;
}
signed main(){
	scanf("%d",&n);
	for(int u,v,i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&w[i]),Add(u,v,i),Add(v,u,i);
	}
	dfs(1),dfs2(1,1);
	for(int i=1;i<n;i++)add(dfn[to[i]],w[i]);
	scanf("%d",&m);
	for(int op,x,y;m--;){
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)add(dfn[to[x]],y-w[x]),w[x]=y;
		else printf("%lld\n",qry(x,y));
	}
}
