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


#define mx 500010
int T[mx], vis[mx];

int main() {
	int n, q;	
	cin >> n >> q;
	int now = 1, ans = 1;
	for (int i = 0; i < q; i ++) {
		int m;
		cin >> m;
		if (m == 1) {
			vis[now ++] = 1;
		} else if (m == 2) {
			int a;
			cin >> a;
			T[a] = 1;
		} else {
			for (; T[ans]; ans ++);
			cout << ans << endl;
		}
	}
}
