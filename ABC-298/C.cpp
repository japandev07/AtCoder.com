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
string s;

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>n>>s;
	int cur = 0 , ans = -1;
	for(int i = 0 ; i < n ; i++ ){
		if(s[i] == 'o'){
			cur++;
		}else{
			cur = 0;
		}
		ans = max(ans , cur);
	}
	if(ans == n || ans <= 0) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}

