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

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>n;
	int lo = 1 , hi = n;
	while(lo + 1 < hi){
		int mid = (lo + hi) >> 1;
		cout<<"? "<<mid<<endl;
		int d;
		cin>>d;
		if(d == 1) hi = mid;
		else lo = mid;
	}
	cout<<"! "<<lo<<endl;
	return 0;
}

