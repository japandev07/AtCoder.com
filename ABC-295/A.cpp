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


#define mx 55

int n , m;
char s[mx][mx];

bool inner(int x , int y){
	return 0 <= x && 0 <= y && x < n && y < m;
}

int main(){
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++ ) cin>>s[i];
	for(int i = 0 ; i < n ; i++ ){
		for(int j = 0 ; j < m ; j++ ) if(isdigit(s[i][j])){
			int val = s[i][j] - '0';
			for(int k = -val ; k <= val ; k++ ){
				for(int l = -val ; l <= val ; l++ ) if(abs(k) + abs(l) <= val){
					int x = i + k , y = j + l;
					if(inner(x , y) && s[x][y] == '#') s[x][y] = '.';
				}
			}
			s[i][j] = '.';
		}
	}
	for(int i = 0 ; i < n ; i++ ) cout<<s[i]<<endl;
	return 0;
}

