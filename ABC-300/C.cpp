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
string C[111];
vector< int > V;
int dr[] = {1 , -1 , -1 , 1};
int dc[] = {1 , 1 , -1 , -1};

bool inner(int i, int j){
	return 0 <= i && i < H && 0 <= j && j < W;
}

int getSize(int r , int c){
	int stp = 1;
	while(true){
		int ok = 1;
		for(int i = 0 ; i < 4 ; i++ ){
			int rr = r + dr[i] *stp , cc = c + dc[i] * stp;
			if(!inner(rr , cc)){
				ok = 0;
				break;
			}
			else{
				if(C[rr][cc] != '#'){
					ok = 0;
					break;
				}
			}
		}
		if(!ok) return stp-1;
		stp++;
	}
}

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>H>>W;
	int n = min(H , W);
	V.resize(n + 1);
	for(int i = 0 ; i < H ; i++ ) cin>>C[i];
	for(int i = 0 ; i < H ; i++ ){
		for(int j = 0 ; j < W ; j++ ) if(C[i][j] == '#'){
			int sz = getSize(i , j);
			V[sz]++;
		}
	}
	
	for(int i = 1 ; i <= n ; i++ ) {
		cout<<V[i]<<" \n"[i == n];
	}
	return 0;
}

