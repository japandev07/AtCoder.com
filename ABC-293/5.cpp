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

LL A , M , X;

LL modexp(LL a , LL n , LL mod){
	LL ret = 1;
	while(n){
		if(n & 1) ret = a * ret % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}


int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>A>>X>>M;
	LL xx = (LL) sqrt(X)+1 , cur = 0;
	for(int i = 0 ; i < xx ; i++ ){
		cur += modexp(A , i , M);
		cur %= M;
	}
	LL ans = 0;
	for(LL i = 0 ; i < X-xx ; i += xx){
		ans += cur * modexp(A , i , M) % M;
		ans %= M;
	}
	LL y = X / xx * xx;
	for(LL i = y ; i < X ; i++ ){
		ans += modexp(A , i , M);
		ans %= M;
	}
	cout<<ans<<endl;
	return 0;
}

