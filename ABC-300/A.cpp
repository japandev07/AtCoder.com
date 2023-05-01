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



int main(){
//	freopen("sam.txt" , "r" , stdin);
	int n , A , B , ans;
	cin>>n>>A>>B;
	for(int i = 0 ; i < n ; i++ ){
		int c;
		cin>>c;
		if(A + B == c) {
			ans = i;
		}
	}
	cout<<ans+1<<endl;
	return 0;
}

