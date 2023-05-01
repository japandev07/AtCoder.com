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

int tc;
LL N;

bool ok(LL a , LL N){
	while(N){
		if(N%a == 0) N /= a;
		else if(N%a != 1) return 0;
		else N /= a;
	}
	return 1;
}

LL ans = 0;

LL can(LL mid , LL a){
	LL val = 0 , c = 1LL;
	for(int i = 0 ; i < 5 ; i++ ) {
		if(bit(i) & a) val += c;
		c *= mid;
	}
	return val;
}

bool solve(LL a){
	LL lo = 0 , hi = 1e9;
	while(lo + 1 < hi){
		LL mid = (lo + hi) /2;
		if(can(mid , a) < N) lo = mid;
		else hi = mid; 
	}
	ans = hi;
	if(hi == N) return 1;
	return 0;
}

int main(){
	cin>>tc;
	while(tc--){
		cin>>N;
		set<int>s;s.clear();
		for(int i = 2 ; i <= 100000 ; i++ ) if(ok(i , N)) s.insert(i);
		for(int i = 1 ; i <= 31 ; i++ ){
			if(solve(i)) s.insert(ans);
		} 
		cout<<s.size()<<endl;
	}
	return 0;
}

