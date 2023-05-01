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

int h = 0 , w = 0;

map< int , int > H , W;

int getH(int val){
	return H.count(val) ? H[val] : H[val] = h++;
}

int getW(int val){
	return W.count(val) ? W[val] : W[val] = w++; 
}

int n;
vector< vector< int > > v;
int  r[mx] , c[mx] , x[mx];
LL a[mx] , b[mx];

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>n;
	for(int i = 0 ; i < n ; i++ ){
		cin>>r[i]>>c[i]>>x[i];
		getH(r[i]);
		getW(c[i]);
	}
	for(int i= 0 ; i < n ; i++ ){
		a[getH[r[i]]] += x[i];
		b[getW[c[i]]] += x[i];
	}
	LL mh = 0 , mw = 0;
	for(int i= 0 ; i < h ; i++ ) mh = max(mh , a[i]);
	for(int j = 0 ; j < w  ; j++ ) mw = max(mw , b[i]);
	for(int i = 0 ; i < h ; i++ ) if(mh == a[i]){
		v.push_back(i);
	}
	return 0;
}

