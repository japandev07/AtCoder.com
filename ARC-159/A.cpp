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

#define oo 1e9

#define Error(x) cerr<<#x<<" = "<<x<<endl;

#define mx 222

int n , K , Q;
int a[mx][mx] , dist[mx][mx];
vector< int > con[mx];

void dijkstra(int st){
	priority_queue< int , vector< int > , greater< int > > que;
	while(!que.empty()) que.pop();
	for(int i = 0 ; i < n ; i++ ) dist[st][i] = oo;
	dist[st][st] = 0;
	que.push(st);
	while(!que.empty()){
		int u = que.top() ; que.pop();
		for(int i = 0 ; i < con[u].size() ; i ++ ){
			int v = con[u][i];
			if(dist[st][v] >= dist[st][u] + 1){
				dist[st][v] = dist[st][u] + 1;
				que.push(v);
			}
		}
	}
}

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>n>>K;
	for(int i = 0 ; i < n ; i++ ){
		for(int j = 0 ; j < n ; j++ ){
			cin>>a[i][j];
			if(a[i][j]) con[i].push_back(j);
		}
	}
	for(int i = 0 ; i < n ; i++ ) dijkstra(i);
	cin>>Q;
	while(Q--){
		LL st , en;
		cin>>st>>en;st-- , en--;
		int s = st % n , e = en % n;
		if(s == e){
			int ans = oo;
//			Error(s)
			for(int i= 0 ; i < n ; i++ ) if(i != s){
				ans = min(ans , dist[s][i] + dist[i][s]);
			}
			if(st != en && a[s][e]) ans = 1;
			else if(st == en) ans = 0; 
			if(ans == oo) cout<<"-1\n";
			else cout<<ans<<endl;
		}else{
			if(dist[s][e] == oo) cout<<"-1\n";
			else cout<<dist[s][e]<<endl;
		}
	}
	return 0;
}

