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

#define oo 1e18

#define Error(x) cerr<<#x<<" = "<<x<<endl;


#define mx 100005
LL prm[mx];
int pn;

void init(LL n) {
	pn = 0;
	for (int i = 2; 1LL * i * i <= n; i ++) {
		if (n % i == 0) {
			prm[pn ++] = i;
			prm[pn ++] = n / i;
		}
	}
	if (n > 1) prm[pn ++] = n;
}

int main() {
//	freopen("sam.txt" , "r" , stdin);
	LL x, y;	
	cin >> x >> y;
	if (x < y) swap(x, y);
	LL ans = 0;
	while(true) {
		LL g = __gcd(x, y);
		x /= g, y /= g;
		init(x - y);
		LL r = oo;
		for (int i = 0; i < pn; i ++) {
			r = min(r, x % prm[i]);
		}
		if (r == oo) {
			ans += min(x, y);
			break;
		}
		ans += r;
		x -= r, y -= r;
		if (x <= 0 || y <= 0) break;
	}
	cout << ans << endl;
} 
