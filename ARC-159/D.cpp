#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long 
#define vi vector < int > 
#define sz(a) ((int) (a).size())
#define ll long long 
#define ull unsigned long long
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 1 << 20, V = 1e9;
int n, l[N], r[N];

const int M = N * 20;

int ch[M][2], mx[M], tot;
int rt1, rt2;
inline void add(int &x, int L, int R, int p, int w) {
	if(!x) x = ++tot, mx[x] = -1e9;
	mx[x] = max(mx[x], w);
	if(L == R) return;
	int mid = (L + R) >> 1;
	p <= mid ? add(ch[x][0], L, mid, p, w) : add(ch[x][1], mid + 1, R, p, w); 
}

inline int query(int x, int L, int R, int l, int r) {
	if(!x) return -1e9;
	if(l <= L && R <= r) return mx[x];
	int mid = (L + R) >> 1, ret = -1e9;
	if(l <= mid) ret = max(ret, query(ch[x][0], L, mid, l, r));
	if(r > mid) ret = max(ret, query(ch[x][1], mid + 1, R, l, r));
	return ret;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		cin >> l[i] >> r[i];
		int mx = r[i] - l[i] + 1;
		mx = max(mx, query(rt1, 0, V, 0, l[i] - 1) + r[i] - l[i] + 1);
		mx = max(mx, query(rt2, 0, V, l[i], r[i]) + r[i]);
		
		add(rt1, 0, V, r[i], mx);
		add(rt2, 0, V, r[i], mx - r[i]);
//		cout << r[i] << " : " << mx << '\n';
	}
	cout << ::mx[rt1] << '\n';
	return 0;
}

