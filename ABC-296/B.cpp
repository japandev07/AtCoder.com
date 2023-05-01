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

char s[10][10];

int main(){
//	freopen("sam.txt" , "r" , stdin);
	for(int i = 0 ; i < 8 ; i++ ) cin>>s[i];
	for(int i = 0 ; i < 8 ; i++ ){
		for(int j = 0 ; j < 8 ; j++ ) if(s[i][j] == '*'){
			cout<<(char) ('a'+j) <<8-i<<endl;
		}
	}
	return 0;
}

