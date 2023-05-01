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
int n , m;
int id[mx];
int a[mx] , b[mx] , c[mx];

int cmp(int i , int j){
	return c[i] < c[j];
}


int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++ ){
		cin>>c[i];
		id[i] = i;
	}
	for(int i= 0 ; i < m ; i++ ) cin>>c[i+n] , id[i+n] = i+n;
	sort(id , id + n + m , cmp);
	for(int i= 0 ; i < n+m ; i++ ) a[id[i]] = i;
	for(int i = 0 ; i < n ; i ++ ) cout<<a[i]+1<<" \n"[i == n-1];
	for(int i = 0 ; i < m ; i++ ) cout<<a[i+n]+1<<" \n"[i == m-1];
	return 0;
}

