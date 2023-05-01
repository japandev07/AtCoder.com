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

#define mod 998244353
int a[600005];

LL modexp(LL a , LL n){
	LL ret = 1;
	while(n){
		if(n & 1) ret = ret * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}

int main(){
//	freopen("sam.txt" , "r" , stdin);
	int q;
	cin>>q;
	LL ans = 1 , len = 1 , cur = 0 , n = 1;
	a[0] = 1;
	while(q--){
		int d , x;
		cin>>d;
		if(d == 1){
			cin>>x;
			ans = ans * 10 + x , ans %= mod;
			len++;
			a[n++] = x;
		}else if(d == 2){
			ans -= modexp(10 , len-1) * a[cur] % mod;
			ans = (ans + mod) % mod;
			cur++;
			len--;
		}else {
			cout<<ans<<endl;
		}
	}
	return 0;
}

