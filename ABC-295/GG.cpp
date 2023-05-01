#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define PII pair<int , int>
#define PLI pair<LL  , int>
#define PLL pair<LL , LL>
#define bit(x) (1<<x)
#define bitl(x) (1LL<<x)
#define cnti(x) (__builtin_ctz(x))
#define cntl(x) (__builtin_ctzll(x))
#define clzi(x) (__builtin_clz(x))
#define clzll(x) (__builtin_clzll(x))

#define Error(x) cerr<<#x<<" = "<<x<<endl;

#define mx 200005

int n;
int root[mx] , anc[mx];

int union_find(int u){
	return root[u] == u ? root[u] : root[u] = union_find(root[u]);
}

int connect(int u , int v){
	u = union_find(u) , v = union_find(v);
	if(u == v) return 0;
	if(u > v) swap(u , v);
	root[v] = u;
}

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>n;
	for(int i = 1 ; i < n ; i++ ){
		int u;cin>>u;
		anc[i+1] = u;
	}
	for(int i = 1 ; i <= n ; i++ ) root[i] = i;
	int q;cin>>q;
	while(q--){
		int u , v , d;cin>>d;
		if(d == 1){
			cin>>u>>v;
			if(connect(u , v) == 0) continue;
			int st = u;
			while(st != v && st != 0){
				connect(union_find(u) , anc[st]);
				st = anc[st];
			}
//			Error(root[u])Error(root[v])
		}else{
			cin>>u;
			cout<<union_find(u)<<endl;
		}
	}
	return 0;
}

