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

char s[mx];
int cnt[mx];

int main() {
	cin >> s;
	int now = 0;
	LL ans = 0;
	cnt[0] = 1;
	for (int i = 0; s[i] ; i ++) {
		int c = s[i] - '0';
		now ^= bit(c) , ans += cnt[now];
		cnt[now] ++;
	}
	cout << ans << endl;
}
