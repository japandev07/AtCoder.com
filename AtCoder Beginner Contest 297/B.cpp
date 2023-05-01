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

vector< int > v[2];

int main(){
//	freopen("sam.txt" , "r" , stdin);
	char s[8];
	cin>>s;
	int k = 0;
	for(int i=  0 ;i < 8 ; i++ ){
		if(s[i] == 'B') v[0].push_back(i);
		else if(s[i] == 'R') v[1].push_back(i);
		else if(s[i] == 'K') k = i;
	}
	int ok = 1;
	if((v[0][1] + v[0][0]) % 2 == 0) ok = 0;
	if(k < v[1][0] || k > v[1][1]) ok = 0;
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}

