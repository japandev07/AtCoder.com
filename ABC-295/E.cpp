#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  int cnt = 0;
  for (int i = 0; i < N; i++){
    if (A[i] == 0){
      cnt++;
    }
  }
  int mx = max(M, cnt);
  vector<long long> inv(mx + 1);
  inv[1] = 1;
  for (int i = 2; i <= mx; i++){
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
  }
  vector<long long> fact(cnt + 1), finv(cnt + 1);
  fact[0] = 1;
  finv[0] = 1;
  for (int i = 1; i <= cnt; i++){
    fact[i] = fact[i - 1] * i % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
  long long ans = 0;
  for (int i = 1; i <= M; i++){
    int cnt1 = 0;
    for (int j = 0; j < N; j++){
      if (A[j] >= i){
        cnt1++;
      }
    }
    long long p = (M + 1 - i) * inv[M] % MOD;
    long long q = (i - 1) * inv[M] % MOD;
    vector<long long> POWp(cnt + 1), POWq(cnt + 1);
    POWp[0] = 1;
    POWq[0] = 1;
    for (int j = 0; j < cnt; j++){
      POWp[j + 1] = POWp[j] * p % MOD;
      POWq[j + 1] = POWq[j] * q % MOD;
    }
    for (int j = 0; j <= cnt; j++){
      if (cnt1 + j >= N + 1 - K){
        ans += fact[cnt] * finv[j] % MOD * finv[cnt - j] % MOD * POWp[j] % MOD * POWq[cnt - j] % MOD;
        ans %= MOD;
      }
    }
  }
  cout << ans << endl;
}
