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

#define mx 1000001

LL n;
int p[mx];
int dp[mx];
vector< int > prime;

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>n;
	int m = (int) sqrt(n);
	for(int i = 0 ; i < mx ; i++ ) p[i] = i;
	for(int i = 2 , u = sqrt(mx) ; i <= u ; i++ ) if(p[i] == i){
		for(int j = i*i ; j < mx ; j += i ) p[j] = i;
	}
	for(int i= 2 ; i < mx ; i++ ) if(p[i] == i) prime.push_back(i);
	int ans = 0;
	for(int i = 0 ; prime[i] < 10000 ; i++ ){
		for(int j = 0 ; j < i ; j++ ){
			LL val = n / prime[i] / prime[j] / prime[j];
			if(val > 1LL* prime[i] * prime[i]){
				for(int k = i+1 ; 1LL * prime[k] * prime[k] <= val ; k++) ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

