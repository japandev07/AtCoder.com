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

string S[] = {"and", "not", "that", "the", "you"};

int main() {
	int n;	
	cin >> n;
	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s;
		for (int j = 0; j < 5; j ++) {
			if (s == S[j]) return cout << "Yes" << endl, 0;
		}
	}
	cout << "No" << endl;
}
