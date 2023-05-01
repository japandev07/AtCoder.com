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

#define mx 200010

int n;
int a[222222] , indeg[mx];

vector< int > con[mx];

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>n;
	for(int i = 1 ; i <= n ; i++ ){
		cin>>a[i];
		con[i].push_back(a[i]);
		indeg[a[i]]++;
	}
	queue< int >que;
	for(int i = 1 ; i <= n ; i++ ) if(indeg[i] == 0) que.push(i);
	while(!que.empty()){
		int u = que.front();que.pop();
		for(int i = 0 ; i< con[u].size() ; i++ ){
			int v = con[u][i];
			if(--indeg[v] == 0) que.push(v);
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; i++ ) if(indeg[i] > 0) ans++;
	cout<<ans<<endl;
	return 0;
}

