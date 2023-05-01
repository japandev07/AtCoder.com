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

#define mx 300010

LL N , M;
LL K;
string s;
LL sum[2*mx];

bool can(LL mid){
	LL r = mid % N , d = mid / N;
	LL dd = (mid - 1) / N + 1;
	if(dd > M) return false;
	if(d * sum[N] > K) return false;
	LL k = K - d * sum[N];
	if(k < 0) return false;
	if(d == 0){
		for(int i = 0 ; i <= N-r ; i++ ){
			if(sum[i+r] - sum[i] <= k) {
				return true;
			}
		}
	}else{
		k += sum[N];
		for(int i = 0 ; i <= N ; i++ ){
			if(sum[N] - sum[N-i] + sum[N+r-i] <= k) {
				return true;
			}
		}
	}
	
	return false;
}

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>N>>M>>K;
	cin>>s;
	s += s;
	sum[1] += s[0] == 'x';
	for(int i = 2 ; i <= 2*N ; i++ ) sum[i] = sum[i-1] + (s[i-1] == 'x');
	LL lo = 0 , hi = 1e18;
	while(lo + 1 < hi){
		LL mid = (lo + hi) >> 1;
		if(can(mid)) lo = mid;
		else hi = mid;
	}
	if(can(hi)) lo = hi;
	cout<<lo<<endl;
	return 0;
}

