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

LL A , B , ans;

void solve(){
	cin>>A>>B;
	while(B){
		ans += A / B;
		LL tmp = B;
		B = A % B , A = tmp;
	}
	cout<<ans-1<<endl;
	
}

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>A>>B;
	solve();
	return 0;
}

