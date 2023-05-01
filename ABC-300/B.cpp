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

int H , W;
string A[33] , B[33];

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>H>>W;
	for(int i = 0 ; i < H ; i++ ) cin>>A[i];
	for(int i = 0 ; i < H ; i++ ) cin>>B[i];
	for(int i = 0 ; i < H ; i++ ){
		for(int j = 0 ; j < W ; j++ ){
			int ok = 1;
			for(int k = 0 ; k < H ; k++ ){
				for(int l = 0 ; l < W ; l++ ) if(A[k][l] != B[(k+i) % H][(l+j) %W]){
					ok = 0;
				}
			}
			if(ok) return cout<<"Yes\n" , 0;
		}
	}
	puts("No");
	return 0;
}

