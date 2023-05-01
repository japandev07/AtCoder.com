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

#define mx 22

int n , k;
LL a[mx];

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++ ) cin>>a[i];
	sort(a , a+n);
	n = unique(a , a + n) - a;
	set< LL > s;
	for(int i = 0 ; i < k ; i++ ){
		LL val = *s.begin();
		s.erase(val);
		for(int i = 0 ; i < n ; i++ ){
			s.insert(val + a[i]);
		}
	}
	cout<<*s.begin()<<endl;
	
}

