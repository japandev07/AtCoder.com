#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<char>> X(N, vector<char>(M));
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      cin >> X[i][j];
    }
  }
  vector<vector<long long>> dp(2, vector<long long>(1 << M, 0));
  dp[0][0] = 1;
  for (int i = 0; i < N * M; i++){
    int x = i / M;
    int y = i % M;
    vector<vector<long long>> dp2(2, vector<long long>(1 << M, 0));
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < (1 << M); k++){
        if (X[x][y] == '0' || X[x][y] == '?'){
          if (y != M - 1){
            dp2[1][k | (1 << y)] += dp[j][k];
            dp2[1][k | (1 << y)] %= MOD;
          } else {
            dp2[0][k | (1 << y)] += dp[j][k];
            dp2[0][k | (1 << y)] %= MOD;
          }
        }
        if (X[x][y] == '1' || X[x][y] == '?'){
          if (j == 0 || (k >> y & 1) == 0){
            if (y != M - 1){
              dp2[j][k] += dp[j][k];
              dp2[j][k] %= MOD;
            } else {
              dp2[0][k] += dp[j][k];
              dp2[0][k] %= MOD;
            }
          }
        }
      }
    }
    dp = dp2;
  }
  long long ans = 0;
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < (1 << M); j++){
      ans += dp[i][j];
    }
  }
  ans %= MOD;
  cout << ans << endl;
}
