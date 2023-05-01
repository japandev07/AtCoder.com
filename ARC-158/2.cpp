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
LL ans , x[3];

void solve(){
	sort(x , x+3);
	if(x[0] == x[2]) return;
	LL stp1 = (x[2] - x[1]) / 2 , stp0 = (x[2] - x[0]) / 4;
	if(stp0 < stp1 || stp1 == 0) {
		ans += stp0;
		x[2] += 3*stp0 , x[1] += 5 * stp0 , x[0] += 7*stp0;
	}else{
		ans += stp1;
		x[2] += 3*stp1 , x[1] += 5 * stp1 , x[0] += 7*stp1;
	}
	
	solve();
}

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>tc;
	while(tc--){
		LL val = 0;
		for(int i = 0 ; i < 3 ; i++ ) cin>>x[i] , val += x[i];
		sort(x , x+3);
		if(x[0] == x[2]){
			cout<<0<<endl;
			continue;
		}
		if(val % 6 != 0) {
			cout<<-1<<endl;
			continue;
		}
		LL s1 = (x[1] - x[0]) / 2 , s2 = (x[2] - x[1]) / 2;
		LL ans = ()
		cout<<(x[2] * 2 - x[1] - x[0]) / 6<<endl;
		
	}
	return 0;
}

