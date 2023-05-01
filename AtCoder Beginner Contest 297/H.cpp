#include <bits/stdc++.h>
#include <atcoder/convolution>
using namespace std;
const long long MOD = 998244353;
long long modpow(long long a, long long b){
	long long ans = 1;
	while (b > 0){
		if (b % 2 == 1){
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return ans;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
vector<long long> inverse(vector<long long> f){
  int N = f.size();
  vector<long long> ans(1);
  ans[0] = modinv(f[0]);
  for (int i = 1; i < N * 2; i *= 2){
    vector<long long> ans2 = ans;
    ans2.resize(i * 4);
    int N2 = min(N, i * 2);
    vector<long long> f2(i * 4, 0);
    for (int j = 0; j < N2; j++){
      f2[j] = f[j];
    }
    ans2 = atcoder::convolution(ans2, ans2);
    ans2.resize(i * 2);
    ans2 = atcoder::convolution(ans2, f2);
    ans2.resize(i * 2);
    for (int j = 0; j < i; j++){
      ans2[j] = MOD - ans2[j] + ans[j] * 2;
      ans2[j] %= MOD;
    }
    swap(ans, ans2);
  }
  ans.resize(N);
  return ans;
}
int main(){
  int N;
  cin >> N;
  vector<long long> A(N + 1, 0), B(N + 1, 0);
  B[0] = 1;
  for (int i = 1; i <= N; i++){
    for (int j = i; j <= N; j += i){
      if (i % 2 == 1){
        A[j] += i;
        B[j] += MOD - 1;
      } else {
        A[j] += MOD - i;
        B[j] += 1;
      }
      A[j] %= MOD;
      B[j] %= MOD;
    }
  }
  B = atcoder::convolution(B, B);
  B.resize(N + 1);
  B = inverse(B);
  vector<long long> C = atcoder::convolution(A, B);
  cout << C[N] << endl;
}
