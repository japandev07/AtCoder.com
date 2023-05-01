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

#define mx 200005
int n , q;
multiset< int > box[mx];
set< int > number[mx];

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>n>>q;
	while(q--){
		int d , i , j;
		cin>>d;
		if(d == 1){
			cin>>i>>j;
			box[j].insert(i);
			number[i].insert(j);
		}else if(d == 2){
			cin>>i;
			for(auto it : box[i]){
				cout<<it<<" ";
			}
			cout<<"\n";
		}else{
			cin>>i;
			for(auto it : number[i]){
				cout<<it<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}

