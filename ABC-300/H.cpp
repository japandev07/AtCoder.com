#include <iostream>
#include <vector>
using namespace std;

#include "atcoder/convolution.hpp"
#include "atcoder/modint.hpp"
using mint = atcoder::modint998244353;

int main() {
  long long K, N;
  cin >> K >> N;
  vector<mint> Q(K + 1, -1);
  Q[0] = 1;
  vector<mint> P = atcoder::convolution(Q, vector<mint>(K, 1));
  P.resize(K);
  for (; N; N >>= 1) {
    vector<mint> Q2{Q};
    for (int i = 1; i <= K; i += 2) Q2[i] = -Q2[i];
    P = atcoder::convolution(P, Q2);
    Q = atcoder::convolution(Q, Q2);
    vector<mint> S(K), T(K + 1);
    for (int i = 0; i < K; i++) S[i] = P[i * 2] + (N % 2 ? P[i * 2 + 1] : 0);
    for (int i = 0; i < K + 1; i++) T[i] = Q[i * 2];
    P = S, Q = T;
  }
  cout << (P[0] * (Q[0].inv())).val() << "\n";
}

