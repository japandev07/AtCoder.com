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

int n;
vector< int >v;

int main(){
	cin>>n;
	for(int i = 0 ; i < n ; i++ ){
		int x;
		cin>>x;
		if(x % 2 == 0) v.push_back(x);
	}
	for(int i = 0 ; i < v.size() ; i++ ) cout<<v[i]<<" \n"[i == v.size() - 1];
	return 0;
}

