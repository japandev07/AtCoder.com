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

#define mx 200010

int n , T;
int C[mx] , R[mx];

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>n>>T;
	for(int i = 0 ; i < n ; i++ ){
		cin>>C[i];
	}
	int col = -1 , id = -1;
	for(int i = 0 ; i < n ; i++ ) cin>>R[i];
	for(int i = 0 ; i < n ; i++ ){
		if(C[i] == T) {
			if(col <= R[i]) col = R[i] , id = i+1;
		}
	}
	if(col != -1) return cout<<id<<endl , 0;
	for(int i = 0 ; i < n ; i++ ){
		if(C[i] == C[0]){
			if(col <= R[i]) col = R[i] , id = i+1;
		}
	}
	cout<<id<<endl;
	return 0;
}

