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

#define mx 222222

LL L;
int N , M;
LL v[2][mx] , l[2][mx];

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>L>>N>>M;
	for(int i = 0 ; i < N ; i++ ){
		cin>>v[0][i]>>l[0][i];
	}
	for(int i = 0 ; i < M ; i++ ){
		cin>>v[1][i]>>l[1][i];
	}
	int F = 0 , S = 0;
	LL ans = 0;
	while(F < N && S < M){
		LL cur = min(l[0][F] , l[1][S]);
		if(v[0][F] == v[1][S]){
			ans += cur;
//			l[0][F] -= cur , l[1][S] -= cur;
		}
		if(l[0][F] < l[1][S]){
			F++ , l[1][S] -= cur;
		}else if(l[0][F] > l[1][S]){
			S++, l[0][F] -= cur;
		}else{
			F++ , S++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

