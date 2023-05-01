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

#define oo 1000000000000000000LL

LL N , M;

bool is_prime(LL M){
	for(LL i = 2 , u = sqrt(M) ; i <= u ; i++ ) if(M % i == 0) return 1;
	return 0;
}

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>N>>M;
	LL m = sqrt(M);
	LL ans = oo;
	for(LL i = 1 ; i <= min(2000000LL , N) ; i++ ){
		LL val = ((M - 1) / i + 1 ) * i;
		if((val / i) <= N) ans = min(val , ans);
	}
	if(ans < M || ans == oo) cout<<"-1"<<endl;
	else cout<<ans<<endl;
	return 0;
}

