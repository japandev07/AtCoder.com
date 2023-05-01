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

#define mx 111

int tc , n;
int a[mx][mx] , b[mx][mx] , c[mx][mx];

bool ok(int a[mx][mx] , int b[mx][mx]){
	for(int i = 0 ; i < n ; i++ ){
		for(int j = 0 ; j < n ; j++ ) if(a[i][j]) {
			if(!b[i][j]) return false;
		}
	}
	return true;
}

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>n;
	for(int i = 0 ; i < n ; i++ ){
		for(int j = 0 ; j < n ; j++ ){
			cin>>a[i][j];
		}
	}
	for(int i = 0 ; i < n ; i++ ) for(int j = 0 ; j < n ; j++ ) cin>>b[i][j];
	if(ok(a , b)) return cout<<"Yes\n" , 0;
	for(int i = 0 ; i < n ; i++ ) for(int j = 0 ; j < n ; j++ ) c[i][j] = a[n-j-1][i];
	for(int i = 0 ; i < n ; i++ ) for(int j = 0 ; j < n ; j++ ) a[i][j] = c[i][j];
	if(ok(a , b)) return cout<<"Yes\n" , 0;
	for(int i = 0 ; i < n ; i++ ) for(int j = 0 ; j < n ; j++ ) c[i][j] = a[n-j-1][i];
	for(int i = 0 ; i < n ; i++ ) for(int j = 0 ; j < n ; j++ ) a[i][j] = c[i][j];
	if(ok(a , b)) return cout<<"Yes\n" , 0;
	for(int i = 0 ; i < n ; i++ ) for(int j = 0 ; j < n ; j++ ) c[i][j] = a[n-j-1][i];
	for(int i = 0 ; i < n ; i++ ) for(int j = 0 ; j < n ; j++ ) a[i][j] = c[i][j];
	if(ok(a , b)) return cout<<"Yes\n" , 0;
	for(int i = 0 ; i < n ; i++ ) for(int j = 0 ; j < n ; j++ ) c[i][j] = a[n-j-1][i];
	for(int i = 0 ; i < n ; i++ ) for(int j = 0 ; j < n ; j++ ) a[i][j] = c[i][j];
	if(ok(a , b)) return cout<<"Yes\n" , 0;
	cout<<"No\n";
	return 0;
}

