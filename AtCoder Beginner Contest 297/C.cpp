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

int W , H;
char s[222][222];

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>H>>W;
	for(int i= 0 ; i < H ; i++ ) cin>>s[i];
	int ok = 0;
	for(int i = 0 ; i < H ; i++ ){
		int flg = 0;
		int cur = 0;
		for(int j = 0 ; j < W ; j++ ){
			if(s[i][j] == 'T'){
				if(flg){
					s[i][j] = (j - cur) & 1 ? 'C' : 'P';
				}else{
					s[i][j] = 'P';
					flg = 1;
					cur = j;
				}
			}else{
				flg = 0;
			}
		}
	}
	for(int i = 0 ; i < H ; i++ ){
		for(int j = 0 ; j < W ; j++ ) {
			if(s[i][j] == 'P'){
				if(j+1 < W && s[i][j+1] == 'C') continue;
				else s[i][j] = 'T';
			}
		}
	}
	for(int i = 0 ; i < H ; i++ ) cout<<s[i]<<endl;
	return 0;
}

