#include <bits/stdc++.h>
using namespace std;
struct unionfind{
  vector<int> p;
  unionfind(int N): p(N, -1){
  }
  int root(int x){
    if (p[x] == -1){
      return x;
    } else {
      p[x] = root(p[x]);
      return p[x];
    }
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  void unite(int x, int y){
    x = root(x);
    y = root(y);
    p[x] = y;
  }
};
int main(){
	freopen("sam.txt" , "r" , stdin);
  int N;
  cin >> N;
  vector<int> p(N);
  for (int i = 1; i < N; i++){
    cin >> p[i];
    p[i]--;
  }
  unionfind UF(N);
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++){
    int t;
    cin >> t;
    if (t == 1){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      while (!UF.same(u, v)){
        u = UF.root(u);
        UF.unite(u, p[u]);
      }
    }
    if (t == 2){
      int x;
      cin >> x;
      x--;
      cout << UF.root(x) + 1 << endl;
    }
  }
}
