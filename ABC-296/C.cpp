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

int n , x;
int a[222222];
set< int > s;

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>n>>x;
	for(int i = 0 ; i < n ; i++ ){
		cin>>a[i];
		s.insert(a[i]);
	}
	int ok = 0;
	for(int i = 0 ; i < n ; i++ ){
		if(s.find(a[i] + x) != s.end()){
			ok = 1;
			break;
		}
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}

