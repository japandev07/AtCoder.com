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

int dr[] = {0 , 1 };
int dc[] = {1 , 0 };

int H , W;
int a[11][11];
unordered_map<int, int> mp;

bool inner(int r , int c){
	return 0 <= r && 0 <= c && r < H && c < W;
}
int ans = 0;

void dfs(int r , int c , unordered_map<int, int> mp){
	mp[a[r][c]]++;
	if(r == H-1 && c == W-1) {
		ans++;
		return;
	}
	for(int i = 0 ; i < 2 ; i++ ){
		int rr = r + dr[i] , cc = c + dc[i];
		if(!inner(rr , cc)) continue;
		if(mp.count(a[rr][cc])) continue;
		dfs(rr , cc , mp);
//		s.erase(s.find(a[rr][cc]));
	}
}

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>H>>W;
	for(int i = 0 ; i < H ; i++ ){
		for(int j = 0 ; j < W ; j++ ){
			cin>>a[i][j];
		}
	}
	dfs(0 , 0 , mp);
	cout<<ans<<endl;
	return 0;
}

