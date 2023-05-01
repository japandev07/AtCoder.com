#include<bits/stdc++.h>

using namespace std;

long long f(long long x,long long n,vector<long long> &rw){
  long long res=(x/n)*rw[n];
  long long rem=x%n;
  res+=rw[rem];
  return res;
}

int main(){
  long long n,m,k;
  string s;
  cin >> n >> m >> k >> s;
  
  vector<long long> rw(n+1,0);
  for(long long i=0;i<n;i++){
    rw[i+1]=rw[i];
    if(s[i]=='x'){rw[i+1]++;}
  }

  long long res=0;
  for(long long i=1;i<=n;i++){
    long long fbeg=f(i-1,n,rw);
    long long l=i,r=n*m;
    while(l<=r){
      long long te=(l+r)/2;
      if(f(te,n,rw)-fbeg<=k){l=te+1;}
      else{r=te-1;}
    }
    res=max(r-i+1,res);
  }
  cout << res << "\n";
  return 0;
}

