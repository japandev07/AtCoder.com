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

int n;
string s;

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>n>>s;
	int good = 0 , bad = 0;
	for(int i = 0 ; i < n ; i++ ){
		if(s[i] == 'o') good++;
		if(s[i] == 'x') bad++;
	}
	if(good && !bad) puts("Yes");
	else puts("No");
	return 0;
}

