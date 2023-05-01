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

#define mx 222222

int n ;
LL L , R;
LL a[mx];

LL calc(LL val){
	val %= (L + R);
	if(val < L) return 0;
	else return val / L;
}

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>n>>L>>R;
	LL val = 0;
	for(int i = 0 ; i < n ; i++ ){
		cin>>a[i];
		val ^= calc(a[i]);
	}
	if(val) puts("First");
	else puts("Second");
	return 0;
}

