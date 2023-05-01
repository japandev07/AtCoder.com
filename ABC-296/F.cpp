#include<iostream>
#include<vector>
#include<algorithm>
#include<atcoder/fenwicktree>
using namespace std;
int N;
int g(vector<int>A)
{
	atcoder::fenwick_tree<int>BIT(N);
	int ans=0;
	for(int a:A)
	{
		a--;
		ans^=BIT.sum(a,N);
		BIT.add(a,1);
	}
	return ans%2;
}
int main()
{
	cin>>N;
	vector<int>A(N),B(N);
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<N;i++)cin>>B[i];
	{
		vector<int>c=A,d=B;
		sort(c.begin(),c.end());
		sort(d.begin(),d.end());
		if(c!=d)
		{
			cout<<"No"<<endl;
			return 0;
		}
		bool fn=false;
		for(int i=1;i<N;i++)if(c[i-1]==c[i])fn=true;
		if(fn)
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	if(g(A)+g(B)&1)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}
