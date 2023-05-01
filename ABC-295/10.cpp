using namespace std;
using namespace atcoder;
 
using ll = long long;
const int inf = 1e9 + 7;
const ll infll = 1e18;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
 
template <typename T>
istream &operator>>(istream &is, vector<T> &x) {
    for (int i = 0; i < x.size(); ++i) {
        is >> x[i];
    }
    return is;
}
 
int32_t main() {
#ifdef LOCAL
    freopen("/tmp/input.txt", "r", stdin);
#else
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n, m;
    cin >> n >> m;
    scc_graph g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v);
    }
    auto ans = g.scc();
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i.size() << " ";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
