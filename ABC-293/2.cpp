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
int a[211111];

int main(){
	cin>>n;
	for(int i = 0 ; i < n ; i++ ) cin>>a[i];
	set<int>s;
	for(int i = 0 ; i < n ; i++ ){
		if(s.find(i+1) != s.end()) continue;
		s.insert(a[i]);
	}
	vector< int > v;
	for(int i = 0 ; i < n ; i++ ) if(s.find(i+1) == s.end()){
		v.push_back(i+1);
	}
	cout<<v.size()<<endl;
	for(int i = 0 ; i < v.size() ; i++ ) cout<<v[i]<<" \n"[i == v.size()-1];
	return 0;
}

