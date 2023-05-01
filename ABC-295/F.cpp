#include <bits/stdc++.h>
using namespace std;
long long solve(string S, long long N){
  long long x = stoll(S);
  vector<long long> TEN(18);
  TEN[0] = 1;
  for (int i = 0; i < 17; i++){
    TEN[i + 1] = TEN[i] * 10;
  }
  int M = S.size();
  long long ans = 0;
  for (int i = 0; i <= 17 - M; i++){
    long long N2 = N;
    if (S[0] == '0'){
      N2 -= TEN[M + i];
    }
    N2 -= x * TEN[i];
    if (N2 > 0){
      long long q = N2 / TEN[M + i];
      long long r = N2 % TEN[M + i];
      ans += q * TEN[i];
      ans += min(r, TEN[i]);
    }
  }
  return ans;
}
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    string S;
    long long L, R;
    cin >> S >> L >> R;
    cout << solve(S, R + 1) - solve(S, L) << endl;
  }
}
