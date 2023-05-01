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

map<int, int> H;

int main() {
//	freopen("sam.txt" , "r" , stdin);
	int n;	
	cin >> n;
	for (int i = 0; i < n; i ++) {
		int x;	cin >> x;
		H[x] ++;
	}
	int ans = 0;
	for (auto it : H) {
		ans += it.second / 2;
	}
	cout << ans << endl;
}
