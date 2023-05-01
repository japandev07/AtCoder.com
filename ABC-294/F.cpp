#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  long long N, M, K;
  cin >> N >> M >> K;
  vector<long long> A(N), B(N), C(M), D(M);
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
  for (int i = 0; i < M; i++) cin >> C[i] >> D[i];
  double ng = 0, ok = 1;
  for (int iter = 0; iter < 100; iter++) {
    double x = (ng + ok) / 2;
    double z = x / (1 - x);
    vector<double> v(M);
    for (int i = 0; i < M; i++) v[i] = C[i] - D[i] * z;
    sort(begin(v), end(v));
    long long num = 0;
    for (int i = 0; i < N; i++) {
      double w = A[i] - B[i] * z;
      num += M - (lower_bound(begin(v), end(v), -w) - begin(v));
    }
    (num < K ? ok : ng) = x;
  }
  cout << fixed << setprecision(16) << ok * 100 << "\n";
}
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N, M, K;
  cin >> N >> M >> K;
  vector<long long> A(N), B(N), C(M), D(M);
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
  for (int i = 0; i < M; i++) cin >> C[i] >> D[i];
  double ng = 0, ok = 1;
  for (int iter = 0; iter < 100; iter++) {
    double x = (ng + ok) / 2;
    double z = x / (1 - x);
    vector<double> v(M);
    for (int i = 0; i < M; i++) v[i] = C[i] - D[i] * z;
    sort(begin(v), end(v));
    long long num = 0;
    for (int i = 0; i < N; i++) {
      double w = A[i] - B[i] * z;
      num += M - (lower_bound(begin(v), end(v), -w) - begin(v));
    }
    (num < K ? ok : ng) = x;
  }
  cout << fixed << setprecision(16) << ok * 100 << "\n";
}
posted: about 13 hours ago
last update: about 13 hours ago
